
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix:  virtual public MappableContainer<Data>,
               virtual public FoldableContainer<Data> { // Must extend MappableContainer<Data> and FoldableContainer<Data>

private:

  // ...

protected:

  unsigned long rows = 0;
  unsigned long columns = 0;

public:

  // Destructor
  virtual ~Matrix() = default ;

  /* ************************************************************************ */

  // Copy assignment
  Matrix& operator =(const Matrix&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Matrix& operator =(Matrix&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator == (const Matrix&) const noexcept = delete;
  bool operator != (const Matrix&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  unsigned long RowNumber() const noexcept;
  unsigned long ColumnNumber() const noexcept;

  virtual void RowResize(const unsigned long) = 0;
  virtual void ColumnResize(const unsigned long) = 0;

  virtual bool ExistsCell(unsigned long,unsigned long) const noexcept = 0;

  
  virtual Data& operator() (const unsigned long, const unsigned long) = 0; // Mutable access to the element (concrete function should throw exceptions only when out of range)
  virtual const Data& operator() (const unsigned long, const unsigned long) const = 0; // Immutable access to the element (concrete function should throw exceptions when not present)

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
