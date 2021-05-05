namespace lasd {

/* ************************************************************************ */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& value){
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
    if (left < ptr->vettore.Size())
        return ((ptr->vettore)[left] != nullptr);
    
    return false;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    if (right < ptr->vettore.Size())
        return ((ptr->vettore)[right] != nullptr);
    
    return false;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if (!HasLeftChild())
        throw std::out_of_range("Non esiste il figlio sinistro");
    
    return *(ptr->vettore)[left];
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if (!HasRightChild())
        throw std::out_of_range("Non esiste il figlio destro");
    
    return *(ptr->vettore)[right];
}

/* ************************************************************************ */

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec() {
    vettore.Resize(7);
    for(unsigned long i = 0; i < vettore.Size(); i++)
    vettore[i] = nullptr;
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& lc) {
    vettore.Resize(lc.Size());
    for(unsigned long i = 0; i < vettore.Size(); i++)
    vettore[i] = nullptr;
    
    size = lc.Size();
    for (unsigned long i = 0; i < lc.Size(); i++) {
        vettore[i] = new struct NodeVec(lc[i]);
        vettore[i]->index = i;
        vettore[i]->left = i*2+1;
        vettore[i]->right = i*2+2;
        vettore[i]->ptr = this;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec& tree){
    vettore.Resize(tree.vettore.Size());
    for(unsigned long i = 0; i < vettore.Size(); i++)
    vettore[i] = nullptr;
    
    size = tree.size;
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(tree.vettore[i] != nullptr){
            vettore[i] = new struct NodeVec(tree.vettore[i]->Element());
            
            vettore[i]->index = tree.vettore[i]->index;
            vettore[i]->left = tree.vettore[i]->left;
            vettore[i]->right = tree.vettore[i]->right;
            vettore[i]->ptr = this;
        }
    }
    
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec&& tree) noexcept{
    vettore.Resize(7);
    for(unsigned long i = 0; i < vettore.Size(); i++)
    vettore[i] = nullptr;
    
    std::swap(size, tree.size);
    std::swap(vettore, tree.vettore);
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr){
            vettore[i]->ptr = this;
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
    size = tree.size;
    
    for(unsigned long i = 0; i < size; i++){
        if(tree.vettore[i] != nullptr){
            vettore[i] = new struct NodeVec(tree.vettore[i]->Element());
            vettore[i]->index = tree.vettore[i]->index;
            vettore[i]->left = tree.vettore[i]->left;
            vettore[i]->right = tree.vettore[i]->right;
            vettore[i]->ptr = this;
        }
    }
    
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator =(BinaryTreeVec&& tree) noexcept{
    Clear();
    
    std::swap(size, tree.size);
    std::swap(vettore, tree.vettore);
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr){
            vettore[i]->ptr = this;
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
    if(size == 0)
        throw std::length_error("Albero vuoto");
    
    return *vettore[0];
}

template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor mapFunctor, void *par){
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr)
            mapFunctor(vettore[i]->Element(), par);
    }
}

template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor foldFunctor, const void *par, void *acc) const{
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr)
            foldFunctor(vettore[i]->Element(), par, acc);
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Expand(){
    unsigned long oldSize = vettore.Size();
    vettore.Resize( vettore.Size()*2 + 1);
    for(unsigned long i = oldSize; i < vettore.Size(); i++)
    vettore[i] = nullptr;
    
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr){
            vettore[i]->ptr = this;
        }
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Reduce(){
    vettore.Resize( (vettore.Size()-1) / 2 );
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr){
            vettore[i]->ptr = this;
        }
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    size = 0;
    for(unsigned long i = 0; i < vettore.Size(); i++){
        if(vettore[i] != nullptr){
            delete vettore[i];
            vettore[i] = nullptr;
        }
    }
    vettore.Clear();
    vettore.Resize(7);
    for(unsigned long i = 0; i < vettore.Size(); i++)
    vettore[i] = nullptr;
}

/* ************************************************************************ */

}
