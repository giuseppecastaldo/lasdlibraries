namespace lasd {

/* ************************************************************************** */

template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& con) : List<Data>(con) { }

template <typename Data>
StackLst<Data>::StackLst(const StackLst& s) : List<Data>(s) { }

template <typename Data>
StackLst<Data>::StackLst(StackLst&& s) noexcept : List<Data>(std::move(s)) { }

template <typename Data>
StackLst<Data>::~StackLst() { }

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& s) {
    List<Data>::operator=(s);
    return *this;
}

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& s) noexcept {
    List<Data>::operator=(std::move(s));
    return *this;
}

template <typename Data>
bool StackLst<Data>::operator==(const StackLst& s) const noexcept {
    return List<Data>::operator==(s);
}

template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& s) const noexcept {
    return List<Data>::operator!=(s);
}

template <typename Data>
void StackLst<Data>::Push(const Data& data) {
    List<Data>::InsertAtFront(data);
}

template <typename Data>
void StackLst<Data>::Push(Data&& data) noexcept {
    List<Data>::InsertAtFront(std::move(data));
}

template <typename Data>
Data& StackLst<Data>::Top() {
    return List<Data>::Front();
}

template <typename Data>
void StackLst<Data>::Pop() {
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data StackLst<Data>::TopNPop() {
    return List<Data>::FrontNRemove();
}

template <typename Data>
void StackLst<Data>::Clear() {
    List<Data>::Clear();
}

/* ************************************************************************** */

}
