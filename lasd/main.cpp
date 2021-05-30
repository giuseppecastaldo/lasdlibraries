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
    
    MatrixCSR<int> mat(8,6);
    mat(0,0) = 1;
    mat(0,1) = 2;
    mat(0,2) = 3;
    mat(2,4) = 10;
    mat(2,5) = 11;
    mat(3,2) = 6;
    mat(5,1) = 9;
    mat(5,4) = 7;
    
    for (int i = 0; i < mat.RowNumber(); i++) {
        for (int j = 0; j < mat.ColumnNumber(); j++) {
            cout << mat(i,j) << " ";
        }
        cout << endl;
    }
    
    return 0;
}
