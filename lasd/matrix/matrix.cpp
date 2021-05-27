
namespace lasd {

template <typename Data>
unsigned long Matrix<Data>::RowNumber() const noexcept {
    return RowNumber_;
}

template <typename Data>
unsigned long Matrix<Data>::ColumnNumber() const noexcept {
    return ColumnNumber_;
}

}
