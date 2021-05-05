
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& value){
    element = value;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& value){
    std::swap(element, value);
}

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
        throw std::out_of_range("Left child does not exist.");
    }
    
    return *left;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
    if (!HasRightChild()) {
        throw std::out_of_range("Right child does not exist.");
    }
    
    return *right;
}

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& lc) {
    size = lc.Size();
    root = FillTreeFromLinearContainer(lc, root, 0);
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& btl) {
    root = CopyTree(btl.root);
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
    root = CopyTree(btl.root);
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
        throw std::length_error("Empty tree.");
    
    return *root;
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    DeleteTree(root);
    root = nullptr;
}

template <typename Data>
void BinaryTreeLnk<Data>::DeleteTree(NodeLnk* node) noexcept {
    if(node != nullptr){
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
        if(size > 0)
            size--;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::CopyTree(const NodeLnk* node){
    if(node == nullptr)
        return nullptr;
    else{
        NodeLnk* ptr = new NodeLnk(node->element);
        
        ptr->left = CopyTree(node->left);
        ptr->right = CopyTree(node->right);
        size++;
        return ptr;
    }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::FillTreeFromLinearContainer(const LinearContainer<Data>& lc, NodeLnk* root, unsigned int i) {
    if (i < lc.Size()) {
        root = new NodeLnk(lc[i]);
        
        root->left = FillTreeFromLinearContainer(lc, root->left, 2*i+1);
        root->right = FillTreeFromLinearContainer(lc, root->right, 2*i+2);
    }
    
    return root;
}

/* ************************************************************************** */

}
