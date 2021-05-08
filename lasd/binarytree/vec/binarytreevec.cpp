namespace lasd {

/* ************************************************************************ */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& value) {
    element = value;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& value){
    std::swap(element, value);
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element(){
    return element;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const {
    return element;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
    return (!HasLeftChild() && !HasRightChild());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    if (left < ptr->tree_vector.Size())
        return ((ptr->tree_vector)[left] != nullptr);
    
    return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    if (right < ptr->tree_vector.Size())
        return ((ptr->tree_vector)[right] != nullptr);
    
    return false;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if (!HasLeftChild())
        throw std::out_of_range("Left child does not exist.");
    
    return *(ptr->tree_vector)[left];
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if (!HasRightChild())
        throw std::out_of_range("Right child does not exist.");
    
    return *(ptr->tree_vector)[right];
}

/* ************************************************************************ */

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& lc) {
    InitializeVector(lc.Size());
    
    size = lc.Size();
    for (unsigned long i = 0; i < lc.Size(); i++) {
        tree_vector[i] = new NodeVec(lc[i]);
        tree_vector[i]->index = i;
        tree_vector[i]->left = i*2+1;
        tree_vector[i]->right = i*2+2;
        tree_vector[i]->ptr = this;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& tree){
    InitializeVector(tree.Size());
    
    size = tree.size;
    for (unsigned long i = 0; i < tree_vector.Size(); i++){
        if(tree.tree_vector[i] != nullptr){
            tree_vector[i] = new struct NodeVec(tree.tree_vector[i]->Element());
            tree_vector[i]->index = tree.tree_vector[i]->index;
            tree_vector[i]->left = tree.tree_vector[i]->left;
            tree_vector[i]->right = tree.tree_vector[i]->right;
            tree_vector[i]->ptr = this;
        }
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& tree) noexcept {
    InitializeVector(tree.Size());
    
    std::swap(size, tree.size);
    std::swap(tree_vector, tree.tree_vector);
    for(unsigned long i = 0; i < tree_vector.Size(); i++) {
        if(tree_vector[i] != nullptr){
            tree_vector[i]->ptr = this;
        }
    }
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    Clear();
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator =(const BinaryTreeVec& tree){
    Clear();
    InitializeVector(tree.Size());
    size = tree.size;
    
    for(unsigned long i = 0; i < tree_vector.Size(); i++) {
        if(tree.tree_vector[i] != nullptr){
            tree_vector[i] = new struct NodeVec(tree.tree_vector[i]->Element());
            tree_vector[i]->index = tree.tree_vector[i]->index;
            tree_vector[i]->left = tree.tree_vector[i]->left;
            tree_vector[i]->right = tree.tree_vector[i]->right;
            tree_vector[i]->ptr = this;
        }
    }
    
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator =(BinaryTreeVec&& tree) noexcept {
    std::swap(size, tree.size);
    std::swap(tree_vector, tree.tree_vector);
    
    for(unsigned long i = 0; i < tree_vector.Size(); i++) {
        if (tree_vector[i] != nullptr) {
            tree_vector[i]->ptr = this;
        }
    }
    
    for(unsigned long i = 0; i < tree.tree_vector.Size(); i++) {
        if (tree.tree_vector[i] != nullptr) {
            tree.tree_vector[i]->ptr = &tree;
        }
    }
    
    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator ==(const BinaryTree<Data>& tree) const noexcept{
    return BinaryTree<Data>::operator ==(tree);
}

template <typename Data>
bool BinaryTreeVec<Data>::operator !=(const BinaryTree<Data>& tree) const noexcept{
    return !(*this == tree);
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const{
    if (size == 0) {
        throw std::length_error("Empty tree.");
    }
    
    return *tree_vector[0];
}

template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor mapFunctor, void *par){
    for (unsigned long i = 0; i < tree_vector.Size(); i++) {
        if (tree_vector[i] != nullptr) {
            mapFunctor(tree_vector[i]->Element(), par);
        }
    }
}

template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor foldFunctor, const void *par, void *acc) const{
    for (unsigned long i = 0; i < tree_vector.Size(); i++) {
        if (tree_vector[i] != nullptr) {
            foldFunctor(tree_vector[i]->Element(), par, acc);
        }
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    size = 0;
    for(unsigned long i = 0; i < tree_vector.Size(); i++) {
        if (tree_vector[i] != nullptr) {
            delete tree_vector[i];
            tree_vector[i] = nullptr;
        }
    }
    
    tree_vector.Clear();
}

template <typename Data>
void BinaryTreeVec<Data>::InitializeVector(unsigned long size) {
    tree_vector.Resize(size);
    for(unsigned long i = 0; i < size; i++) {
        tree_vector[i] = nullptr;
    }
}

/* ************************************************************************ */

}
