//
//  vector.hpp
//  exercise1
//
//  Created by Giuseppe Castaldo on 02/04/21.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : public virtual LinearContainer<Data>, public virtual MappableContainer<Data>, public virtual FoldableContainer<Data> {
    
private:
    
protected:
    using LinearContainer<Data>::size;
    Data *Elements = nullptr;
    
public:
    // Default constructor
    Vector() = default;
    
    /* ************************************************************************ */
    
    // Specific constructors
    Vector(const unsigned long);
    Vector(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    Vector(const Vector&);
    
    // Move constructor
    Vector(Vector&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~Vector();
    
    /* ************************************************************************ */
    
    // Copy assignment
    Vector& operator = (const Vector&);
    
    // Move assignment
    Vector& operator = (Vector&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator==(const Vector&) const noexcept;
    inline bool operator!=(const Vector&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    void Resize(const unsigned long);
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from LinearContainer)
    
    Data& Front() const override;
    Data& Back() const override;
    
    Data& operator[](const unsigned long) const override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from MappableContainer)
    
    using typename MappableContainer<Data>::MapFunctor;
    
    void MapPreOrder(const MapFunctor, void *) override;
    void MapPostOrder(const MapFunctor, void *) override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from FoldableContainer)
    
    using typename FoldableContainer<Data>::FoldFunctor;
    
    void FoldPreOrder(const FoldFunctor, const void *, void *) const override;
    void FoldPostOrder(const FoldFunctor, const void *, void *) const override;
};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
