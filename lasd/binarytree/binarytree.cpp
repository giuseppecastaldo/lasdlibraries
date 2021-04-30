
namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    return (node.element == element);
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

/* ************************************************************************** */



/* ************************************************************************** */

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree) {
    current = &(tree.Root());
    elements.Push(&(tree.Root()));
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& it) {
    
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& it) noexcept {
    
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& it) {
    
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& it) noexcept {
   
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& it) const noexcept {
    
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    current = elements.TopNPop();
    if (current->HasRightChild()) {
        elements.Push(&(current->RightChild()));
    }
    
    if (current->HasLeftChild()) {
        elements.Push(&(current->LeftChild()));
    }
    
    return current->Element();
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    return current->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

/* ************************************************************************** */

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree) {
    FindLastLeftLeaf(&(tree.Root()));
    current = elements.Top();
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& it) {
    
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& it) {
    
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& it) noexcept {
    
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& it) const noexcept {
    
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    current = elements.TopNPop();
    if (!elements.Empty()) {
        if (current == &(elements.Top()->LeftChild())) {
            FindLastLeftLeaf(&(elements.Top()->RightChild()));
        }
    }
    
    return current->Element();
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    return current->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

template <typename Data>
void BTPostOrderIterator<Data>::FindLastLeftLeaf(typename BinaryTree<Data>::Node* node) {
    while (node != nullptr) {
        elements.Push(node);
        if (node->HasLeftChild()) {
            node = &(node->LeftChild());
        } else {
            node = &(node->RightChild());
        }
    }
}

/* ************************************************************************** */

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree) {
    FindLastLeftNode(&(tree.Root()));
    current = elements.Top();
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& it) {
    
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& it) noexcept {
    
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& it) {
    
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& it) noexcept {
    
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& it) const noexcept {
    
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    current = elements.TopNPop();
    typename BinaryTree<Data>::Node* tmp = &(current->RightChild());
    
    while (tmp != nullptr) {
        elements.Push(tmp);
        tmp = &(tmp->LeftChild());
    }
    
    delete tmp;
    
    return current->Element();
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator*() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    return current->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

template <typename Data>
void BTInOrderIterator<Data>::FindLastLeftNode(typename BinaryTree<Data>::Node* node) {
    while (node != nullptr) {
        elements.Push(node);
        node = &(node->LeftChild());
    }
}

/* ************************************************************************** */

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree) {
    current = &(tree.Root());
    elements.Enqueue(&(tree.Root()));
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& it) {
    
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& it) noexcept {
    
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& it) {
    
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& it) noexcept {
    
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& it) const noexcept {
    
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    current = elements.HeadNDequeue();
    
    if (current->HasLeftChild()) { elements.Enqueue(&current->LeftChild()); }
    if (current->HasRightChild()) { elements.Enqueue(&current->RightChild()); }
    
    return current->Element();
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator*() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    return current->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (current == nullptr);
}

/* ************************************************************************** */

}
