namespace lasd {

/* ************************************************************************** */

template <typename Data>
Vector<Data>::Vector(const unsigned long newsize) {
    Elements = new Data[newsize] {};
    size = newsize;
}

template <typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& con) {
    size = con.Size();
    Elements = new Data[size];
    for (unsigned long index = 0; index < size; ++index) {
        Elements[index] = con[index];
    }
}

/* ************************************************************************** */

template <typename Data>
Vector<Data>::Vector(const Vector<Data>& vec) {
    Elements = new Data[vec.size];
    std::copy(vec.Elements, vec.Elements + vec.size, Elements);
    size = vec.size;
}

template <typename Data>
Vector<Data>::Vector(Vector<Data>&& vec) noexcept {
    std::swap(Elements, vec.Elements);
    std::swap(size, vec.size);
}

/* ************************************************************************** */

template <typename Data>
Vector<Data>::~Vector() {
    delete[] Elements;
}

/* ************************************************************************** */

template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec) {
    Vector<Data>* tmpvec = new Vector<Data>(vec);
    std::swap(*tmpvec, *this);
    delete tmpvec;
    return *this;
}

template <typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept {
    std::swap(Elements, vec.Elements);
    std::swap(size, vec.size);
    return *this;
}

/* ************************************************************************** */

template <typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept {
    if (size == vec.size) {
        for (unsigned long index = 0; index < size; ++index) {
            if (Elements[index] != vec.Elements[index]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

template <typename Data>
inline bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept {
    return !(*this == vec);
}

/* ************************************************************************** */

template <typename Data>
void Vector<Data>::Resize(const unsigned long newsize) {
    if (newsize == 0) {
        Clear();
    } else if (size != newsize) {
        unsigned long limit = (size < newsize) ? size : newsize;
        Data* TmpElements = new Data[newsize] {};
        for (unsigned long index = 0; index < limit; ++index) {
            std::swap(Elements[index], TmpElements[index]);
        }
        std::swap(Elements, TmpElements);
        size = newsize;
        delete[] TmpElements;
    }
}

template <typename Data>
void Vector<Data>::Clear() {
    delete[] Elements;
    Elements = nullptr;
    size = 0;
}

/* ************************************************************************** */

template <typename Data>
Data& Vector<Data>::Front() const {
    if (size != 0) {
        return Elements[0];
    } else {
        throw std::length_error("Access to an empty vector.");
    }
}

template <typename Data>
Data& Vector<Data>::Back() const {
    if (size != 0) {
        return Elements[size-1];
    } else {
        throw std::length_error("Access to an empty vector.");
    }
}

template <typename Data>
Data& Vector<Data>::operator[](const unsigned long index) const {
    if (index < size) {
        return Elements[index];
    } else {
        throw std::out_of_range("Access at index " + std::to_string(index) + " vector size " + std::to_string(size) + ".");
    }
}

/* ************************************************************************** */

template <typename Data>
void Vector<Data>::MapPreOrder(const MapFunctor fun, void* par) {
    for (unsigned long index = 0; index < size; ++index) {
        fun(Elements[index], par);
    }
}

template <typename Data>
void Vector<Data>::MapPostOrder(const MapFunctor fun, void* par) {
    unsigned long index = size;
    while (index > 0) {
        fun(Elements[--index], par);
    }
}

/* ************************************************************************** */

template <typename Data>
void Vector<Data>::FoldPreOrder(const FoldFunctor fun, const void* par, void* acc) const {
    for (unsigned long index = 0; index < size; ++index) {
        fun(Elements[index], par, acc);
    }
}

template <typename Data>
void Vector<Data>::FoldPostOrder(const FoldFunctor fun, const void* par, void* acc) const {
    unsigned long index = size;
    while (index > 0) {
        fun(Elements[--index], par, acc);
    }
}

/* ************************************************************************** */

}
