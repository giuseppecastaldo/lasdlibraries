
namespace lasd {

// Default constructor
template<typename Data>
MatrixCSR<Data>::MatrixCSR() {
    rowsPtr[0] = &Head;
}

// Specific constructors
template<typename Data>
MatrixCSR<Data>::MatrixCSR(const unsigned long r, const unsigned long c) {
    rows = r;
    columns = c;
    rowsPtr.Resize(r + 1);
    for (unsigned long i = 0; i <= rows; ++i) {
        rowsPtr[i] = &Head;
    }
}

// Copy constructor
template<typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& mat) : MatrixCSR(mat.rows, mat.columns) {
    for (unsigned long row = 0; row < rows; ++row) {
        for (Node** ptr = mat.rowsPtr[row]; ptr != mat.rowsPtr[row + 1]; ptr = &((*ptr)->NextElement)) {
            Node& nod = **ptr;
            (*this)(row, nod.Element.second) = nod.Element.first;
        }
    }
}

// Move constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& mat) noexcept {
    std::swap(size, mat.size);
    std::swap(Head, mat.Head);
    std::swap(columns, mat.columns);
    std::swap(rows, mat.rows);
    std::swap(rowsPtr, mat.rowsPtr);
    for (unsigned long i = 0; i < size && rowsPtr[i] == &mat.Head; ++i) {
        rowsPtr[i] = &Head;
    }
    for (unsigned long i = 0; i < mat.size && mat.rowsPtr[i] == &Head; ++i) {
        mat.rowsPtr[i] = &mat.Head;
    }
}

// Destructor
template <typename Data>
MatrixCSR<Data>::~MatrixCSR() {
    MatrixCSR<Data>::Clear();
}

// Copy assignment
template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& mat) {
    rows = mat.rows;
    columns = mat.columns;
    rowsPtr.Resize(rows + 1);
    
    for (unsigned long i = 0; i <= rows; ++i) {
        rowsPtr[i] = &Head;
    }
    
    for (unsigned long row = 0; row < rows; ++row) {
        for (Node** ptr = mat.rowsPtr[row]; ptr != mat.rowsPtr[row + 1]; ptr = &((*ptr)->NextElement)) {
            Node& nod = **ptr;
            (*this)(row, nod.Element.second) = nod.Element.first;
        }
    }
    
    return *this;
}

// Move assignment
template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& mat) noexcept {
    std::swap(size, mat.size);
    std::swap(Head, mat.Head);
    std::swap(columns, mat.columns);
    std::swap(rows, mat.rows);
    std::swap(rowsPtr, mat.rowsPtr);
    for (unsigned long i = 0; i < size && rowsPtr[i] == &mat.Head; ++i) {
        rowsPtr[i] = &Head;
    }
    for (unsigned long i = 0; i < mat.size && mat.rowsPtr[i] == &Head; ++i) {
        mat.rowsPtr[i] = &mat.Head;
    }
    
    return *this;
}

// Comparison operators
template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& mat) const noexcept {
    bool equal_rows = (rows == mat.rows) && (columns == mat.columns) && (List<std::pair<Data, unsigned long>>::operator==(mat));
    
    if (mat.rowsPtr.Size() == rowsPtr.Size()) {
        for (unsigned long index = 0; index < rowsPtr.Size(); ++index) {
            if (*rowsPtr[index] != nullptr && *mat.rowsPtr[index] != nullptr) {
                if ((*rowsPtr[index])->Element != (*mat.rowsPtr[index])->Element) {
                    return false;
                }
            }
        }
        return true && equal_rows;
    } else {
        return false;
    }
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& mat) const noexcept {
    return !(*this == mat);
}

