#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk: public BinaryTree<Data> {
    
private:
    
protected:
    
    using BinaryTree<Data>::size;
    
    struct NodeLnk: public BinaryTree<Data>::Node {
        
    private:
        
    protected:
        
        using BinaryTree<Data>::Node::element;
        NodeLnk* right = nullptr;
        NodeLnk* left = nullptr;
        
    public:
        
        friend class BinaryTreeLnk<Data>;
        
        /* ********************************************************************** */
        
        // Copy assignment
        NodeLnk& operator =(const NodeLnk&);
        
        // Move assignment
        NodeLnk& operator =(NodeLnk&&) noexcept;
        
        /* ********************************************************************** */
        
        // Specific member functions
        
        Data& Element() override;
        const Data& Element() const override;
        
        bool IsLeaf() const noexcept override;
        bool HasLeftChild() const noexcept override;
        bool HasRightChild() const noexcept override;
        
        NodeLnk& LeftChild() const override;
        NodeLnk& RightChild() const override;
        
    };
    
public:
    
    // Default constructor
    BinaryTreeLnk() = default;
    
    /* ************************************************************************ */
    
    // Specific constructors
    BinaryTreeLnk(const LinearContainer<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BinaryTreeLnk(const BinaryTreeLnk&);
    
    // Move constructor
    BinaryTreeLnk(BinaryTreeLnk&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~BinaryTreeLnk();
    
    /* ************************************************************************ */
    
    // Copy assignment
    BinaryTreeLnk& operator = (const BinaryTreeLnk&);
    
    // Move assignment
    BinaryTreeLnk& operator = (BinaryTreeLnk&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const BinaryTreeLnk&) const noexcept;
    inline bool operator != (const BinaryTreeLnk&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from BinaryTree)
    
    NodeLnk& Root() const override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override;
    
protected:
    
    NodeLnk *root = nullptr;
    void DeleteTree(NodeLnk* root) noexcept;
    NodeLnk* CopyTreeLnk(const NodeLnk* node);
    NodeLnk* FillTreeFromLinearContainer(const LinearContainer<Data>&, NodeLnk*, unsigned int);
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
