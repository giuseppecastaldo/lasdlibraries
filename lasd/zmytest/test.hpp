#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../zlasdtest/test.hpp"

#include "../zlasdtest/container/container.hpp"

#include "../matrix/matrix.hpp"
#include "../matrix/csr/matrixcsr.hpp"
#include "../matrix/vec/matrixvec.hpp"

#include <iostream>
#include <random>

using namespace lasd;

/* ************************************************************************** */

template <typename Data>
void print(const Data&, void*);

template <typename Data>
void multiply_2(Data&, void*);

template <typename Data>
void negative_cube(Data&, void*);

template <typename Data>
void multiply_n(const Data&, const void*, void*);

template <typename Data>
void sum_n(const Data&, const void*, void*);

template <typename Data, typename Parameter, typename Value>
void fold(FoldableContainer<Data>&, typename FoldableContainer<Data>::FoldFunctor, const Parameter&, const Value&);

template <typename Data, typename Parameter>
void map(MappableContainer<Data>&, typename MappableContainer<Data>::MapFunctor, const Parameter&);

std::string random_string(uint);
int random_int(uint, uint);
double random_double(uint, uint);
void menu();

void types(int);

void test_matrix_string(Matrix<std::string>&);
void test_matrix_double(Matrix<double>&);
void test_matrix_int(Matrix<int>&);

void populate_structure(int, int);

/* ************************************************************************** */

#endif
