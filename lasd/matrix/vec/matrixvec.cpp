
namespace lasd {

template<typename Data>
MatrixVec<Data>::MatrixVec() : Vector<Data>() {
    RowNumber_ = 0;
    ColumnNumber_ = 0;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const unsigned long r, const unsigned long c) : Vector<Data>(r*c) {
    RowNumber_ = r;
    ColumnNumber_ = c;
}

//Copy constructor
template<typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& MatrixVec) : Vector<Data>(MatrixVec) {
    RowNumber_ = MatrixVec.RowNumber_;
    ColumnNumber_ = MatrixVec.ColumnNumber_;
}

//Move constructor
template <typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& MatrixVec) noexcept : Vector<Data>(std::move(MatrixVec)) {
    std::swap(ColumnNumber_, MatrixVec.ColumnNumber_);
    std::swap(RowNumber_, MatrixVec.RowNumber_);
}

//Copy assignment
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& MatrixVec) {
    RowNumber_ = MatrixVec.RowNumber_;
    ColumnNumber_ = MatrixVec.ColumnNumber_;
    Vector<Data>::operator=(MatrixVec);
    return *this;
}

//Move assignment
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& MatrixVec) noexcept {
    std::swap(RowNumber_, MatrixVec.RowNumber_);
    std::swap(ColumnNumber_, MatrixVec.ColumnNumber_);
    Vector<Data>::operator=(std::move(MatrixVec));
    return *this;
}

//Comparison operators
template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec<Data>& MatrixVec) const noexcept {
    return Vector<Data>::operator==(MatrixVec);
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec<Data>& MatrixVec) const noexcept{
    return !(*this == MatrixVec);
}

// Specific member functions
template <typename Data>
void MatrixVec<Data>::RowResize(const unsigned long newsize) {
    Vector<Data>::Resize(newsize * ColumnNumber_);
    RowNumber_ = newsize;
}

template <typename Data>
void MatrixVec<Data>::ColumnResize(const unsigned long newSize){
    if(newSize == 0) {
        Clear();
    } else if(size!=newSize) {
        size=newSize*RowNumber_;
        Data* TmpElements = new Data[size]{};
        for(unsigned long i=0;i<RowNumber_;i++) {
            for(unsigned long j=0;j<ColumnNumber_;j++) {
                std::swap(Elements[i*ColumnNumber_+j], TmpElements[i*newSize+j]);
            }
        }
        std::swap(Elements, TmpElements);
        delete[] TmpElements;
        ColumnNumber_=newSize;
    }
}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(unsigned long i, unsigned long j)const noexcept{
    if (i < RowNumber_ && j < ColumnNumber_) {
        return true;
    }
    return false;
}

template <typename Data>
Data& MatrixVec<Data>::operator()(const unsigned long r, const unsigned long c){
    if (ExistsCell(r,c)) {
        if (&Elements[r*ColumnNumber_+c] != nullptr) {
            return Elements[r*ColumnNumber_+c];
        } else {
            throw std::length_error("non esiste valore");
        }
    } else {
        throw std::out_of_range("non esiste la cella");
    }
}

template <typename Data>
Data MatrixVec<Data>::operator() (const unsigned long r, const unsigned long c)const{
    if (ExistsCell(r,c)) {
        if (&Elements[r*ColumnNumber_+c] != nullptr) {
            return Elements[r*ColumnNumber_+c];
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
    ColumnNumber_ = 0;
    RowNumber_ = 0;
}

/* ************************************************************************** */

template <typename Data>
void MatrixVec<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    Vector<Data>::MapPreOrder(fun, par);
}

template <typename Data>
void MatrixVec<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    Vector<Data>::MapPostOrder(fun, par);
}

/* ************************************************************************** */

template <typename Data>
void MatrixVec<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    Vector<Data>::FoldPreOrder(fun, par, acc);
}

template <typename Data>
void MatrixVec<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    Vector<Data>::FoldPostOrder(fun, par, acc);
}

}
