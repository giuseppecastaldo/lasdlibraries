
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

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& tree) const noexcept {
    if (size != tree.Size()) {
        return false;
    }
    
    if (size == 0 && tree.Size() == 0) {
        return true;
    }
    
    return CompareTrees(Root(), tree.Root());
}

template <typename Data>
bool BinaryTree<Data>::CompareTrees(Node& root1, Node& root2) const {
    bool flag = true;
    
    if (root1.Element() != root2.Element()) {
        flag = false;
    } else {
        if (root1.HasLeftChild() && root2.HasLeftChild()) {
            flag = CompareTrees(root1.LeftChild(),root2.LeftChild());
        } else if (!root1.HasLeftChild() && !root2.HasLeftChild()) {
            flag = true;
        } else {
            flag = false;
        }
        
        if (flag == true) {
            if (root1.HasRightChild() && root2.HasRightChild()) {
                flag = CompareTrees(root1.RightChild(), root2.RightChild());
            } else if (!root1.HasRightChild() && !root2.HasRightChild()) {
                flag = true;
            } else {
                flag = false;
            }
        }
    }
    
    return flag;
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
void BinaryTree<Data>::MapInOrder(MapFunctor fun, void* par) {
    MapInOrder(fun, par, Root());
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
void BinaryTree<Data>::MapInOrder(MapFunctor fun, void* par, Node& node) {
    if (&node == nullptr) {
        return;
    }
    
    if (node.HasLeftChild()) {
        MapInOrder(fun, par, node.LeftChild());
    }
    fun(node.Element(), par);
    if (node.HasRightChild()) {
        MapInOrder(fun, par, node.RightChild());
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
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& it) {
    elements = StackLst<typename BinaryTree<Data>::Node*>(it.elements);
    current = it.current;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& it) noexcept {
    elements = StackLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator() {
    elements.Clear();
    current = nullptr;
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
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    if (current->HasRightChild()) {
        elements.Push(&(current->RightChild()));
    }
    
    if (current->HasLeftChild()) {
        elements.Push(&(current->LeftChild()));
    }
    
    if (elements.Empty()) {
        current = nullptr;
    } else {
        current = elements.TopNPop();
    }
    
    return *this;
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const {
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
    current = elements.TopNPop();
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& it) {
    elements = StackLst<typename BinaryTree<Data>::Node*>(it.elements);
    current = it.current;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    elements = StackLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator() {
    elements.Clear();
    current = nullptr;
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
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    if (!elements.Empty()) {
        if (elements.Top()->HasLeftChild()) {
            if (current == &(elements.Top()->LeftChild())) {
                if (elements.Top()->HasRightChild()) {
                    FindLastLeftLeaf(&(elements.Top()->RightChild()));
                }
            }
        }
        
        current = elements.TopNPop();
    } else {
        current = nullptr;
    }
    
    return *this;
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const {
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
        } else if (node->HasRightChild()) {
            node = &(node->RightChild());
        } else {
            node = nullptr;
        }
    }
}

/* ************************************************************************** */

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& tree) {
    FindLastLeftNode(&(tree.Root()));
    current = elements.TopNPop();
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& it) {
    elements = StackLst<typename BinaryTree<Data>::Node*>(it.elements);
    current = it.current;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& it) noexcept {
    elements = StackLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
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
BTInOrderIterator<Data>::~BTInOrderIterator() {
    elements.Clear();
    current = nullptr;
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
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    if (current->HasRightChild()) {
        FindLastLeftNode(&(current->RightChild()));
    }
    
    if (elements.Empty()) {
        current = nullptr;
    } else {
        current = elements.TopNPop();
    }
    
    return *this;
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const {
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
        if (node->HasLeftChild()) {
            node = &(node->LeftChild());
        } else {
            node = nullptr;
        }
    }
}

/* ************************************************************************** */

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& tree) {
    current = &(tree.Root());
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& it) {
    elements = QueueLst<typename BinaryTree<Data>::Node*>(it.elements);
    current = it.current;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& it) noexcept {
    elements = QueueLst<typename BinaryTree<Data>::Node*>(std::move(it.elements));
    std::swap(current, it.current);
}

template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator() {
    elements.Clear();
    current = nullptr;
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
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if (Terminated()) {
        throw std::out_of_range("Out of range exception.");
    }
    
    if (current->HasLeftChild()) {
        elements.Enqueue(&current->LeftChild());
    }
    if (current->HasRightChild()) {
        elements.Enqueue(&current->RightChild());
    }
    
    if (elements.Empty()) {
        current = nullptr;
    } else {
        current = elements.HeadNDequeue();
    }
    
    return *this;
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const {
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
