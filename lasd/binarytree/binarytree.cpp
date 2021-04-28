
// #include "..."

namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept {
    return node.element == element;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

/* ************************************************************************** */

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& tree) {
    PreOrder(tree.Root());
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& it) {
    QueueLst<struct BinaryTree<Data>::Node*> tmp(it.elements);
    elements = tmp;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& it) noexcept {
    QueueLst<struct BinaryTree<Data>::Node*> tmp(std::swap(it.elements));
    elements = tmp;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& it) {
    elements = it.elements;
    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& it) const noexcept {
    return (it.elements == elements);
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& it) const noexcept {
    return (it.elements != elements);
}

template <typename Data>
void BTPreOrderIterator<Data>::operator++() {
    elements.Dequeue();
}

template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() {
    elements.Head();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() {
    return elements.Empty();
}

template <typename Data>
void BTPreOrderIterator<Data>::FillQueueInPreOrder(struct BinaryTree<Data>::Node* root) {
    if (root == nullptr)
        return;
    
    elements.Enqueue(root);
    preorder(root->LeftChild());
    preorder(root->rightChild());
}

/* ************************************************************************** */

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& tree) {
    PostOrder(tree.Root());
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& it) {
    QueueLst<struct BinaryTree<Data>::Node*> tmp(it.elements);
    elements = tmp;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& it) noexcept {
    QueueLst<struct BinaryTree<Data>::Node*> tmp(std::swap(it.elements));
    elements = tmp;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& it) {
    elements = it.elements;
    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& it) noexcept {
    std::swap(elements, it.elements);
    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& it) const noexcept {
    return (it.elements == elements);
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& it) const noexcept {
    return (it.elements != elements);
}

template <typename Data>
void BTPostOrderIterator<Data>::operator++() {
    elements.Dequeue();
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() {
    elements.Head();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() {
    return elements.Empty();
}

template <typename Data>
void BTPostOrderIterator<Data>::FillQueueInPostOrder(struct BinaryTree<Data>::Node* root) {
    if (root == nullptr)
        return;
    
    elements.Enqueue(root);
    PostOrder(root->LeftChild());
    PostOrder(root->rightChild());
}

/* ************************************************************************** */

}