// Specific member functions (inherited from Matrix)
template <typename Data>
void MatrixCSR<Data>::RowResize(const unsigned long newsize) {
    if (newsize == 0) {
        MatrixCSR<Data>::Clear();
    } else if (newsize < rows) {
        DeleteSubList(*rowsPtr[rows - (rows - newsize)]);
        rowsPtr.Resize(newsize + 1);
    } else if (newsize > rows) {
        rowsPtr.Resize(newsize + 1);
        for (unsigned long i = rows; i < newsize; ++i) {
            rowsPtr[i+1] = rowsPtr[i];
        }
    }
    
    rows = newsize;
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(const unsigned long newsize) {
    if (newsize == 0) {
        List<std::pair<Data, unsigned long>>::Clear();
    } else if (newsize < columns) {
        unsigned long idx = 1;
        Node** ptr = &Head;
        while (idx <= rows) {
            Node* nod;
            Node** ext = rowsPtr[idx];
            while (ptr != ext && (*ptr)->Element.second < newsize) {
                nod = *ptr;
                ptr = &(nod->NextElement);
            }
            
            if (ptr != ext) {
                if (ext == rowsPtr[rows]) {
                    Tail = nod;
                }
                Node* tmp = *ptr;
                *ptr = *ext;
                *ext = nullptr;
                for (Node* ptr = tmp; ptr != nullptr; ptr = ptr->NextElement) { size--; }
                delete tmp;
            }
            for (; idx <= rows && rowsPtr[idx] == ext; ++idx) {
                rowsPtr[idx] = ptr;
            }
        }
    }
    
    columns = newsize;
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(unsigned long r, unsigned long c) const noexcept {
    if ((r < rows) && (c < columns)) {
        Node** ptr = rowsPtr[r];
        while (ptr != rowsPtr[r+1]) {
            Node& nod = **ptr;
            if (nod.Element.second == c) {
                return true;
            }
            
            ptr = &(nod.NextElement);
        }
    }
    
    return false;
}

template <typename Data>
Data& MatrixCSR<Data>::operator()(const unsigned long row, const unsigned long col) {
    if ((row < rows) && (col < columns)) {
        Node** ptr = rowsPtr[row];
        Node** ext = rowsPtr[row+1];
        
        while (ptr != ext && (*ptr)->Element.second <= col) {
            Node& nod = **ptr;
            if (nod.Element.second == col) {
                return nod.Element.first;
            }
            
            ptr = &(nod.NextElement);
        }
        
        InsertInColumnAfter(col, ptr);
        
        if (ptr == ext) {
            for (unsigned long i = row + 1; i <= rows && rowsPtr[i] == ptr; i++) {
                rowsPtr[i] = &(*ptr)->NextElement;
            }
        }
        
        return (*ptr)->Element.first;
    } else {
        throw std::out_of_range("Cell does not exists.");
    }
    
    throw std::length_error("Data does not exists.");
}

template <typename Data>
const Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c) const {
    if ((r < rows) && (c < columns)) {
        Node** ptr = rowsPtr[r];
        while (ptr != rowsPtr[r+1]) {
            Node& nod = **ptr;
            if (nod.Element.second == c) {
                return nod.Element.first;
            }
            
            ptr = &(nod.NextElement);
        }
    } else {
        throw std::out_of_range("Cell does not exists.");
    }
    
    throw std::length_error("Data does not exists.");
}

// Specific member functions (inherited from Container)
template <typename Data>
void MatrixCSR<Data>::Clear() {
    List<std::pair<Data, unsigned long>>::Clear();
    rowsPtr.Resize(1);
    rowsPtr[0] = &Head;
    rows = 0;
    columns = 0;
}

// Specific member functions (inherited from MappableContainer)
template <typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    List<std::pair<Data, unsigned long>>::MapPreOrder([&fun](std::pair<Data, unsigned long>& datx, void* parx) { fun(datx.first, parx); }, par);
}

template <typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    List<std::pair<Data, unsigned long>>::MapPostOrder([&fun](std::pair<Data, unsigned long>& datx, void* parx) { fun(datx.first, parx); }, par);
}

// Specific member functions (inherited from FoldableContainer)
template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    List<std::pair<Data, unsigned long>>::FoldPreOrder([&fun](const std::pair<Data, unsigned long>& datx, const void* parx, void* accx) { fun(datx.first, parx, accx); }, par, acc);
}

template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    List<std::pair<Data, unsigned long>>::FoldPostOrder([&fun](const std::pair<Data, unsigned long>& datx, const void* parx, void* accx) { fun(datx.first, parx, accx); }, par, acc);
}


// Auxiliary member functions
template <typename Data>
void MatrixCSR<Data>::InsertInColumnAfter(unsigned long col, Node **ptr) {
    size++;
    Node* tmp = (*ptr);
    (*ptr) = new Node(); (*ptr)->Element.second = col;
    (*ptr)->NextElement = tmp;
}

template <typename Data>
void MatrixCSR<Data>::DeleteSubList(Node *&node) {
    if (!node)
        return;
    DeleteSubList(node->NextElement);
    size--;
    delete node;
    node = nullptr;
}

}

