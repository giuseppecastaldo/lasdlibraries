#ifndef MYTEST_HPP
#define MYTEST_HPP

#include "../zlasdtest/test.hpp"
#include "../queue/queue.hpp"
#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include <random>
#include <iostream>

using namespace lasd;

/* ************************************************************************** */

std::string random_string();
int random_int();
double random_double();

void menu();
void types(int);

void populate_structure(int, int);

template <typename Data>
void stack_test(Stack<Data>& stack, Data& toPush);

template <typename Data>
void queue_test(Queue<Data>& queue, Data& toEnqueue);

/* ************************************************************************** */

#endif
