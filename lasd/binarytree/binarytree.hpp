#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/queue.hpp"
#include "../stack/stack.hpp"

#include "../stack/lst/stacklst.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree: virtual public InOrderMappableContainer<Data>, virtual public BreadthMappableContainer<Data>, virtual public InOrderFoldableContainer<Data>, virtual public BreadthFoldableContainer<Data> {
    
private:
    
protected:
    
    using InOrderMappableContainer<Data>::size;
    using BreadthMappableContainer<Data>::size;
    
public:
    
    struct Node {
        
    private:
        
    protected:
        
        Data element;
        
    public:
        
        friend class BinaryTree<Data>;
        
        /* ********************************************************************** */
        
        // Destructor
        virtual ~Node() = default;
        
        /* ********************************************************************** */
        
        // Copy assignment
        Node& operator =(const Node&) = delete;
        
        // Move assignment
        Node& operator =(Node&&) noexcept = delete;
        
        /* ********************************************************************** */
        
        // Comparison operators
        bool operator == (const Node&) const noexcept;
        inline bool operator != (const Node&) const noexcept;
        
        /* ********************************************************************** */
        
        // Specific member functions
        
        virtual Data& Element() = 0;
        virtual const Data& Element() const = 0;
        
        virtual bool IsLeaf() const noexcept = 0;
        virtual bool HasLeftChild() const noexcept = 0;
        virtual bool HasRightChild() const noexcept = 0;
        
        virtual Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
        virtual Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
        
    };
    
    /* ************************************************************************ */
    
    // Destructor
    ~BinaryTree() = default;
    
    /* ********************************************************************** */
    
    // Copy assignment
    BinaryTree& operator =(const BinaryTree&) = delete;
    
    // Move assignment
    BinaryTree& operator =(BinaryTree&&) noexcept = delete;
    
    /* ********************************************************************** */
    
    // Comparison operators
    bool operator ==(const BinaryTree&) const noexcept;
    inline bool operator !=(const BinaryTree&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    virtual Node& Root() const = 0; // (concrete function must throw std::length_error when empty)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from MappableContainer)
    
    using typename MappableContainer<Data>::MapFunctor;
    
    virtual void MapPreOrder(MapFunctor, void *) override;
    virtual void MapPostOrder(MapFunctor, void *) override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from FoldableContainer)
    
    using typename FoldableContainer<Data>::FoldFunctor;
    
    virtual void FoldPreOrder(const FoldFunctor, const void *, void *) const override;
    virtual void FoldPostOrder(const FoldFunctor, const void *, void *) const override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from InOrderMappableContainer)
    
    virtual void MapInOrder(MapFunctor, void*) override; // Override InOrderMappableContainer member
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from InOrderFoldableContainer)
    
    virtual void FoldInOrder(FoldFunctor, const void*, void*) const override; // Override InOrderFoldableContainer member
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from BreadthMappableContainer)
    
    virtual void MapBreadth(MapFunctor, void*) override; // Override BreadthMappableContainer member
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from BreadthFoldableContainer)
    
    virtual void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member
    
