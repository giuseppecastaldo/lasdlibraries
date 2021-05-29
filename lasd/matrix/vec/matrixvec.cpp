namespace lasd {

template<typename Data>
MatrixVec<Data>::MatrixVec() : Vector<Data>() {
    rows = 0;
    columns = 0;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const unsigned long r, const unsigned long c) : Vector<Data>(r*c) {
    rows = r;
    columns = c;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& mat) : Vector<Data>(mat) {
    rows = mat.rows;
    columns = mat.columns;
}

template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& mat) noexcept : Vector<Data>(std::move(mat)) {
    std::swap(columns, mat.columns);
    std::swap(rows, mat.rows);
}

template <typename Data>
MatrixVec<Data>::~MatrixVec() { }

template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& mat) {
    rows = mat.rows;
    columns = mat.columns;
    Vector<Data>::operator=(mat);
    return *this;
}

template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& mat) noexcept {
    std::swap(rows, mat.rows);
    std::swap(columns, mat.columns);
    Vector<Data>::operator=(std::move(mat));
    return *this;
}

template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec<Data>& mat) const noexcept {
    return Vector<Data>::operator==(mat);
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec<Data>& mat) const noexcept{
    return !(*this == mat);
}

template <typename Data>
void MatrixVec<Data>::RowResize(const unsigned long newsize) {
    if (newsize == 0) {
        Clear();
    } else {
        Vector<Data>::Resize(newsize * columns);
        rows = newsize;
    }
}

template <typename Data>
void MatrixVec<Data>::ColumnResize(const unsigned long newSize){
    if(newSize == 0) {
        Clear();
    } else if(size!=newSize) {
        size=newSize*rows;
        Data* TmpElements = new Data[size]{};
        for(unsigned long i=0;i<rows;i++) {
            for(unsigned long j=0;j<columns;j++) {
                std::swap(Elements[i*columns+j], TmpElements[i*newSize+j]);
            }
        }
        std::swap(Elements, TmpElements);
        delete[] TmpElements;
        columns=newSize;
    }
}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(unsigned long i, unsigned long j) const noexcept {
    return (i < rows && j < columns);
}

template <typename Data>
Data& MatrixVec<Data>::operator()(const unsigned long r, const unsigned long c){
    if (ExistsCell(r,c)) {
        if (&Elements[r*columns+c] != nullptr) {
            return Elements[r*columns+c];
        } else {
            throw std::length_error("non esiste valore");
        }
    } else {
        throw std::out_of_range("non esiste la cella");
    }
}

template <typename Data>
const Data& MatrixVec<Data>::operator() (const unsigned long r, const unsigned long c)const{
    if (ExistsCell(r,c)) {
        if (&Elements[r*columns+c] != nullptr) {
            return Elements[r*columns+c];
        } else {
            throw std::length_error("non esiste valore");
        }
    } else {
        throw std::out_of_range("non esiste la cella");
    }
}

template <typename Data>
void MatrixVec<Data>::Clear() {
    Vector<Data>::Clear();
    columns = 0;
    rows = 0;
}

template <typename Data>
void MatrixVec<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    Vector<Data>::MapPreOrder(fun, par);
}

template <typename Data>
void MatrixVec<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    Vector<Data>::MapPostOrder(fun, par);
}

template <typename Data>
void MatrixVec<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    Vector<Data>::FoldPreOrder(fun, par, acc);
}

template <typename Data>
void MatrixVec<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    Vector<Data>::FoldPostOrder(fun, par, acc);
}

}
