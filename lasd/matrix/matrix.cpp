
namespace lasd {

template <typename Data>
unsigned long Matrix<Data>::RowNumber() const noexcept {
    return rows;
}

template <typename Data>
unsigned long Matrix<Data>::ColumnNumber() const noexcept {
    return columns;
}

}
