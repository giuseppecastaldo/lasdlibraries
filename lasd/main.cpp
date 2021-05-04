#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "list/list.hpp"

#include "queue/queue.hpp"
#include "queue/lst/queuelst.hpp"

#include "binarytree/binarytree.hpp"
#include "binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    
    lasd::List<int> lst;
    lst.InsertAtBack(1);
    lst.InsertAtBack(2);
    lst.InsertAtBack(3);
    
    lasd::QueueLst<int> q(lst);
    std::cout << q.Head() << std::endl;
    
    lasd::BinaryTreeLnk<int> bst(lst);

    return 0;
}
