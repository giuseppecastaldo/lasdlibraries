namespace lasd {

/* ************************************************************************** */

template <typename Data>
StackVec<Data>::StackVec() : Vector<Data>(2) { }

template <typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con) {
    size = 2;
    Elements = new Data[2];
    
    for (unsigned long i = 0; i < con.Size(); i++) {
        StackVec<Data>::Push(con[i]);
    }
}

template <typename Data>
StackVec<Data>::StackVec(const StackVec& s) : Vector<Data>(s) { index = s.index; }

template <typename Data>
StackVec<Data>::StackVec(StackVec&& s) noexcept : Vector<Data>(std::move(s)) { std::swap(index, s.index); }

template <typename Data>
StackVec<Data>::~StackVec() { }

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec& s) {
    Vector<Data>::operator=(s);
    index = s.index;
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec&& s) noexcept {
    Vector<Data>::operator=(std::move(s));
    std::swap(index, s.index);
    return *this;
}

template <typename Data>
bool StackVec<Data>::operator==(const StackVec& s) const noexcept {
    if (index != s.index) {
        return false;
    }
    
    for (unsigned long i = 0; i < index; i++) {
        if (Elements[i] != s.Elements[i]) {
            return false;
        }
    }
    
    return true;
}

template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& s) const noexcept {
    return !(*this == s);
}

template <typename Data>
void StackVec<Data>::Push(const Data& data) {
    if (index == size - 1) {
        Expand();
    }
    
    Elements[index] = data;
    index++;
}

template <typename Data>
void StackVec<Data>::Push(Data&& data) noexcept {
    if (index == size - 1) {
        Expand();
    }
    
    std::swap(Elements[index], data);
    index++;
}

template <typename Data>
Data& StackVec<Data>::Top() {
    if (index == 0) {
        throw std::length_error("Access to an empty stack vector.");
    }
    
    return Elements[index - 1];
}

template <typename Data>
void StackVec<Data>::Pop() {
    if (index == 0) {
        throw std::length_error("Access to an empty stack vector.");
    }
    
    index--;
    if (index <= (size/4)) {
        Reduce();
    }
}

template <typename Data>
Data StackVec<Data>::TopNPop() {
    Data result = Top();
    Pop();
    return result;
}

template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    if (index == 0) {
        return true;
    }
    
    return false;
}

template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
    return index;
}

template <typename Data>
void StackVec<Data>::Clear() {
    delete[] Elements;
    size = 2;
    Elements = new Data[2];
    index = 0;
}

template <typename Data>
void StackVec<Data>::Expand() {
    Vector<Data>::Resize(size * 2);
}

template <typename Data>
void StackVec<Data>::Reduce() {
    Vector<Data>::Resize(size / 2);
}

/* ************************************************************************** */

}
