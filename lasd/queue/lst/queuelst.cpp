
namespace lasd {

/* ************************************************************************** */

template <typename Data>
QueueLst<Data>::QueueLst(const LinearContainer<Data>& con) : List<Data>(con) { }

template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& s) : List<Data>(s) { }

template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& s) noexcept : List<Data>(std::move(s)) { }

template <typename Data>
QueueLst<Data>::~QueueLst() { }

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& s) {
    List<Data>::operator=(s);
    return *this;
}

template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& s) noexcept {
    List<Data>::operator=(std::move(s));
    return *this;
}

template <typename Data>
bool QueueLst<Data>::operator==(const QueueLst& s) const noexcept {
    return List<Data>::operator==(s);
}

template <typename Data>
bool QueueLst<Data>::operator!=(const QueueLst& s) const noexcept {
    return List<Data>::operator!=(s);
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& data) {
    List<Data>::InsertAtBack(data);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& data) noexcept {
    List<Data>::InsertAtBack(std::move(data));
}

template <typename Data>
Data& QueueLst<Data>::Head() {
    return List<Data>::Front();
}

template <typename Data>
void QueueLst<Data>::Dequeue() {
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
void QueueLst<Data>::Clear() {
    List<Data>::Clear();
}

/* ************************************************************************** */

}
