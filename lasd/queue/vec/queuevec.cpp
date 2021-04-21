namespace lasd {

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec() : Vector<Data>(2) { }

template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con) {
    size = 2;
    Elements = new Data[2];
    
    for (unsigned long i = 0; i < con.Size(); i++) {
        QueueVec<Data>::Enqueue(con[i]);
    }
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& q) : Vector<Data>(q) {
    lenght = q.lenght;
    head = q.head;
    tail = q.tail;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& q) noexcept : Vector<Data>(std::move(q)) {
    std::swap(lenght, q.lenght);
    std::swap(head, q.head);
    std::swap(tail, q.tail);
}

template <typename Data>
QueueVec<Data>::~QueueVec() { }

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& q) {
    Vector<Data>::operator=(q);
    lenght = q.lenght;
    head = q.head;
    tail = q.tail;
    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& q) noexcept {
    Vector<Data>::operator=(std::move(q));
    std::swap(lenght, q.lenght);
    std::swap(head, q.head);
    std::swap(tail, q.tail);
    return *this;
}

template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& q) const noexcept {
    if (lenght != q.lenght) {
        return false;
    }
    
    unsigned long this_head = head;
    unsigned long q_head = q.head;
    
    for (unsigned long i = 0; i < lenght; i++) {
        if (Elements[this_head] != q.Elements[q_head]) {
            return false;
        }
        
        this_head = (this_head + 1) % size;
        q_head = (q_head + 1) % size;
    }
    
    return true;
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& q) const noexcept {
    return !(*this == q);
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& data) {
    if (lenght == size - 1) {
        Expand();
    }
    
    Elements[tail] = data;
    tail = (tail + 1) % size;
    lenght++;
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& data) noexcept {
    if (lenght == size - 1) {
        Expand();
    }
    
    std::swap(Elements[tail], data);
    tail = (tail + 1) % size;
    lenght++;
}

template <typename Data>
Data& QueueVec<Data>::Head() {
    if (lenght == 0) {
        throw std::length_error("Access to an empty queue vector.");
    }
    
    return Elements[head];
}

template <typename Data>
void QueueVec<Data>::Dequeue() {
    if (lenght == 0) {
        throw std::length_error("Access to an empty queue vector.");
    }
    
    head = (head + 1) % size;
    lenght--;
    
    if (lenght <= size/4) {
        Reduce();
    }
}

template <typename Data>
Data QueueVec<Data>::HeadNDequeue() {
    Data result = Head();
    Dequeue();
    return result;
}

template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
    if (lenght == 0) {
        return true;
    }
    
    return false;
}

template <typename Data>
unsigned long QueueVec<Data>::Size() const noexcept {
    return lenght;
}

template <typename Data>
void QueueVec<Data>::Clear() {
    size = 2;
    Elements = new Data[2];
    lenght = 0;
    head = 0;
    tail = 0;
}

template <typename Data>
void QueueVec<Data>::Expand() {
    SwapVectors(size * 2);
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    SwapVectors(size / 2);
}

template <typename Data>
void QueueVec<Data>::SwapVectors(unsigned long newsize) {
    if (newsize == 0) {
        Clear();
    } else if (size != newsize) {
        unsigned long this_head = head;
        Data* TmpElements = new Data[size] {};
        for (unsigned long index = 0; index < lenght; ++index) {
            std::swap(TmpElements[index],Elements[this_head]);
            this_head = (this_head + 1) % size;
        }
        
        std::swap(Elements, TmpElements);
        size = newsize;
        head = 0;
        tail = lenght;
        delete[] TmpElements;
    }
}

/* ************************************************************************** */

}
