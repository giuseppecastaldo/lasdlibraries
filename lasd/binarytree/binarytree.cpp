
namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    return (node.element == element && node.LeftChild().Element() == LeftChild().Element() && node.RightChild().Element() == RightChild().Element());
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept {
    if (size != tree.Size() || tree.Root() != Root())
        return false;
    
    return true;
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& tree) const noexcept {
    return !(*this == tree);
}


template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor fun, void * par) {
    MapPreOrder(fun, par, Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor fun, void * par) {
    MapPostOrder(fun, par, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* acc, void *par) const {
    FoldPreOrder(fun, acc, par, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* acc, void *par) const {
    FoldPostOrder(fun, acc, par, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor fun, const void* acc, void* par) const {
    FoldInOrder(fun, acc, par, Root());
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor fun, void* par) {
    MapBreadth(fun, par, Root());
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor fun, const void* acc, void* par) const {
    FoldBreadth(fun, acc, par, Root());
}

/* ************************************************************************** */

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor fun, void * par, Node& node) {
    if (&node == nullptr) {
        return;
    }
    
    fun(node.Element(), par);
    if (node.HasLeftChild()) {
        MapPreOrder(fun, par, node.LeftChild());
    }
    
    if (node.HasRightChild()) {
        MapPreOrder(fun, par, node.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor fun, void * par, Node& node) {
    if (&node == nullptr) {
        return;
    }
    
    if (node.HasLeftChild()) {
        MapPostOrder(fun, par, node.LeftChild());
    }
    if (node.HasRightChild()) {
        MapPostOrder(fun, par, node.RightChild());
    }
    fun(node.Element(), par);
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(const FoldFunctor fun, const void* acc, void *par, Node& node) const {
    if (&node == nullptr) {
        return;
    }
    
    fun(node.Element(), acc, par);
    if (node.HasLeftChild()) {
        FoldPreOrder(fun, acc, par, node.LeftChild());
    }
    if (node.HasRightChild()) {
        FoldPreOrder(fun, acc, par, node.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(const FoldFunctor fun, const void* acc, void *par, Node& node) const {
    if (&node == nullptr) {
        return;
    }
    
    if (node.HasLeftChild()) {
        FoldPostOrder(fun, acc, par, node.LeftChild());
    }
    if (node.HasRightChild()) {
        FoldPostOrder(fun, acc, par, node.RightChild());
    }
    fun(node.Element(), acc, par);
}

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor fun, const void* acc, void* par, Node& node) const {
    if (&node == nullptr) {
        return;
    }
    
    if (node.HasLeftChild()) {
        FoldInOrder(fun, acc, par, node.LeftChild());
    }
    fun(node.Element(), acc, par);
    if (node.HasRightChild()) {
        FoldInOrder(fun, acc, par, node.RightChild());
    }
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor fun, void* par, Node& node) {
    lasd::QueueLst<Node*> queue;
    
    if (&node != nullptr) {
        queue.Enqueue(&node);
    }
    
    while (!queue.Empty()) {
        fun(queue.Head()->Element(), par);
        
        if (queue.Head()->HasLeftChild()) {
            queue.Enqueue(&(queue.Head()->LeftChild()));
        }
        
        if (queue.Head()->HasRightChild()) {
            queue.Enqueue(&(queue.Head()->RightChild()));
        }
        
        queue.Dequeue();
    }
}

template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor fun, const void* acc, void* par, Node& node) const {
    lasd::QueueLst<Node*> queue;
    
    if (&node != nullptr) {
        queue.Enqueue(&node);
    }
    
    while (!queue.Empty()) {
        fun(queue.Head()->Element(), acc, par);
        
        if (queue.Head()->HasLeftChild()) {
            queue.Enqueue(&(queue.Head()->LeftChild()));
        }
        
        if (queue.Head()->HasRightChild()) {
            queue.Enqueue(&(queue.Head()->RightChild()));
        }
        
        queue.Dequeue();
    }
}

/* ************************************************************************** */

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree) {
    current = &(tree.Root());
    elements.Push(&(tree.Root()));
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& it) {
    elements = StackLst<Data>(it.elements);
    current = it.current;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& it) noexcept {
    elements = StackLst<Data>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& it) {
    elements = it.elements;
    current = it.current;
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator++() {
    if (elements.Empty()) {
        current = nullptr;
    }
    
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
    elements = StackLst<Data>(it.elements);
    current = it.current;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    elements = StackLst<Data>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& it) {
    elements = it.elements;
    current = it.current;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator++() {
    if (elements.Empty()) {
        current = nullptr;
    }
    
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
    elements = StackLst<Data>(it.elements);
    current = it.current;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& it) noexcept {
    elements = StackLst<Data>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& it) {
    elements = it.elements;
    current = it.current;
    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator++() {
    if (elements.Empty()) {
        current = nullptr;
    }
    
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    current = elements.TopNPop();
    FindLastLeftNode(&(current->RightChild()));
    
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
    elements = StackLst<Data>(it.elements);
    current = it.current;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& it) noexcept {
    elements = StackLst<Data>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& it) {
    elements = it.elements;
    current = it.current;
    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& it) noexcept {
    std::swap(elements, it.elements);
    std::swap(current, it.current);
    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& it) const noexcept {
    return (elements == it.elements && current == it.current);
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& it) const noexcept {
    return !(*this == it);
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator++() {
    if (elements.Empty()) {
        current = nullptr;
    }
    
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
