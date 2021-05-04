
namespace lasd {

/* ************************************************************************** */

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& n) {
    element = n.element;
    right = &(n.RightChild());
    left = &(n.LeftChild());

    return *this;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& n) noexcept {
    std::swap(element, n.element);
    std::swap(right, &(n.RightChild()));
    std::swap(left, &(n.LeftChild()));

    return *this;
}

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() {
    return element;
}

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const {
    return element;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return (!HasLeftChild() && !HasRightChild());
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (left != nullptr);
}


template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (right != nullptr);
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
    if (!HasLeftChild()) {
        throw std::out_of_range("Element not exists.");
    }

    return *left;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if (!HasRightChild()) {
        throw std::out_of_range("Element not exists.");
    }

    return *right;
}

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& lc) {
    size = lc.Size();
    FillTreeFromLinearContainer(lc, Root(), 0);
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& btl) {
    root = CopyTreeLnk(btl.root);
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& btl) noexcept {
    std::swap(size, btl.size);
    std::swap(root, btl.root);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator =(const BinaryTreeLnk& btl){
    Clear();
    root = CopyTreeLnk(btl.root);
    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator =(BinaryTreeLnk&& btl) noexcept{
    Clear();
    std::swap(size, btl.size);
    std::swap(root, btl.root);
    return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& btl) const noexcept {
    return BinaryTree<Data>::operator ==(btl);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator !=(const BinaryTreeLnk<Data>& tree) const noexcept{
    return !(*this == tree);
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const {
    if (root == nullptr)
        throw std::length_error("Empty tree!");

    return *root;
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    DeleteTree(root);
    root = nullptr;
}

template <typename Data>
void BinaryTreeLnk<Data>::DeleteTree(NodeLnk* root) noexcept {
    if(root != nullptr){
        DeleteTree(root->left);
        DeleteTree(root->right);
        delete root;
        size--;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopyTreeLnk(const NodeLnk* nodePtr){
    if(nodePtr == nullptr)
        return nullptr;
    else{
        struct NodeLnk* ptr = new struct NodeLnk(nodePtr->dato);
        ptr->left = CopyTreeLnk(nodePtr->left);
        ptr->right = CopyTreeLnk(nodePtr->right);
        size++;
        return ptr;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::FillTreeFromLinearContainer(const LinearContainer<Data>& lc, NodeLnk& root, unsigned int i) {
    if (i < lc.Size()) {
        root.element = lc[i];

        root.left = &(FillTreeFromLinearContainer(lc, root, 2*i+1));
        root.right = &(FillTreeFromLinearContainer(lc, root, 2*i+2));
    }

    return root;
}

/* ************************************************************************** */

}
