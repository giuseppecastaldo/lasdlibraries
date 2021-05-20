#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"
#include "bst/bst.hpp"

#include "zlasdtest/container/container.hpp"
#include "zlasdtest/bst/bst.hpp"

/* ************************************************************************** */

#include <iostream>
using namespace lasd;

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    
    unsigned int loctestnum = 0, loctesterr = 0;
    std::cout << std::endl << "Begin of BST<int> Test" << std::endl;
    try {
        BST<int> bst;
        Empty(loctestnum, loctesterr, bst, true);
        
        InsertC(loctestnum, loctesterr, bst, 3);
        InsertC(loctestnum, loctesterr, bst, 21);
        InsertC(loctestnum, loctesterr, bst, 1);
        InsertC(loctestnum, loctesterr, bst, 4);
        InsertC(loctestnum, loctesterr, bst, -7);
        InsertC(loctestnum, loctesterr, bst, 5);
        InsertC(loctestnum, loctesterr, bst, 22);
        InsertC(loctestnum, loctesterr, bst, 2);
        InsertC(loctestnum, loctesterr, bst, 13);
        InsertC(loctestnum, loctesterr, bst, -9);
        
        Size(loctestnum, loctesterr, bst, true, 10);
        
        Remove(loctestnum, loctesterr, bst, 22);
        Remove(loctestnum, loctesterr, bst, 4);
        Remove(loctestnum, loctesterr, bst, 5);
        
        Exists(loctestnum, loctesterr, bst, false, 22);
        Exists(loctestnum, loctesterr, bst, false, 4);
        Exists(loctestnum, loctesterr, bst, false, 5);
        Exists(loctestnum, loctesterr, bst, true, 13);
        Size(loctestnum, loctesterr, bst, true, 7);
        
        Min(loctestnum, loctesterr, bst, true, -9);
        MinNRemove(loctestnum, loctesterr, bst, true, -9);
        Exists(loctestnum, loctesterr, bst, false, -9);
        Size(loctestnum, loctesterr, bst, true, 6);
        
        Remove(loctestnum, loctesterr, bst, 22);
        Remove(loctestnum, loctesterr, bst, 4);
        Remove(loctestnum, loctesterr, bst, 5);
        Size(loctestnum, loctesterr, bst, true, 6);
        
        Predecessor(loctestnum, loctesterr, bst, true, 5, 3);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        MapBreadth(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, 5, 3);
        Size(loctestnum, loctesterr, bst, true, 5);
        Exists(loctestnum, loctesterr, bst, true, 13);
        
        PredecessorNRemove(loctestnum, loctesterr, bst, false, -9, 3);
        Size(loctestnum, loctesterr, bst, true, 5);
        
        RemovePredecessor(loctestnum, loctesterr, bst, false, -7);
        Size(loctestnum, loctesterr, bst, true, 5);
        
        bst.Clear();
        
        Size(loctestnum, loctesterr, bst, true, 0);
        
        InsertC(loctestnum, loctesterr, bst, 14);
        InsertC(loctestnum, loctesterr, bst, -70);
        InsertC(loctestnum, loctesterr, bst, -1500);
        InsertC(loctestnum, loctesterr, bst, 1);
        InsertC(loctestnum, loctesterr, bst, -6);
        InsertC(loctestnum, loctesterr, bst, -5);
        InsertC(loctestnum, loctesterr, bst, -5);
        InsertC(loctestnum, loctesterr, bst, 7);
        InsertC(loctestnum, loctesterr, bst, 13);
        InsertC(loctestnum, loctesterr, bst, 13);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        
        Size(loctestnum, loctesterr, bst, true, 8);
        
        Successor(loctestnum, loctesterr, bst, true, 13, 14);
        SuccessorNRemove(loctestnum, loctesterr, bst, true, 13, 14);
        RemoveSuccessor(loctestnum, loctesterr, bst, true, -70);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        
        Predecessor(loctestnum, loctesterr, bst, true, -70, -1500);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, -70, -1500);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, -5, -70);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, 1, -5);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, 7, 1);
        
        Size(loctestnum, loctesterr, bst, true, 2);
        
        BST<int> bst1(std::move(bst));
        Size(loctestnum, loctesterr, bst1, true, 2);
        Size(loctestnum, loctesterr, bst, true, 0);
        Empty(loctestnum, loctesterr, bst, true);
        
        MapInOrder(loctestnum, loctesterr, bst1, true, &MapPrint<int>, 0);
        RemoveMin(loctestnum, loctesterr, bst1, true);
        RemoveMax(loctestnum, loctesterr, bst1, true);
        
        Empty(loctestnum, loctesterr, bst1, true);
        bst1.Clear();
        
        EqualBST(loctestnum, loctesterr, bst, bst1);
        bst.Insert(-1);
        bst.Insert(2);
        bst.Insert(3);
        
        NonEqualBST(loctestnum, loctesterr, bst, bst1);
        RemoveMin(loctestnum, loctesterr, bst, true);
        
        InsertC(loctestnum, loctesterr, bst, -1);
        InsertC(loctestnum, loctesterr, bst, 2);
        InsertC(loctestnum, loctesterr, bst, 3);
        
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        
        RemoveMin(loctestnum, loctesterr, bst, true);
        MinNRemove(loctestnum, loctesterr, bst, true, 2);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        Size(loctestnum, loctesterr, bst, true, 1);
        
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        
        bst = bst1;
        
        EqualBST(loctestnum, loctesterr, bst, bst1);
        Empty(loctestnum, loctesterr, bst, true);
        Empty(loctestnum, loctesterr, bst1, true);
        
        InsertC(loctestnum, loctesterr, bst, 50);
        InsertC(loctestnum, loctesterr, bst, 17);
        InsertC(loctestnum, loctesterr, bst, 72);
        InsertC(loctestnum, loctesterr, bst, 12);
        InsertC(loctestnum, loctesterr, bst, 23);
        InsertC(loctestnum, loctesterr, bst, 54);
        InsertC(loctestnum, loctesterr, bst, 76);
        InsertC(loctestnum, loctesterr, bst, 9);
        InsertC(loctestnum, loctesterr, bst, 14);
        InsertC(loctestnum, loctesterr, bst, 19);
        InsertC(loctestnum, loctesterr, bst, 67);
        
        bst1 = bst;
        EqualBST(loctestnum, loctesterr, bst, bst1);
        
        Remove(loctestnum, loctesterr, bst, 14);
        Exists(loctestnum, loctesterr, bst, false, 14);
        Remove(loctestnum, loctesterr, bst, 12);
        Exists(loctestnum, loctesterr, bst, false, 12);
        Remove(loctestnum, loctesterr, bst, 54);
        Exists(loctestnum, loctesterr, bst, false, 54);
        
        Exists(loctestnum, loctesterr, bst, true, 9);
        Exists(loctestnum, loctesterr, bst, true, 67);
        
        Remove(loctestnum, loctesterr, bst, 50);
        Exists(loctestnum, loctesterr, bst, false, 50);
        
        Exists(loctestnum, loctesterr, bst, true, 17);
        Exists(loctestnum, loctesterr, bst, true, 72);
        
        Size(loctestnum, loctesterr, bst, true, 7);
        
        Remove(loctestnum, loctesterr, bst, 17);
        Remove(loctestnum, loctesterr, bst, 12);
        Remove(loctestnum, loctesterr, bst, 23);
        Remove(loctestnum, loctesterr, bst, 9);
        Remove(loctestnum, loctesterr, bst, 19);
        
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        MinNRemove(loctestnum, loctesterr, bst, true, 67);
        RemoveMin(loctestnum, loctesterr, bst, true);
        Min(loctestnum, loctesterr, bst, true, 76);
        MinNRemove(loctestnum, loctesterr, bst, true, 76);
        Empty(loctestnum, loctesterr, bst, true);
        
        MapInOrder(loctestnum, loctesterr, bst1, true, &MapPrint<int>, 0);
        
        Max(loctestnum, loctesterr, bst1, true, 76);
        RemoveMax(loctestnum, loctesterr, bst1, true);
        MaxNRemove(loctestnum, loctesterr, bst1, true, 72);
        MaxNRemove(loctestnum, loctesterr, bst1, true, 67);
        MaxNRemove(loctestnum, loctesterr, bst1, true, 54);
        RemoveMax(loctestnum, loctesterr, bst1, true);
        InsertC(loctestnum, loctesterr, bst1, 50);
        Max(loctestnum, loctesterr, bst1, true, 50);
        
        Size(loctestnum, loctesterr, bst1, true, 7);
        
    } catch(...) {
        loctestnum++; loctesterr++;
        std::cout << std::endl << "Unmanaged error! " << std::endl;
    }
    std::cout << "End of BST<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
    
    return 0;
}
