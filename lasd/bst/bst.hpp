
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST: public BinaryTreeLnk<Data> {
    
private:
    
    // ...
    
protected:
    
    using BinaryTreeLnk<Data>::size;
    using BinaryTreeLnk<Data>::root;
    
public:
    
    // Default constructor
    BST() = default;
    
    /* ************************************************************************ */
    
    // Specific constructors
    BST(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    // BST(argument) specifiers;
    
    // Move constructor
    // BST(argument) specifiers;
    
    /* ************************************************************************ */
    
    // Destructor
    // ~BST() specifiers;
    
    /* ************************************************************************ */
    
    // Copy assignment
    // type operator=(argument) specifiers;
    
    // Move assignment
    // type operator=(argument) specifiers;
    
    /* ************************************************************************ */
    
    // Comparison operators
    // type operator==(argument) specifiers;
    // type operator!=(argument) specifiers;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    void Insert(const Data&);
    // type Insert(argument) specifiers; // Move of the value
    // type Remove(argument) specifiers;
    
    // type Min(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type MinNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type RemoveMin(argument) specifiers; // (concrete function must throw std::length_error when empty)
    
    // type Max(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type MaxNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type RemoveMax(argument) specifiers; // (concrete function must throw std::length_error when empty)
    
    // type Predecessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type PredecessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type RemovePredecessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
    
    // type Successor(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type SuccessorNRemove(argument) specifiers; // (concrete function must throw std::length_error when empty)
    // type RemoveSuccessor(argument) specifiers; // (concrete function must throw std::length_error when empty)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from TestableContainer)
    
    bool Exists(const Data&) const noexcept override;
    
protected:
    
    // Auxiliary member functions
    
    // type DataNDelete(argument) specifiers;
    
    // type Detach(argument) specifiers;
    
    // type DetachMin(argument) specifiers;
    // type DetachMax(argument) specifiers;
    
    // type SkipOnLeft(argument) specifiers;
    // type SkipOnRight(argument) specifiers;
    
    // type FindPointerToMin(argument) specifiers;
    // type FindPointerToMax(argument) specifiers;
    
    typename BinaryTreeLnk<Data>::NodeLnk*& FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk*&, const Data&) noexcept;
    typename BinaryTreeLnk<Data>::NodeLnk* const& FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk* const&, const Data&) const noexcept;
    
    // type FindPointerToPredecessor(argument) specifiers;
    // type FindPointerToSuccessor(argument) specifiers;
    
};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
