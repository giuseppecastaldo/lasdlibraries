
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
    *this = MatrixCSR(mat.rows, mat.columns);
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
    return (rows = mat.rows) && (columns = mat.columns) && (List<std::pair<Data, unsigned long>>::operator==(mat));
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& mat) const noexcept {
    return !(*this == mat);
}

// Specific member functions (inherited from Matrix)
template <typename Data>
void MatrixCSR<Data>::RowResize(const unsigned long newsize) {
//
//
//
//
//
//
//
//
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
//        std::cout << (*rowsPtr[r])->Element.first << ", " << (*rowsPtr[r])->Element.second << std::endl;
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
Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c) {
    if ((r < rows) && (c < columns)) {
        Node** ptr = rowsPtr[r];
        Node** ext = rowsPtr[r+1];

        while (ptr != ext && (*ptr)->Element.second <= c) {
            Node& nod = **ptr;
            if (nod.Element.second == c) {
                return nod.Element.first;
            }

            ptr = &(nod.NextElement);
        }
        
        size++;
        Node* tmp = (*ptr);
        (*ptr) = new Node();
        (*ptr)->Element.second = c;
        (*ptr)->NextElement = tmp;
        
        if (ptr == ext) {
            for (unsigned long i = r + 1; i <= rows; i++) {
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
    rowsPtr.Clear();
    rows = 0;
    columns = 0;
}

// Specific member functions (inherited from MappableContainer)
template <typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    List<std::pair<Data, unsigned long>>::MapPreOrder([&fun](std::pair<Data, unsigned long> datx, void* parx) { fun(datx.first, parx); }, par);
}

template <typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    List<std::pair<Data, unsigned long>>::MapPostOrder([&fun](std::pair<Data, unsigned long> datx, void* parx) { fun(datx.first, parx); }, par);
}

// Specific member functions (inherited from FoldableContainer)
template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    List<std::pair<Data, unsigned long>>::FoldPreOrder([&fun](std::pair<Data, unsigned long> datx, const void* parx, void* accx) { fun(datx.first, parx, accx); }, par, acc);
}

template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    List<std::pair<Data, unsigned long>>::FoldPostOrder([&fun](std::pair<Data, unsigned long> datx, const void* parx, void* accx) { fun(datx.first, parx, accx); }, par, acc);
}

}

