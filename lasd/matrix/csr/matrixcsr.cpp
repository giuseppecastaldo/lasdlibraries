
namespace lasd {

template<typename Data>
MatrixCSR<Data>::MatrixCSR() {
    rowsPtr[0] = Head;
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(const unsigned long r, const unsigned long c) {
    rows = r;
    columns = c;
    rowsPtr.Resize(r + 1);
    for (unsigned long i = 0; i <= rows; ++i) {
        rowsPtr[i] = Head;
    }
}

template<typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& mat) {
    
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& mat) noexcept {
    
}

template <typename Data>
MatrixCSR<Data>::~MatrixCSR() { }

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& mat) {
    return *this;
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& mat) noexcept {
    return *this;
}

template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& mat) const noexcept {
    return List<std::pair<Data, unsigned long>>::operator==(mat);
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& mat) const noexcept {
    return !(*this == mat);
}

template <typename Data>
void MatrixCSR<Data>::RowResize(const unsigned long newsize) {
    
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(const unsigned long newSize){
   
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(unsigned long i, unsigned long j) const noexcept {
    
}

template <typename Data>
Data& MatrixCSR<Data>::operator()(const unsigned long r, const unsigned long c){
    
}

template <typename Data>
const Data& MatrixCSR<Data>::operator() (const unsigned long r, const unsigned long c) const {
    
}

template <typename Data>
void MatrixCSR<Data>::Clear() {
    List<std::pair<Data, unsigned long>>::Clear();
    rowsPtr.Clear();
    rows = 0;
    columns = 0;
}

template <typename Data>
void MatrixCSR<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    List<std::pair<Data, unsigned long>>::MapPreOrder([&fun](std::pair<Data, unsigned long> datx, void* parx) { fun(datx.first, parx); }, par);
}

template <typename Data>
void MatrixCSR<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    List<std::pair<Data, unsigned long>>::MapPostOrder([&fun](std::pair<Data, unsigned long> datx, void* parx) { fun(datx.first, parx); }, par);
}

template <typename Data>
void MatrixCSR<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    List<std::pair<Data, unsigned long>>::FoldPreOrder([&fun](std::pair<Data, unsigned long> datx, const void* parx, void* accx) { fun(datx.first, parx, accx); }, par, acc);
}

template <typename Data>
void MatrixCSR<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    List<std::pair<Data, unsigned long>>::FoldPostOrder([&fun](std::pair<Data, unsigned long> datx, const void* parx, void* accx) { fun(datx.first, parx, accx); }, par, acc);
}

}

