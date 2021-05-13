#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../zlasdtest/test.hpp"

#include "../list/list.hpp"

#include "../binarytree/binarytree.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"

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

void testBTInt(BinaryTree<int>&);

template <typename Data>
void nodeOptions(BinaryTree<Data>&);

template <typename Data>
void testBT(BinaryTree<Data>&);

/* ************************************************************************** */

#endif
