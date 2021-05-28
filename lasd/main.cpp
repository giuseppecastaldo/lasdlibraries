#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "matrix/vec/matrixvec.hpp"
#include "matrix/matrix.hpp"

#include "zlasdtest/container/container.hpp"
#include "zlasdtest/matrix/matrix.hpp"
#include "zlasdtest/iterator/iterator.hpp"


/* ************************************************************************** */

#include <iostream>
using namespace lasd;
using namespace std;

/* ************************************************************************** */

void testString(MatrixVec<string> mat, unsigned int loctestnum, unsigned loctesterr) {
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
}

void testInt(MatrixVec<long> mat, unsigned int loctestnum, unsigned loctesterr) {
    Empty(loctestnum, loctesterr, mat, true);
    Size(loctestnum, loctesterr, mat, true, 0);

    GetRowNumber(loctestnum, loctesterr, mat, true, 0);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 0);

    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);

    GetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
    SetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);

    SetRowNumber(loctestnum, loctesterr, mat, true, 1);
    SetColumnNumber(loctestnum, loctesterr, mat, true, 1);

    mat.Clear();

    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);

    SetRowNumber(loctestnum, loctesterr, mat, true, 5);
    GetRowNumber(loctestnum, loctesterr, mat, true, 5);
    SetColumnNumber(loctestnum, loctesterr, mat, true, 4);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 4);

    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 1, 1);
    SetCell<long>(loctestnum, loctesterr, mat, true, 1, 0, 2);

    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 1, 3);

    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 3, 4);
    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 3, 5);

    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 1, 6);
    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 3, 7);

    MatrixVec<long> copmat(mat);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPreOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 28);

    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapIncrement<long>, 0);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 40320);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapDecrement<long>, 0);

    SetColumnNumber(loctestnum, loctesterr, mat, true, 5);

    SetCell<long>(loctestnum, loctesterr, mat, true, 1, 4, 8);
    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 4, 9);

    SetColumnNumber(loctestnum, loctesterr, mat, true, 3);
    SetColumnNumber(loctestnum, loctesterr, mat, true, 4);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 12);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapIncrement<long>, 0);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 168);

    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapDecrement<long>, 0);

    SetRowNumber(loctestnum, loctesterr, mat, true, 4);
    SetRowNumber(loctestnum, loctesterr, mat, true, 5);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 6);

    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapIncrement<long>, 0);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 24);

    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapDecrement<long>, 0);

    NonEqualMatrix(loctestnum, loctesterr, mat, copmat);

    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 1, 6);
    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 3, 7);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 19);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapIncrement<long>, 0);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 1344);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapDecrement<long>, 0);

    NonEqualMatrix(loctestnum, loctesterr, mat, copmat);

    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 3, 4);
    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 3, 5);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 28);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapIncrement<long>, 0);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 40320);

    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapDecrement<long>, 0);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPreOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);

    EqualMatrix(loctestnum, loctesterr, mat, copmat);

    MatrixVec<long> movmat(std::move(mat));

    GetRowNumber(loctestnum, loctesterr, mat, true, 0);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 0);

    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);

    Exists<long>(loctestnum, loctesterr, movmat, false, 8);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 2, 8);

    MapPreOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, movmat, true, &FoldAdd<long>, 0, 0, 36);

    Exists<long>(loctestnum, loctesterr, movmat, true, 8);

    SetRowNumber(loctestnum, loctesterr, movmat, true, 4);
    MapPostOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);

    movmat.Clear();

    GetRowNumber(loctestnum, loctesterr, movmat, true, 0);
    GetColumnNumber(loctestnum, loctesterr, movmat, true, 0);

    mat = copmat;
    copmat.Clear();

    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    SetRowNumber(loctestnum, loctesterr, mat, true, 3);
    SetColumnNumber(loctestnum, loctesterr, mat, true, 3);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 6);
    
    std::cout << "End of Matrix<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
}

void testDouble(MatrixVec<double> mat, unsigned int loctestnum, unsigned loctesterr) {
    SetCell(loctestnum, loctesterr, mat, true, 0, 0, 3.0);
    SetCell(loctestnum, loctesterr, mat, true, 1, 1, 2.1);
    SetCell(loctestnum, loctesterr, mat, true, 2, 2, 1.2);

    SetCell(loctestnum, loctesterr, mat, true, 3, 0, 0.3);
    SetCell(loctestnum, loctesterr, mat, true, 2, 1, 1.2);
    SetCell(loctestnum, loctesterr, mat, true, 1, 2, 2.1);

    SetCell(loctestnum, loctesterr, mat, true, 0, 2, 0.3);
    SetCell(loctestnum, loctesterr, mat, true, 1, 1, 1.2);
    SetCell(loctestnum, loctesterr, mat, true, 2, 0, 2.1);

    SetCell(loctestnum, loctesterr, mat, true, 3, 2, 3.0);
    SetCell(loctestnum, loctesterr, mat, true, 2, 1, 2.1);
    SetCell(loctestnum, loctesterr, mat, true, 1, 0, 1.2);

    MatrixVec<double> newmat(5, 10);
    newmat = std::move(mat);

    GetRowNumber(loctestnum, loctesterr, mat, true, 5);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 10);

    GetCell(loctestnum, loctesterr, mat, false, 5, 10, 0.0);

    Exists<double>(loctestnum, loctesterr, mat, false, 3.0);

    GetCell(loctestnum, loctesterr, newmat, true, 1, 1, 1.2);
    GetCell(loctestnum, loctesterr, newmat, true, 2, 1, 2.1);

    GetRowNumber(loctestnum, loctesterr, newmat, true, 4);
    GetColumnNumber(loctestnum, loctesterr, newmat, true, 3);
    
    
    std::cout << "End of Matrix<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
}


int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    //    menu();
    
    unsigned int loctestnum = 0, loctesterr = 0;
    
    MatrixVec<long> mat1;
    testInt(mat1, loctestnum, loctesterr);
    std::cout << std::endl;
    
    MatrixVec<string> mat2(3,3);
    testString(mat2, loctestnum, loctesterr);
    std::cout << std::endl;
    
    MatrixVec<double> mat3(4,3);
    testDouble(mat3, loctestnum, loctesterr);
    std::cout << std::endl;
    
    return 0;
}
