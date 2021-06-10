
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix: virtual public MappableContainer<Data>, virtual public FoldableContainer<Data> {
    
private:
    
protected:
    
    unsigned long rows = 0;
    unsigned long columns = 0;
    
public:
    
    // Destructor
    virtual ~Matrix() = default ;
    
    /* ************************************************************************ */
    
    // Copy assignment
    Matrix& operator =(const Matrix&) = delete;
    
    // Move assignment
    Matrix& operator =(Matrix&&) noexcept = delete;
    
    /* ************************************************************************ */
    
    // Comparison operators
    bool operator == (const Matrix&) const noexcept = delete;
    bool operator != (const Matrix&) const noexcept = delete;
    
    /* ************************************************************************ */
    
    // Specific member functions
    
    unsigned long RowNumber() const noexcept;
    unsigned long ColumnNumber() const noexcept;
    
    virtual void RowResize(unsigned long) = 0;
    virtual void ColumnResize(unsigned long) = 0;
    
    virtual bool ExistsCell(unsigned long,unsigned long) const noexcept = 0;
    
    virtual Data& operator() (const unsigned long, const unsigned long) = 0;
    virtual const Data& operator() (const unsigned long, const unsigned long) const = 0;
    
};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
