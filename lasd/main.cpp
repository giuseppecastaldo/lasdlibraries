#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "matrix/vec/matrixvec.hpp"

#include "zlasdtest/container/container.hpp"
#include "zlasdtest/matrix/matrix.hpp"
#include "zlasdtest/iterator/iterator.hpp"


/* ************************************************************************** */

#include <iostream>
using namespace lasd;
using namespace std;

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    //    menu();
    
    unsigned int loctestnum = 0, loctesterr = 0;
    MatrixVec<string> mat(3,3);
    SetCell(loctestnum, loctesterr, mat, true, 0, 0, string("| A"));
    SetCell(loctestnum, loctesterr, mat, true, 0, 2, string("B |"));

    SetCell(loctestnum, loctesterr, mat, true, 1, 1, string(" C |"));

    SetCell(loctestnum, loctesterr, mat, true, 2, 0, string(" D"));
    SetCell(loctestnum, loctesterr, mat, true, 2, 2, string("E |"));

    MapPreOrder<string, int>(loctestnum, loctesterr, mat, true, &MapPrint<string>, 0);
    MapPostOrder<string, int>(loctestnum, loctesterr, mat, true, &MapPrint<string>, 0);

    FoldPreOrder<string, string, string>(loctestnum, loctesterr, mat, true, &FoldStringConcatenate, string(""), string("?"), string("?| AB | C | DE |"));
    FoldPostOrder<string, string, string>(loctestnum, loctesterr, mat, true, &FoldStringConcatenate, string(""), string("?"), string("?E | D C |B || A"));

    MapPreOrder<string, string>(loctestnum, loctesterr, mat, true, &MapStringNonEmptyAppend, string(" "));

    FoldPreOrder<string, string, string>(loctestnum, loctesterr, mat, true, &FoldStringConcatenate, string(""), string("?"), string("?| A B |  C |  D E | "));
    FoldPostOrder<string, string, string>(loctestnum, loctesterr, mat, true, &FoldStringConcatenate, string(""), string("?"), string("?E |  D  C | B | | A "));

    MapPreOrder<string, string>(loctestnum, loctesterr, mat, true, &MapStringNonEmptyAppend, string("X"));

    FoldPreOrder<string, string, string>(loctestnum, loctesterr, mat, true, &FoldStringConcatenate, string(""), string("?"), string("?| A XB | X C | X D XE | X"));
    FoldPostOrder<string, string, string>(loctestnum, loctesterr, mat, true, &FoldStringConcatenate, string(""), string("?"), string("?E | X D X C | XB | X| A X"));

    GetRowNumber(loctestnum, loctesterr, mat, true, 3);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 3);

    std::cout << "End of Matrix<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
    
    return 0;
}
