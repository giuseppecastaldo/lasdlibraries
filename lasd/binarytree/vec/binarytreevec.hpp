
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : public BinaryTree<Data> { // Should extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;
  unsigned long treeHeight = 0;
  unsigned long heightVector[100];

public:

  using typename BinaryTree<Data>::Node;

  struct NodeVec : public BinaryTree<Data>::Node { // Should extend Node

  private:

    BinaryTreeVec<Data> *refTree = nullptr;

  protected:

    unsigned long index;
    unsigned long height;

    unsigned long left;
    unsigned long right;


    using BinaryTree<Data>::Node::element;
    // using BinaryTree<Data>::Node::Node;

  public:

    // Constructor
    NodeVec(Data&&, unsigned long, unsigned long, unsigned long, unsigned long, BinaryTreeVec<Data>*);
    NodeVec(const Data&, unsigned long, unsigned long, unsigned long, unsigned long, BinaryTreeVec<Data>*);

    friend class BinaryTreeVec<Data>;

    /* ********************************************************************** */

    // Specific member functions
    bool HasParent() const noexcept;
    bool HasLeftSibling() const noexcept;
    bool HasRightSibling() const noexcept;

    struct NodeVec& Parent() const; // (might throw std::out_of_range)
    struct NodeVec& LeftSibling() const; // (might throw std::out_of_range)
    struct NodeVec& RightSibling() const; // (might throw std::out_of_range)

    /* ********************************************************************** */

    // Specific member functions (inherited from Node)
    Data& Element() override; // Override Node member Mutable access to the element
    const Data& Element() const override; // Override Node member Immutable access to the element

    bool IsLeaf() const noexcept override; // Override Node member
    bool HasLeftChild() const noexcept override; // Override Node member
    bool HasRightChild() const noexcept override; // Override Node member

    NodeVec& LeftChild() const override; // Override Node member (might throw std::out_of_range)
    NodeVec& RightChild() const override; // Override Node member (might throw std::out_of_range)

    //Getters
    const unsigned long getIndex() const;
    const unsigned long getHeight() const;
    const unsigned long getLeft() const;
    const unsigned long getRight() const;
  };

protected:

  Vector<struct NodeVec*> treeVec;

  /* ************************************************************************ */

public:

  // Default constructor
  BinaryTreeVec();

  // Specific constructors
    BinaryTreeVec(const LinearContainer<Data>&);
  BinaryTreeVec(const Data&); // Construct a tree with a given root data (Copy of the value)
  BinaryTreeVec(Data&&) noexcept; // Construct a tree with a given root data (Move of the value)

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  // bool operator==(const BinaryTreeVec&) const noexcept;
  // bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)
  struct NodeVec& Root() const override; // Override Node member (might throw std::length_error)

  void AddLeftChild(struct NodeVec&, const Data&); // Add a child to a given node (Copy of the value)
  void AddLeftChild(struct NodeVec&, Data&&); // Add a child to a given node (Move of the value)
  void AddRightChild(struct NodeVec&, const Data&); // Add a child to a given node (Copy of the value)
  void AddRightChild(struct NodeVec&, Data&&); // Add a child to a given node (Move of the value)

  void RemoveLeftChild(struct NodeVec&); // Remove an entire subtree rooted in a child of a given node
  void RemoveRightChild(struct NodeVec&); // Remove an entire subtree rooted in a child of a given node

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthSearchableContainer)
  using typename BinaryTree<Data>::MapFunctor;
  void MapBreadth(MapFunctor, void*) override; // Override BreadthSearchableContainer member

  using typename BinaryTree<Data>::FoldFunctor;
  void FoldBreadth(FoldFunctor, const void*, void*) const override; // Override BreadthSearchableContainer member

protected:

  // Accessory functions
  void Expand();
  void Reduce();

  void removeSubtree(struct NodeVec&);

// public:
//   void stampaVecAltezza(){
//     std::cout << std::endl << std::endl;
//     std::cout << "Tree height: " << treeHeight << std::endl;
//       for(int i = 0; i < 30; i++)
//         std::cout << heightVector[i] << " ";
//
//     std::cout << std::endl;
//
//     std::cout << "Dimensione Vettore: " << treeVec.Size() << std::endl;
//     std::cout << std::endl << std::endl;
//     }
//
  // void stampaVettore(){
  //   for(int i=0; i< treeVec.Size(); i++)
  //     if(treeVec[i].valid)
  //       std::cout << treeVec[i].Element() << " ";
  //     else
  //       std::cout << "0" << " ";
  //
  //   std::cout << std::endl;
  // }
  //
  // void stampaAltezza(){
  //   std::cout << treeHeight << std::endl;
  // }

};

/* ************************************************************************** */

#include "binarytreevec.cpp"

}

#endif

