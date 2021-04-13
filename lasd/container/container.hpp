//
//  container.hpp
//  exercise1
//
//  Created by Giuseppe Castaldo on 02/04/21.
//

#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {
    
private:
    
protected:
    
    unsigned long size = 0;
    
public:
    
    // Destructor
    virtual ~Container() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    Container& operator = (const Container&) = delete;
    
    // Move assignment
    Container& operator = (Container&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const Container&) const noexcept = delete;
    bool operator != (const Container&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    virtual inline bool Empty() const noexcept {
        return (size == 0);
    };
    
    virtual inline unsigned long Size() const noexcept {
        return size;
    };
    
    virtual inline void Clear() = 0;
};

/* ************************************************************************** */

template <typename Data>
class LinearContainer : virtual public Container {
    
private:
    
protected:
    
public:
    
    // Destructor
    virtual ~LinearContainer() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    LinearContainer& operator = (const LinearContainer&) = delete;
    
    // Move assignment
    LinearContainer& operator = (LinearContainer&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const LinearContainer&) const noexcept = delete;
    bool operator != (const LinearContainer&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    virtual Data& Front() const = 0;
    virtual Data& Back() const = 0;
    virtual Data& operator [] (const unsigned long) const = 0; // (concrete function must throw std::out_of_range when out of range)
    
};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : public virtual Container {
    
private:
    
protected:
    
public:
    
    // Destructor
    virtual ~TestableContainer() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    TestableContainer& operator = (const TestableContainer&) = delete;
    
    // Move assignment
    TestableContainer& operator = (TestableContainer&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const TestableContainer&) const noexcept = delete;
    bool operator != (const TestableContainer&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    virtual bool Exists(const Data&) const noexcept = 0;
    
    // type Exists(argument) specifiers; // (concrete function should not throw exceptions)
    
};

/* ************************************************************************** */

template <typename Data>
class MappableContainer : public virtual Container {
    
private:
    
protected:
    
public:
    
    // Destructor
    virtual ~MappableContainer() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    MappableContainer& operator = (const MappableContainer&) = delete;
    
    // Move assignment
    MappableContainer& operator = (MappableContainer&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const MappableContainer&) const noexcept = delete;
    bool operator != (const MappableContainer&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    typedef std::function<void(Data&, void*)> MapFunctor;
    
    virtual void MapPreOrder(const MapFunctor, void*) = 0;
    virtual void MapPostOrder(const MapFunctor,void*) = 0;
    
};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : public virtual TestableContainer<Data> {
    
private:
    
protected:
    
public:
    
    // Destructor
    virtual ~FoldableContainer() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    FoldableContainer& operator = (const FoldableContainer&) = delete;
    
    // Move assignment
    FoldableContainer& operator = (FoldableContainer&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const FoldableContainer&) const noexcept = delete;
    bool operator != (const FoldableContainer&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    typedef std::function<void(const Data&, const void*, void*) noexcept> FoldFunctor;
    
    virtual void FoldPreOrder(const FoldFunctor, const void*, void*) const = 0;
    virtual void FoldPostOrder(const FoldFunctor, const void*, void*) const = 0;
    
    virtual bool Exists(const Data&) const noexcept override;
    
};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer { // Must extend MappableContainer
    
private:
    
protected:
    
public:
    
    // Destructor
    // ~BreadthMappableContainer() specifiers
    
    /* ************************************************************************ */
    
    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.
    
    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.
    
    /* ************************************************************************ */
    
    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    // using typename MappableContainer<Data>::MapFunctor;
    
    // type MapBreadth(arguments) specifiers;
    
};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer { // Must extend FoldableContainer
    
private:
    
    // ...
    
protected:
    
    // ...
    
public:
    
    // Destructor
    // ~BreadthFoldableContainer() specifiers
    
    /* ************************************************************************ */
    
    // Copy assignment
    // type operator=(argument); // Copy assignment of abstract types should not be possible.
    
    // Move assignment
    // type operator=(argument); // Move assignment of abstract types should not be possible.
    
    /* ************************************************************************ */
    
    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
    // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    // using typename FoldableContainer<Data>::FoldFunctor;
    
    // type FoldBreadth(arguments) specifiers;
    
};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
