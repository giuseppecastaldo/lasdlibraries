#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../zlasdtest/test.hpp"

#include "../list/list.hpp"

#include "../bst/bst.hpp"

#include "../zlasdtest/container/container.hpp"
#include "../zlasdtest/bst/bst.hpp"

#include <iostream>
#include <random>

using namespace lasd;
/* ************************************************************************** */

template <typename Data>
void print(const Data&, void*);

template <typename Data>
void multiply_3(Data&, void*);

template <typename Data>
void multiply_n(const Data&, const void*, void*);

template <typename Data, typename Parameter, typename Value>
void fold(FoldableContainer<Data>&, typename FoldableContainer<Data>::FoldFunctor, const Parameter&, const Value&);

template <typename Data, typename Parameter>
void map(MappableContainer<Data>&, typename MappableContainer<Data>::MapFunctor, const Parameter&);

std::string random_string();
int random_int();
double random_double();
void menu();

void types(int);
void populate_structure(int, int);

void testBSTInt(BinaryTree<int>&);

void personal_test();

template <typename Data>
void testBST(BinaryTree<Data>&);

/* ************************************************************************** */

#endif
