#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "binarytree/binarytree.hpp"
#include "binarytree/lnk/binarytreelnk.hpp"

#include "list/list.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace lasd;

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    
    
    List<int> lst;
    lst.InsertAtBack(1);
    lst.InsertAtBack(2);
    lst.InsertAtBack(3);
    
    BinaryTreeLnk<int> bst(lst);
    
    std::cout << bst.Root().Element();
    
    return 0;
}
