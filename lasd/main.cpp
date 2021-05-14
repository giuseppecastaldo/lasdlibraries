#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"
#include "bst/bst.hpp"

/* ************************************************************************** */

#include <iostream>
using namespace lasd;

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
//    menu();
    
    List<int> lst;
    lst.InsertAtBack(1);
    lst.InsertAtBack(5);
    lst.InsertAtBack(4);
    lst.InsertAtBack(3);
    lst.InsertAtBack(2);
    lst.InsertAtBack(6);
    lst.InsertAtBack(8);
    lst.InsertAtBack(78);
    lst.InsertAtBack(73);
    lst.InsertAtBack(7);
    lst.InsertAtBack(9);
    
    BST<int> bst(lst);
    bst.Insert(10);
    
    for(BTInOrderIterator<int> it(bst); !it.Terminated(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << bst.Exists(4) << std::endl;
    
    return 0;
}
