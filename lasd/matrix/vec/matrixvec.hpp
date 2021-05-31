
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixVec : virtual public Matrix<Data>, virtual protected Vector<Data> {
    
private:
    
protected:
    
    using Vector<Data>::Elements;
    using Vector<Data>::size;
    using Matrix<Data>::rows;
    using Matrix<Data>::columns;
    
public:
    
    // Default constructor
    MatrixVec();
    
    /* ************************************************************************ */
    
    // Specific constructors
    MatrixVec(const unsigned long,const unsigned long);
    
    /* ************************************************************************ */
    
    // Copy constructor
    MatrixVec(const MatrixVec&);
    
    // Move constructor
    MatrixVec(MatrixVec&&) noexcept;
    
    /* ************************************************************************ */
    
    // Destructor
    virtual ~MatrixVec();
    
    /* ************************************************************************ */
    
    // Copy assignment
    MatrixVec& operator = (const MatrixVec&);
    
    // Move assignment
    MatrixVec& operator = (MatrixVec&&) noexcept;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator ==(const MatrixVec&) const noexcept;
    bool operator !=(const MatrixVec&) const noexcept;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Matrix)
    
    void RowResize(const unsigned long) override;
    void ColumnResize(const unsigned long) override;
    
    bool ExistsCell(unsigned long, unsigned long) const noexcept override;
    
    Data& operator() (const unsigned long, const unsigned long) override;
    const Data& operator() (const unsigned long, const unsigned long) const override;
    
    /* ************************************************************************ */
    
    // Specific member functions (inherited from Container)
    
    void Clear() override; // Override Container member
    
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
    
};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
