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
    MatrixCSR<string> mat(8,5);
    mat(0,1) = "B";
    mat(7,4) = "O";
//    mat(1,2) = "D";
//    mat(4,4) = "L";
//    mat(6,2) = "M";
    mat(6,4) = "N";
//    mat(4,1) = "E";
//    mat(1,0) = "C";
//    mat(6,1) = "I";
//    mat(7,0) = "H";
//    mat(1,4) = "G";
//    mat(0,0) = "A";
    
    //    MapPreOrder<int, int>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    
    cout << endl;
    for (int i = 0; i < mat.RowNumber(); i++) {
        for (int j = 0; j < mat.ColumnNumber(); j++) {
            if (mat.ExistsCell(i, j)) {
                cout << mat(i,j) << " ";
            } else {
                cout << "- ";
            }
            
        }
        cout << endl;
    }
    
    return 0;
}
