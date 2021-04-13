#include <stdexcept>

// Default constructor
template <typename Data>
StackVec<Data>::StackVec() : Vector<Data>(2) {
    // size = 2;
    // Elements = new Data[2];
}

template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con) {
    Elements = new Data[con.Size()];
    for (unsigned long i = 0; i < con.Size(); i++) {
        StackVec<Data>::Push(con[i]);
    }
}

// Copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec& ref) : Vector<Data>(ref), index(ref.index){}

// Move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec&& ref) noexcept : Vector<Data>(std::move(ref)) {
    std::swap(index, ref.index);
}

// Destructor
template <typename Data>
StackVec<Data>::~StackVec(){} // E' chiamato quello di Vector


// Copy assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator =(const StackVec<Data>& ref){
    Vector<Data>::operator =(ref);
    index = ref.index;
    return *this;
}

// Move assignment
template <typename Data>
StackVec<Data>& StackVec<Data>::operator =(StackVec<Data>&& ref) noexcept{
    Vector<Data>::operator =(std::move(ref));
    std::swap(index, ref.index);
    return *this;
}

// Comparison operators
template <typename Data>
bool StackVec<Data>::operator ==(const StackVec<Data>& ref) const noexcept{
    if(index != ref.index)
        return false;

    for(unsigned long i = 0; i < index; i++){
        if(Elements[i] != ref.Elements[i])
            return false;
    }

    return true;
}

template <typename Data>
bool StackVec<Data>::operator !=(const StackVec<Data>& ref) const noexcept{
    return !(*this == ref);
}


// Specific member functions (inherited from Stack)
template <typename Data>
Data& StackVec<Data>::Top(){
    if(index == 0)
        throw std::length_error("StackVec vuoto!");

    return Elements[index-1];
}

template <typename Data>
void StackVec<Data>::Pop(){
    if(index == 0)
        throw std::length_error("StackVec vuoto!");

    index--;
    if(index <= (size/4))
        Reduce();
}

template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(index == 0)
        throw std::length_error("StackVec vuoto!");
    
    Data result = Top();
    Pop();
    return result;
}

template <typename Data>
void StackVec<Data>::Push(const Data& ref){
    if(index == size-1)
        Expand();

    Elements[index] = ref;
    index++;
}

template <typename Data>
void StackVec<Data>::Push(Data&& ref) noexcept{
    if(index == size-1)
        Expand();
        
    std::swap(Elements[index], ref);
    index++;
}

// Specific member functions (inherited from Container)
template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
    if(index == 0)
        return true;
    
    return false;
}

template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept{
    return index;
}

template <typename Data>
void StackVec<Data>::Clear(){
    Vector<Data>::Clear();
    index = 0;
    Vector<Data>::Resize(2);
}


template <typename Data>
void StackVec<Data>::Expand(){
    Vector<Data>::Resize(2*size);
}

template <typename Data>
void StackVec<Data>::Reduce(){
    Vector<Data>::Resize(size/2);
}
