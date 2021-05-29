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
    //    menu();
    
    unsigned int loctestnum = 0, loctesterr = 0;
    
    MatrixCSR<long> mat(4,3);
    mat(0,0) = 1;
    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
    
    cout << mat.RowNumber() << endl ;
    cout << mat.ColumnNumber() << endl;
    
    
    return 0;
}
