#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec: public BinaryTree<Data> {
    
private:
    
protected:
    
    using BinaryTree<Data>::size;
    
public:
    
    using typename BinaryTree<Data>::Node;
    
    struct NodeVec: public BinaryTree<Data>::Node {
        
    private:
        
    protected:
        
        unsigned long index;
        unsigned long left;
        unsigned long right;
        using BinaryTree<Data>::Node::element;
        
        BinaryTreeVec<Data> *ptr = nullptr;
        
    public:
        
        friend class BinaryTreeVec<Data>;
        
        /* ************************************************************************ */
        
        NodeVec(const Data&);
        NodeVec(Data&&);
        
        /* ************************************************************************ */
        
        Data& Element() override;
        const Data& Element() const override;
        
        bool IsLeaf() const noexcept override;
        bool HasLeftChild() const noexcept override;
        bool HasRightChild() const noexcept override;
        
        NodeVec& LeftChild() const override;
        NodeVec& RightChild() const override;
        
    };
    
public:
    
    // Default constructor
    BinaryTreeVec() = default;
    
    /* ************************************************************************ */
    
    // Specific constructors
    BinaryTreeVec(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BinaryTreeVec(const BinaryTreeVec<Data>&);
    
    // Move constructor
    BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~BinaryTreeVec();
    
    /* ************************************************************************ */
    
    // Copy assignment
    BinaryTreeVec& operator =(const BinaryTreeVec<Data>&);
    
    // Move assignment
    BinaryTreeVec& operator =(BinaryTreeVec<Data>&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator ==(const BinaryTree<Data>&) const noexcept;
    bool operator !=(const BinaryTree<Data>&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from BinaryTree)
    
    NodeVec& Root() const override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override;
    
    /* ************************************************************************ */
    
    using typename BinaryTree<Data>::MapFunctor;
    void MapBreadth(MapFunctor, void*) override;
    
    using typename BinaryTree<Data>::FoldFunctor;
    void FoldBreadth(FoldFunctor, const void*, void*) const override;
    
protected:
    
    void InitializeVector(unsigned long size);
    
private:
    
    Vector<NodeVec*> tree_vector;
    
};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
