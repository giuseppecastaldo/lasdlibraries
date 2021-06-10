
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixCSR: virtual public Matrix<Data>, virtual protected List<std::pair<Data, unsigned long>> {
    
private:
    
protected:
    
    using List<std::pair<Data, unsigned long>>::size;
    using typename List<std::pair<Data, unsigned long>>::Node;
    using List<std::pair<Data, unsigned long>>::Head;
    
    Vector<Node**> rowsPtr = Vector<Node**>(1);
    using Matrix<Data>::rows;
    using Matrix<Data>::columns;
    
public:
    
    // Default constructor
    MatrixCSR();
    
    /* ************************************************************************ */
    
    // Specific constructors
    MatrixCSR(const unsigned long, const unsigned long);
    
    /* ************************************************************************ */
    
    // Copy constructor
    MatrixCSR(const MatrixCSR&);
    
    // Move constructor
    MatrixCSR(MatrixCSR&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~MatrixCSR();
    
    /* ************************************************************************ */
    
    // Copy assignment
    MatrixCSR& operator = (const MatrixCSR&);
    
    // Move assignment
    MatrixCSR& operator = (MatrixCSR&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator ==(const MatrixCSR&) const noexcept;
    bool operator !=(const MatrixCSR&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Matrix)
    
    void RowResize(unsigned long) override;
    void ColumnResize(unsigned long) override;
    
    bool ExistsCell(unsigned long, unsigned long) const noexcept override;
    
    Data& operator() (const unsigned long, const unsigned long) override;
    const Data& operator() (const unsigned long, const unsigned long) const override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from MappableContainer)
    
    using typename MappableContainer<Data>::MapFunctor;
    
    void MapPreOrder(const MapFunctor, void *) override;
    void MapPostOrder(const MapFunctor, void *) override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from FoldableContainer)
    
    using typename FoldableContainer<Data>::FoldFunctor;
    
    void FoldPreOrder(const FoldFunctor, const void *, void *) const override;
    void FoldPostOrder(const FoldFunctor, const void *, void *) const override;
    
protected:
    
    // Auxiliary member functions
    void DeleteSubList(Node*&);
    void Initialize();
    void Initialize(unsigned long, unsigned long);
    void InsertInColumnAfter(unsigned long, Node**);
    
};

/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