protected:
    
    // Auxiliary member functions (for MappableContainer)
    
    virtual void MapPreOrder(MapFunctor, void*, Node&);
    virtual void MapPostOrder(MapFunctor, void*, Node&);
    
    /* ************************************************************************ */
    
    // Auxiliary member functions (for FoldableContainer)
    
    virtual void FoldPreOrder(FoldFunctor, const void*, void*, Node&) const;
    virtual void FoldPostOrder(FoldFunctor, const void*, void*, Node&) const;
    
    /* ************************************************************************ */
    
    // Auxiliary member functions (for InOrderMappableContainer)
    
    virtual void MapInOrder(MapFunctor, void*, Node&);
    
    /* ************************************************************************ */
    
    // Auxiliary member functions (for InOrderFoldableContainer)
    
    virtual void FoldInOrder(FoldFunctor, const void*, void*, Node&) const;
    
    /* ************************************************************************ */
    
    // Auxiliary member functions (for BreadthMappableContainer)
    
    virtual void MapBreadth(MapFunctor, void*, Node&);
    
    /* ************************************************************************ */
    
    // Auxiliary member functions (for BreadthFoldableContainer)
    
    virtual void FoldBreadth(FoldFunctor, const void*, void*, Node&) const;
    
};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator: public virtual ForwardIterator<Data> {
    
private:
    
protected:
    
    typename BinaryTree<Data>::Node* current;
    StackLst<typename BinaryTree<Data>::Node*> elements;
    
public:
    
    // Specific constructors
    BTPreOrderIterator(const BinaryTree<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BTPreOrderIterator(const BTPreOrderIterator&);
    
    // Move constructor
    BTPreOrderIterator(BTPreOrderIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~BTPreOrderIterator();
    
    /* ************************************************************************ */
    
    // Copy assignment
    BTPreOrderIterator& operator = (const BTPreOrderIterator&);
    
    // Move assignment
    BTPreOrderIterator& operator = (BTPreOrderIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const BTPreOrderIterator&) const noexcept;
    inline bool operator != (const BTPreOrderIterator&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Iterator)
    
    Data& operator*() override; // (throw std::out_of_range when terminated)
    
    bool Terminated() const noexcept override; // (should not throw exceptions)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from ForwardIterator)
    
    Data& operator++() override; // (throw std::out_of_range when terminated)
    
};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data> {
    
private:
    
protected:
    
    typename BinaryTree<Data>::Node* current;
    StackLst<typename BinaryTree<Data>::Node*> elements;
    
public:
    
    // Specific constructors
    BTPostOrderIterator(const BinaryTree<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BTPostOrderIterator(const BTPostOrderIterator&);
    
    // Move constructor
    BTPostOrderIterator(BTPostOrderIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~BTPostOrderIterator();
    
    /* ************************************************************************ */
    
    // Copy assignment
    BTPostOrderIterator& operator = (const BTPostOrderIterator&);
    
    // Move assignment
    BTPostOrderIterator& operator = (BTPostOrderIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const BTPostOrderIterator&) const noexcept;
    inline bool operator != (const BTPostOrderIterator&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Iterator)
    
    Data& operator*() override; // (throw std::out_of_range when terminated)
    
    bool Terminated() const noexcept override; // (should not throw exceptions)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from ForwardIterator)
    
    Data& operator++() override; // (throw std::out_of_range when terminated)
    
protected:
    
    void FindLastLeftLeaf(typename BinaryTree<Data>::Node*);
    
};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data> {
    
private:
    
protected:
    
    typename BinaryTree<Data>::Node* current;
    StackLst<typename BinaryTree<Data>::Node*> elements;
    
public:
    
    // Specific constructors
    BTInOrderIterator(const BinaryTree<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BTInOrderIterator(const BTInOrderIterator&);
    
    // Move constructor
    BTInOrderIterator(BTInOrderIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~BTInOrderIterator();
    
    /* ************************************************************************ */
    
    // Copy assignment
    BTInOrderIterator& operator = (const BTInOrderIterator&);
    
    // Move assignment
    BTInOrderIterator& operator = (BTInOrderIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const BTInOrderIterator&) const noexcept;
    inline bool operator != (const BTInOrderIterator&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Iterator)
    
    Data& operator*() override; // (throw std::out_of_range when terminated)
    
    bool Terminated() const noexcept override; // (should not throw exceptions)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from ForwardIterator)
    
    Data& operator++() override; // (throw std::out_of_range when terminated)
    
protected:
    
    void FindLastLeftNode(typename BinaryTree<Data>::Node*);
    
};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator: virtual public ForwardIterator<Data> {
    
private:
    
protected:
    
    typename BinaryTree<Data>::Node* current;
    QueueLst<typename BinaryTree<Data>::Node*> elements;
    
public:
    
    // Specific constructors
    BTBreadthIterator(const BinaryTree<Data>&);
    
    /* ************************************************************************ */
    
    // Copy constructor
    BTBreadthIterator(const BTBreadthIterator&);
    
    // Move constructor
    BTBreadthIterator(BTBreadthIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~BTBreadthIterator();
    
    /* ************************************************************************ */
    
    // Copy assignment
    BTBreadthIterator& operator = (const BTBreadthIterator&);
    
    // Move assignment
    BTBreadthIterator& operator = (BTBreadthIterator&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const BTBreadthIterator&) const noexcept;
    inline bool operator != (const BTBreadthIterator&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Iterator)
    
    Data& operator*() override; // (throw std::out_of_range when terminated)
    
    bool Terminated() const noexcept override; // (should not throw exceptions)
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from ForwardIterator)
    
    Data& operator++() override; // (throw std::out_of_range when terminated)
    
};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
