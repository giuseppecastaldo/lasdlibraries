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
    lst.InsertAtBack(3);
    lst.InsertAtBack(1);
    lst.InsertAtBack(4);
    lst.InsertAtBack(2);
    lst.InsertAtBack(5);

    BST<int> bst(lst);
    
    for(BTBreadthIterator<int> it(bst); !it.Terminated(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    
    std::cout << std::endl;
    std::cout << "Min bst " << (bst.Min()) << std::endl;
    std::cout << "Max bst " << (bst.Max()) << std::endl;

    bst.RemoveMax();
    
    for(BTInOrderIterator<int> it(bst); !it.Terminated(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << bst.Successor(4) << std::endl;
    
    return 0;
}
