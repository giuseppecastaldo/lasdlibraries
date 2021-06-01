#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

#include "matrix/matrix.hpp"
#include "matrix/vec/matrixvec.hpp"
#include "matrix/csr/matrixcsr.hpp"

#include "zlasdtest/matrix/matrix.hpp"
#include "zlasdtest/container/container.hpp"

/* ************************************************************************** */

#include <iostream>
using namespace std;
using namespace lasd;

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    //     menu();
    
    uint loctestnum = 0, loctesterr = 0;
    MatrixCSR<long> mat;

    Empty(loctestnum, loctesterr, mat, true);
    Size(loctestnum, loctesterr, mat, true, 0);

    GetRowNumber(loctestnum, loctesterr, mat, true, 0);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 0);

    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);

    GetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
    SetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);

    SetRowNumber(loctestnum, loctesterr, mat, true, 6);
    SetColumnNumber(loctestnum, loctesterr, mat, true, 7);

    GetRowNumber(loctestnum, loctesterr, mat, true, 6);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 7);
    Size(loctestnum, loctesterr, mat, true, 0);

    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 0, 3);
    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 2, 4);
    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 6, 3);
    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 6, 2);
    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 1, 1);
    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 0, 7);
    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 3, 5);
    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 6);

    Size(loctestnum, loctesterr, mat, true, 8);

    MatrixCSR<long> copmat(mat);

    SetColumnNumber(loctestnum, loctesterr, copmat, true, 0);
    SetRowNumber(loctestnum, loctesterr, copmat, true, 6);

    GetRowNumber(loctestnum, loctesterr, copmat, true, 6);
    GetColumnNumber(loctestnum, loctesterr, copmat, true, 0);

    SetColumnNumber(loctestnum, loctesterr, mat, true, 5);
    Size(loctestnum, loctesterr, mat, true, 6);
    SetRowNumber(loctestnum, loctesterr, mat, true, 5);
    Size(loctestnum, loctesterr, mat, true, 4);
    GetRowNumber(loctestnum, loctesterr, mat, true, 5);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 5);

    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 8);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 22);
    FoldPostOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 22);

    SetColumnNumber(loctestnum, loctesterr, mat, true, 8);
    SetRowNumber(loctestnum, loctesterr, mat, true, 7);
    Size(loctestnum, loctesterr, mat, true, 5);

    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 5, 9);
    SetCell<long>(loctestnum, loctesterr, mat, true, 6, 6, 10);
    Size(loctestnum, loctesterr, mat, true, 7);

    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 7, 5);
    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 6, 3);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    MatrixCSR<long> movmat(std::move(mat));

    Empty(loctestnum, loctesterr, mat, true);
    Size(loctestnum, loctesterr, mat, true, 0);

    GetRowNumber(loctestnum, loctesterr, mat, true, 0);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 0);

    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);

    GetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
    SetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);

    Size(loctestnum, loctesterr, movmat, true, 9);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, movmat, true, &FoldMultiply<long>, 0, 1, 777600);
    FoldPostOrder<long, long, long>(loctestnum, loctesterr, movmat, true, &FoldMultiply<long>, 0, 1, 777600);

    MapPreOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);

    GetCell<long>(loctestnum, loctesterr, movmat, true, 2, 6, 3);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 3, 3, 6);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 4, 8);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 6, 6, 10);
    GetCell<long>(loctestnum, loctesterr, movmat, false, 7, 8, 20);

    copmat = std::move(movmat);

    Empty(loctestnum, loctesterr, movmat, true);
    Size(loctestnum, loctesterr, movmat, true, 0);

    GetRowNumber(loctestnum, loctesterr, movmat, true, 6);
    GetColumnNumber(loctestnum, loctesterr, movmat, true, 0);

    ExistsCell(loctestnum, loctesterr, movmat, false, 0, 0);

    GetCell<long>(loctestnum, loctesterr, movmat, false, 0, 0, 0);
    SetCell<long>(loctestnum, loctesterr, movmat, false, 0, 0, 0);

    Size(loctestnum, loctesterr, copmat, true, 9);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, copmat, true, &FoldMultiply<long>, 0, 1, 777600);
    FoldPostOrder<long, long, long>(loctestnum, loctesterr, copmat, true, &FoldMultiply<long>, 0, 1, 777600);

    MapPreOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);

    GetCell<long>(loctestnum, loctesterr, copmat, true, 2, 6, 3);
    GetCell<long>(loctestnum, loctesterr, copmat, true, 3, 3, 6);
    GetCell<long>(loctestnum, loctesterr, copmat, true, 4, 4, 8);
    GetCell<long>(loctestnum, loctesterr, copmat, true, 6, 6, 10);
    GetCell<long>(loctestnum, loctesterr, copmat, false, 7, 8, 20);

    mat = copmat;

    Empty(loctestnum, loctesterr, mat, false);
    Size(loctestnum, loctesterr, mat, true, 9);

    GetRowNumber(loctestnum, loctesterr, mat, true, 7);
    GetColumnNumber(loctestnum, loctesterr, mat, true, 8);

    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 777600);
    FoldPostOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 777600);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);

    GetCell<long>(loctestnum, loctesterr, mat, true, 2, 6, 3);
    GetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 6);
    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 8);
    GetCell<long>(loctestnum, loctesterr, mat, true, 6, 6, 10);
    GetCell<long>(loctestnum, loctesterr, mat, false, 7, 8, 20);

    Exists<long>(loctestnum, loctesterr, mat, true, 8);
    Exists<long>(loctestnum, loctesterr, mat, false, 7);

    mat.Clear();
    movmat.Clear();

    Empty(loctestnum, loctesterr, mat, true);
    Size(loctestnum, loctesterr, mat, true, 0);

    Empty(loctestnum, loctesterr, movmat, true);
    Size(loctestnum, loctesterr, movmat, true, 0);

    EqualMatrix(loctestnum, loctesterr, mat, movmat);

    SetRowNumber(loctestnum, loctesterr, mat, true, 6);
    SetColumnNumber(loctestnum, loctesterr, mat, true, 6);

    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 0, 1);
    GetCell<long>(loctestnum, loctesterr, mat, true, 0, 0, 1);
    Exists<long>(loctestnum, loctesterr, mat, true, 1);

    SetCell<long>(loctestnum, loctesterr, mat, true, 1, 1, 2);
    GetCell<long>(loctestnum, loctesterr, mat, true, 1, 1, 2);
    Exists<long>(loctestnum, loctesterr, mat, true, 2);

    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 2, 3);
    GetCell<long>(loctestnum, loctesterr, mat, true, 2, 2, 3);
    Exists<long>(loctestnum, loctesterr, mat, true, 3);

    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 4);
    GetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 4);
    Exists<long>(loctestnum, loctesterr, mat, true, 4);

    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 5);
    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 5);
    Exists<long>(loctestnum, loctesterr, mat, true, 5);

    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 5, 6);
    GetCell<long>(loctestnum, loctesterr, mat, true, 5, 5, 6);
    Exists<long>(loctestnum, loctesterr, mat, true, 6);

    NonEqualMatrix(loctestnum, loctesterr, mat, movmat);

    SetRowNumber(loctestnum, loctesterr, movmat, true, 6);
    SetColumnNumber(loctestnum, loctesterr, movmat, true, 6);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 0, 0, 1);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 0, 0, 1);
    Exists<long>(loctestnum, loctesterr, movmat, true, 1);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 1, 1, 2);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 1, 1, 2);
    Exists<long>(loctestnum, loctesterr, movmat, true, 2);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 2, 2, 3);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 2, 2, 3);
    Exists<long>(loctestnum, loctesterr, movmat, true, 3);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 3, 3, 4);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 3, 3, 4);
    Exists<long>(loctestnum, loctesterr, movmat, true, 4);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 4, 5);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 4, 5);
    Exists<long>(loctestnum, loctesterr, movmat, true, 5);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 5, 6);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 5, 6);
    Exists<long>(loctestnum, loctesterr, movmat, true, 6);

    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    MapPreOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);

    NonEqualMatrix(loctestnum, loctesterr, mat, movmat);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 0, 5, 1);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 0, 5, 1);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 1, 4, 2);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 1, 4, 2);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 2, 3, 3);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 2, 3, 3);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 3, 2, 4);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 3, 2, 4);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 1, 5);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 1, 5);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 5, 0, 6);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 5, 0, 6);

    SetCell<long>(loctestnum, loctesterr, movmat, true, 5, 5, 6);
    GetCell<long>(loctestnum, loctesterr, movmat, true, 5, 5, 6);

    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 5, 1);
    GetCell<long>(loctestnum, loctesterr, mat, true, 0, 5, 1);

    SetCell<long>(loctestnum, loctesterr, mat, true, 1, 4, 2);
    GetCell<long>(loctestnum, loctesterr, mat, true, 1, 4, 2);

    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 3, 3);
    GetCell<long>(loctestnum, loctesterr, mat, true, 2, 3, 3);

    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 2, 4);
    GetCell<long>(loctestnum, loctesterr, mat, true, 3, 2, 4);

    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 1, 5);
    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 1, 5);

    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 0, 6);
    GetCell<long>(loctestnum, loctesterr, mat, true, 5, 0, 6);

    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 5, 6);
    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 5, 6);

    EqualMatrix(loctestnum, loctesterr, mat, movmat);

    std::cout << "End of Matrix<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
    
    return 0;
}
