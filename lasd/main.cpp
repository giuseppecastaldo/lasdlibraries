#include "zlasdtest/test.hpp"

#include "zlasdtest/matrix/matrix.hpp"
#include "zlasdtest/container/container.hpp"

#include "zmytest/test.hpp"

#include "matrixcsr.hpp"
#include "matrixvec.hpp"
#include "matrix.hpp"
#include "container.hpp"

/* ************************************************************************** */

#include <iostream>
using namespace lasd;

/* ************************************************************************** */

template <typename T>
void PrintMatrix(const Matrix<T>& mat) {
    std::cout << std::endl;
    for (unsigned long i = 0; i < mat.RowNumber(); ++i) {
        for (unsigned long j = 0; j < mat.ColumnNumber(); ++j) {
            if (mat.ExistsCell(i, j)) {
                std::cout << mat(i,j) << " ";
            } else {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
    //  lasdtest(); // To call in the menu of your library test!
    
    unsigned int loctestnum = 0, loctesterr = 0;
    
    MatrixCSR<long> mat1;
    MatrixCSR<long> mat2;
    
    SetRowNumber(loctestnum, loctesterr, mat1, true, 5);
    SetColumnNumber(loctestnum, loctesterr, mat1, true, 5);
    
    SetRowNumber(loctestnum, loctesterr, mat2, true, 5);
    SetColumnNumber(loctestnum, loctesterr, mat2, true, 5);
    
    SetCell<long>(loctestnum, loctesterr, mat1, true, 0, 0, 1);
    SetCell<long>(loctestnum, loctesterr, mat1, true, 0, 1, 2);
    
    SetCell<long>(loctestnum, loctesterr, mat2, true, 0, 0, 1);
    SetCell<long>(loctestnum, loctesterr, mat2, true, 1, 1, 2);
    
    PrintMatrix(mat1);
    PrintMatrix(mat2);
    
    NonEqualMatrix(loctestnum, loctesterr, mat1, mat2);
    
    std::cout << "End of Matrix<long> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
    
    return 0;
}
