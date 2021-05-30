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
//        menu();
    
    unsigned int loctestnum = 0, loctesterr = 0;
    MatrixCSR<int> mat(5,5);
    mat(0,0) = 1;
    mat(0,2) = 2;
    mat(1,0) = 3;
    mat(2,2) = 4;
    mat(2,3) = 5;
    mat(4,4) = 6;
    mat(0,1) = 7;
//    mat(1,3) = 9; Scoppia
    
    
    
//    MapPreOrder<int, int>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    
    cout << endl;
    cout << endl;
    for (int i = 0; i < mat.RowNumber(); i++) {
        for (int j = 0; j < mat.ColumnNumber(); j++) {
            if (mat.ExistsCell(i, j)) {
                cout << mat(i,j) << " ";
            } else {
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
