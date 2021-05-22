
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
    
protected:
    
    using BinaryTreeLnk<Data>::size;
    using BinaryTreeLnk<Data>::root;
    using typename BinaryTreeLnk<Data>::NodeLnk;
    
public:

    // Default constructor
    BST() = default;
    
    /* ************************************************************************ */
    
    // Specific constructors
    BST(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BST(const BST&);
    
    // Move constructor
    BST(BST&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    ~BST() = default;
    
    /* ************************************************************************ */
    
    // Copy assignment
    BST& operator =(const BST&);
    
    // Move assignment
    BST& operator =(BST&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator ==(const BST&) const noexcept;
    bool operator !=(const BST&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    void Insert(const Data&);
    void Insert(Data&&);
    void Remove(const Data&);
    
    Data& Min() const; // (concrete function must throw std::length_error when empty)
    Data MinNRemove(); // (concrete function must throw std::length_error when empty)
    void RemoveMin(); // (concrete function must throw std::length_error when empty)
    
    Data& Max() const; // (concrete function must throw std::length_error when empty)
    Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
    void RemoveMax(); // (concrete function must throw std::length_error when empty)
    
    Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when empty)
    Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
    void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when empty)
    
    Data& Successor(const Data&) const; // (concrete function must throw std::length_error when empty)
    Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
    void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when empty)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from TestableContainer)
    
    bool Exists(const Data&) const noexcept override;
    
protected:
    
    // Auxiliary member functions
    
    Data DataNDelete(NodeLnk*);
    
    NodeLnk* Detach(NodeLnk*, const Data&);
    
    NodeLnk* DetachMin(NodeLnk*, NodeLnk*);
    NodeLnk* DetachMax(NodeLnk*, NodeLnk*);
    
    NodeLnk* SkipOnLeft(NodeLnk*&);
    NodeLnk* SkipOnRight(NodeLnk*&);
    
    NodeLnk* FindPointerToMin(NodeLnk*) const noexcept;
    NodeLnk* FindPointerToMax(NodeLnk*) const noexcept;
    
    NodeLnk*& FindPointerTo(NodeLnk*&, const Data&) noexcept;
    NodeLnk* FindPointerTo(NodeLnk*, const Data&) const noexcept;
    
    NodeLnk* FindPointerToPredecessor(NodeLnk*, NodeLnk*, const Data&) const noexcept;
    NodeLnk* FindPointerToSuccessor(NodeLnk*, NodeLnk*, const Data&) const noexcept;
    
};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
