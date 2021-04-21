#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: public Stack<Data>, protected Vector<Data> {
    
private:
    
protected:
    
    using Vector<Data>::size;
    using Vector<Data>::Elements;
    unsigned long index = 0;
    
public:
    
    // Default constructor
    StackVec();
    
    /* ************************************************************************ */
    
    // Specific constructor
    StackVec(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    StackVec(const StackVec&);
    
    // Move constructor
    StackVec(StackVec&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~StackVec();
    
    /* ************************************************************************ */
    
    // Copy assignment
    StackVec& operator=(const StackVec&);
    
    // Move assignment
    StackVec& operator=(StackVec&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator==(const StackVec&) const noexcept;
    inline bool operator!=(const StackVec&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Stack)
    
    void Push(const Data&) override;
    void Push(Data&&) noexcept override;
    
    Data& Top() override;
    
    void Pop() override;
    Data TopNPop() override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    bool Empty() const noexcept override;
    
    unsigned long Size() const noexcept override;
    
    void Clear() override;
    
protected:
    
    // Auxiliary member functions
    
    void Expand();
    void Reduce();
    
};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
