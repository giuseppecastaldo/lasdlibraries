
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Stack: public virtual Container { // Must extend Container

private:

protected:

public:

  // Destructor
    virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
    Stack& operator=(const Stack&) = delete;

  // Move assignment
    Stack& operator=(const Stack&&) noexcept = delete;

  /* ************************************************************************ */

  // Comparison operators
    bool operator==(const Stack&) const noexcept = delete;
    inline bool operator!=(const Stack&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions
    
    virtual void Push(const Data&) = 0;
    virtual void Push(Data&&) noexcept = 0;
   
    virtual Data& Top() = 0; // (concrete function must throw std::length_error when empty)
    
    virtual void Pop() = 0; // (concrete function must throw std::length_error when empty)
    virtual Data TopNPop() = 0; // (concrete function must throw std::length_error when empty)

};

/* ************************************************************************** */

}

#endif
