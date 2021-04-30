#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: public Stack<Data>, protected List<Data> { // Must extend Stack<Data> and List<Data>
    
private:
    
protected:
    
    using List<Data>::size;
    
public:
    
    // Default constructor
    StackLst() = default;
    
    /* ************************************************************************ */
    
    // Specific constructor
    StackLst(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    StackLst(const StackLst&);
    
    // Move constructor
    StackLst(StackLst&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~StackLst();
    
    /* ************************************************************************ */
    
    // Copy assignment
    StackLst& operator = (const StackLst&);
    
    // Move assignment
    StackLst& operator = (StackLst&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator==(const StackLst&) const noexcept;
    inline bool operator!=(const StackLst&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Stack)
    
    void Push(const Data&) override;
    void Push(Data&&) noexcept override;
    
    Data& Top() override; // Override Stack member (must throw std::length_error when empty)
    
    void Pop() override; // Override Stack member (must throw std::length_error when empty)
    Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override;
    
};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
&&