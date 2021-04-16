#include <stdexcept>

// Default constructor
template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(2){
    // size = 2;
    // Elements = new Data[2];
}

template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con) {
    size = 2;
    Elements = new Data[2];
    
    for (unsigned long i = 0; i < con.Size(); i++) {
        QueueVec<Data>::Enqueue(con[i]);
    }
}

// Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& ref) : Vector<Data>(ref), top(ref.top), back(ref.back), lunghezza(ref.lunghezza) { }


// Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& ref) noexcept : Vector<Data>(std::move(ref)) {
    std::swap(top, ref.top);
    std::swap(back, ref.back);
    std::swap(lunghezza, ref.lunghezza);
}


// Destructor
template <typename Data>
QueueVec<Data>::~QueueVec() { } // E' chiamato quello di Vector


// Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator =(const QueueVec<Data>& ref){
    Vector<Data>::operator =(ref);
    top = ref.top;
    back = ref.back;
    lunghezza = ref.lunghezza;
    return *this;
}


// Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator =(QueueVec<Data>&& ref) noexcept{
    Vector<Data>::operator =(std::move(ref));
    std::swap(top, ref.top);
    std::swap(back, ref.back);
    std::swap(lunghezza, ref.lunghezza);
    return *this;
}


// Comparison operators
template <typename Data>
bool QueueVec<Data>::operator ==(const QueueVec<Data>& ref) const noexcept{
    if(lunghezza != ref.lunghezza)
        return false;
    
    unsigned long index = top;
    unsigned long index_ref = ref.top;
    
    for(unsigned long i = 0; i < lunghezza; i++){
        if(Elements[index] != ref.Elements[index_ref])
            return false;
        index = (index + 1) % size;
        index_ref = (index_ref + 1) % ref.size;
    }
    
    return true;
}

template <typename Data>
bool QueueVec<Data>::operator !=(const QueueVec<Data>& ref) const noexcept{
    return !(*this == ref);
}

// Specific member functions (inherited from Stack)
template <typename Data>
Data& QueueVec<Data>::Head(){
    if(lunghezza == 0)
        throw std::length_error("Coda vuota!");
    
    return Elements[top];
}

template <typename Data>
void QueueVec<Data>::Dequeue(){
    if(lunghezza == 0)
        throw std::length_error("QueueVec vuoto!");
    
    top = (top + 1) % size;
    lunghezza--;
    if(lunghezza <= (size / 4))
        Reduce();
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if(lunghezza == 0)
        throw std::length_error("QueueVec vuoto!");
    
    Data result = Head();
    Dequeue();
    return result;
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& ref){
    if(lunghezza == size - 1)
        Expand();
    
    lunghezza++;
    Elements[back] = ref;
    back = (back + 1) % size;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& ref) noexcept{
    if(lunghezza == size - 1)
        Expand();
    
    lunghezza++;
    std::swap(Elements[back], ref);
    back = (back + 1) % size;
}

// Specific member functions (inherited from Container)
template <typename Data>
bool QueueVec<Data>::Empty() const noexcept{
    if(lunghezza == 0)
        return true;
    
    return false;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept{
    return lunghezza;
}

template <typename Data>
void QueueVec<Data>::Clear(){
    Vector<Data>::Clear();
    top = 0;
    back = 0;
    lunghezza = 0;
    Vector<Data>::Resize(2);
}

template <typename Data>
void QueueVec<Data>::Expand(){
    Data *tmp = new Data[size * 2];
    unsigned long index = top;
    for(unsigned long i = 0; i < lunghezza; i++){
        tmp[i] = Elements[index];
        index = (index + 1) % size;
    }
    top = 0;
    back = lunghezza;
    size = size * 2;
    std::swap(tmp, Elements);
    delete[] tmp;
}

template <typename Data>
void QueueVec<Data>::Reduce(){
    Data *tmp = new Data[size / 2];
    unsigned long index = top;
    for(unsigned long i = 0; i < lunghezza; i++){
        tmp[i] = Elements[index];
        index = (index + 1) % size;
    }
    top = 0;
    back = lunghezza;
    size = size / 2;
    std::swap(tmp, Elements);
    delete[] tmp;
}
