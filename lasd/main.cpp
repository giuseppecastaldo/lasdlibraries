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

bool eq_matr(const MatrixCSR<int>& mc, const MatrixVec<int>& mv);
const int& const_acc(const Matrix<int>& mx, int i, int j);

/* *** Random generation *** */
default_random_engine gen(3499211612);
uniform_int_distribution<unsigned int> distr0_100(0, 100);
uniform_int_distribution<unsigned int> distr0_4(0, 4);

/* ************************************************************************** */

void printMx(const Matrix<int>& m){
    for (int i = 0; i < m.RowNumber(); ++i) {
        for (int j = 0; j < m.ColumnNumber(); ++j) {
            if (m.ExistsCell(i, j))
                cout<< m(i, j) << " ";
            else
                cout<< 0 << " ";
        }
        cout<< endl;
    }
}

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2020" << std::endl;
//    lasdtest(); // To call in the menu of your library test!
    //     menu();
    
//    uint loctestnum = 0, loctesterr = 0;
//    MatrixCSR<long> mat;
//
//    Empty(loctestnum, loctesterr, mat, true);
//    Size(loctestnum, loctesterr, mat, true, 0);
//
//    GetRowNumber(loctestnum, loctesterr, mat, true, 0);
//    GetColumnNumber(loctestnum, loctesterr, mat, true, 0);
//
//    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);
//
//    GetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
//    SetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
//
//    SetRowNumber(loctestnum, loctesterr, mat, true, 6);
//    SetColumnNumber(loctestnum, loctesterr, mat, true, 7);
//
//    GetRowNumber(loctestnum, loctesterr, mat, true, 6);
//    GetColumnNumber(loctestnum, loctesterr, mat, true, 7);
//    Size(loctestnum, loctesterr, mat, true, 0);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 0, 3);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 2, 4);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 6, 3);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 6, 2);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 1, 1);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 0, 7);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 3, 5);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 6);
//
//    Size(loctestnum, loctesterr, mat, true, 8);
//
//    MatrixCSR<long> copmat(mat);
//
//    SetColumnNumber(loctestnum, loctesterr, copmat, true, 0);
//    SetRowNumber(loctestnum, loctesterr, copmat, true, 6);
//
//    GetRowNumber(loctestnum, loctesterr, copmat, true, 6);
//    GetColumnNumber(loctestnum, loctesterr, copmat, true, 0);
//
//    SetColumnNumber(loctestnum, loctesterr, mat, true, 5);
//    Size(loctestnum, loctesterr, mat, true, 6);
//    SetRowNumber(loctestnum, loctesterr, mat, true, 5);
//    Size(loctestnum, loctesterr, mat, true, 4);
//    GetRowNumber(loctestnum, loctesterr, mat, true, 5);
//    GetColumnNumber(loctestnum, loctesterr, mat, true, 5);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 8);
//
//    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 22);
//    FoldPostOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldAdd<long>, 0, 0, 22);
//
//    SetColumnNumber(loctestnum, loctesterr, mat, true, 8);
//    SetRowNumber(loctestnum, loctesterr, mat, true, 7);
//    Size(loctestnum, loctesterr, mat, true, 5);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 5, 9);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 6, 6, 10);
//    Size(loctestnum, loctesterr, mat, true, 7);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 7, 5);
//    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 6, 3);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
//    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
//
//    MatrixCSR<long> movmat(std::move(mat));
//
//    Empty(loctestnum, loctesterr, mat, true);
//    Size(loctestnum, loctesterr, mat, true, 0);
//
//    GetRowNumber(loctestnum, loctesterr, mat, true, 0);
//    GetColumnNumber(loctestnum, loctesterr, mat, true, 0);
//
//    ExistsCell(loctestnum, loctesterr, mat, false, 0, 0);
//
//    GetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
//    SetCell<long>(loctestnum, loctesterr, mat, false, 0, 0, 0);
//
//    Size(loctestnum, loctesterr, movmat, true, 9);
//
//    FoldPreOrder<long, long, long>(loctestnum, loctesterr, movmat, true, &FoldMultiply<long>, 0, 1, 777600);
//    FoldPostOrder<long, long, long>(loctestnum, loctesterr, movmat, true, &FoldMultiply<long>, 0, 1, 777600);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);
//    MapPostOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);
//
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 2, 6, 3);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 3, 3, 6);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 4, 8);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 6, 6, 10);
//    GetCell<long>(loctestnum, loctesterr, movmat, false, 7, 8, 20);
//
//    copmat = std::move(movmat);
//
//    Empty(loctestnum, loctesterr, movmat, true);
//    Size(loctestnum, loctesterr, movmat, true, 0);
//
//    GetRowNumber(loctestnum, loctesterr, movmat, true, 6);
//    GetColumnNumber(loctestnum, loctesterr, movmat, true, 0);
//
//    ExistsCell(loctestnum, loctesterr, movmat, false, 0, 0);
//
//    GetCell<long>(loctestnum, loctesterr, movmat, false, 0, 0, 0);
//    SetCell<long>(loctestnum, loctesterr, movmat, false, 0, 0, 0);
//
//    Size(loctestnum, loctesterr, copmat, true, 9);
//
//    FoldPreOrder<long, long, long>(loctestnum, loctesterr, copmat, true, &FoldMultiply<long>, 0, 1, 777600);
//    FoldPostOrder<long, long, long>(loctestnum, loctesterr, copmat, true, &FoldMultiply<long>, 0, 1, 777600);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);
//    MapPostOrder<long, long>(loctestnum, loctesterr, copmat, true, &MapPrint<long>, 0);
//
//    GetCell<long>(loctestnum, loctesterr, copmat, true, 2, 6, 3);
//    GetCell<long>(loctestnum, loctesterr, copmat, true, 3, 3, 6);
//    GetCell<long>(loctestnum, loctesterr, copmat, true, 4, 4, 8);
//    GetCell<long>(loctestnum, loctesterr, copmat, true, 6, 6, 10);
//    GetCell<long>(loctestnum, loctesterr, copmat, false, 7, 8, 20);
//
//    mat = copmat;
//
//    Empty(loctestnum, loctesterr, mat, false);
//    Size(loctestnum, loctesterr, mat, true, 9);
//
//    GetRowNumber(loctestnum, loctesterr, mat, true, 7);
//    GetColumnNumber(loctestnum, loctesterr, mat, true, 8);
//
//    FoldPreOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 777600);
//    FoldPostOrder<long, long, long>(loctestnum, loctesterr, mat, true, &FoldMultiply<long>, 0, 1, 777600);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
//    MapPostOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
//
//    GetCell<long>(loctestnum, loctesterr, mat, true, 2, 6, 3);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 6);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 8);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 6, 6, 10);
//    GetCell<long>(loctestnum, loctesterr, mat, false, 7, 8, 20);
//
//    Exists<long>(loctestnum, loctesterr, mat, true, 8);
//    Exists<long>(loctestnum, loctesterr, mat, false, 7);
//
//    mat.Clear();
//    movmat.Clear();
//
//    Empty(loctestnum, loctesterr, mat, true);
//    Size(loctestnum, loctesterr, mat, true, 0);
//
//    Empty(loctestnum, loctesterr, movmat, true);
//    Size(loctestnum, loctesterr, movmat, true, 0);
//
//    EqualMatrix(loctestnum, loctesterr, mat, movmat);
//
//    SetRowNumber(loctestnum, loctesterr, mat, true, 6);
//    SetColumnNumber(loctestnum, loctesterr, mat, true, 6);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 0, 1);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 0, 0, 1);
//    Exists<long>(loctestnum, loctesterr, mat, true, 1);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 1, 1, 2);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 1, 1, 2);
//    Exists<long>(loctestnum, loctesterr, mat, true, 2);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 2, 3);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 2, 2, 3);
//    Exists<long>(loctestnum, loctesterr, mat, true, 3);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 4);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 3, 3, 4);
//    Exists<long>(loctestnum, loctesterr, mat, true, 4);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 5);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 4, 5);
//    Exists<long>(loctestnum, loctesterr, mat, true, 5);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 5, 6);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 5, 5, 6);
//    Exists<long>(loctestnum, loctesterr, mat, true, 6);
//
//    NonEqualMatrix(loctestnum, loctesterr, mat, movmat);
//
//    SetRowNumber(loctestnum, loctesterr, movmat, true, 6);
//    SetColumnNumber(loctestnum, loctesterr, movmat, true, 6);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 0, 0, 1);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 0, 0, 1);
//    Exists<long>(loctestnum, loctesterr, movmat, true, 1);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 1, 1, 2);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 1, 1, 2);
//    Exists<long>(loctestnum, loctesterr, movmat, true, 2);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 2, 2, 3);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 2, 2, 3);
//    Exists<long>(loctestnum, loctesterr, movmat, true, 3);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 3, 3, 4);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 3, 3, 4);
//    Exists<long>(loctestnum, loctesterr, movmat, true, 4);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 4, 5);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 4, 5);
//    Exists<long>(loctestnum, loctesterr, movmat, true, 5);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 5, 6);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 5, 6);
//    Exists<long>(loctestnum, loctesterr, movmat, true, 6);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, mat, true, &MapPrint<long>, 0);
//    MapPreOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);
//
//    NonEqualMatrix(loctestnum, loctesterr, mat, movmat);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 0, 5, 1);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 0, 5, 1);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 1, 4, 2);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 1, 4, 2);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 2, 3, 3);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 2, 3, 3);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 3, 2, 4);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 3, 2, 4);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 4, 1, 5);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 4, 1, 5);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 5, 0, 6);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 5, 0, 6);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 5, 5, 6);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 5, 5, 6);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 0, 5, 1);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 0, 5, 1);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 1, 4, 2);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 1, 4, 2);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 2, 3, 3);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 2, 3, 3);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 3, 2, 4);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 3, 2, 4);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 1, 5);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 1, 5);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 5, 0, 6);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 5, 0, 6);
//
//    SetCell<long>(loctestnum, loctesterr, mat, true, 4, 5, 6);
//    GetCell<long>(loctestnum, loctesterr, mat, true, 4, 5, 6);
//
//    EqualMatrix(loctestnum, loctesterr, mat, movmat);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, movmat, true, &MapPrint<long>, 0);
//
//    MatrixCSR<long> matmov(std::move(movmat));
//
//    SetRowNumber(loctestnum, loctesterr, movmat, true, 6);
//    SetColumnNumber(loctestnum, loctesterr, movmat, true, 7);
//
//    Size(loctestnum, loctesterr, movmat, true, 0);
//
//    SetCell<long>(loctestnum, loctesterr, movmat, true, 5, 0, 6);
//    GetCell<long>(loctestnum, loctesterr, movmat, true, 5, 0, 6);
//
//    SetCell<long>(loctestnum, loctesterr, matmov, true, 5, 1, 6);
//    GetCell<long>(loctestnum, loctesterr, matmov, true, 5, 1, 6);
//
//    MapPreOrder<long, long>(loctestnum, loctesterr, matmov, true, &MapPrint<long>, 0);
//
//    Size(loctestnum, loctesterr, matmov, true, 14);
//    Size(loctestnum, loctesterr, movmat, true, 1);
//
//    mat = std::move(matmov);
//
//    SetRowNumber(loctestnum, loctesterr, matmov, true, 6);
//    SetColumnNumber(loctestnum, loctesterr, matmov, true, 7);
//
//    Size(loctestnum, loctesterr, matmov, true, 13);
//
//    SetCell<long>(loctestnum, loctesterr, matmov, true, 5, 0, 6);
//    GetCell<long>(loctestnum, loctesterr, matmov, true, 5, 0, 6);
//
//
//
//    std::cout << "End of Matrix<long> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
    MatrixVec<int> mv;
      MatrixCSR<int> mc;
      cout<< random_device{}() << "Seed "<< endl;

      for(int i=0; i<1000; i++){
          int c = distr0_4(gen);
          cout<<i<<"\t"<<c<<endl;
         if(c == 0){
             int r = distr0_100(gen);
             mv.RowResize(r);
             mc.RowResize(r);
         }
          if(c == 1){
              int t = distr0_100(gen);
              mv.ColumnResize(t);
              mc.ColumnResize(t); //Zoccola

          }
          if(c == 2 && mv.RowNumber() != 0 && mv.ColumnNumber() != 0){
              int num = distr0_100(gen);

              uniform_int_distribution<unsigned int> N(0, mv.RowNumber()-1);
              uniform_int_distribution<unsigned int> M(0, mv.ColumnNumber()-1);

              for(int k=0; k<20; k++){
                  unsigned int n = N(gen);
                  unsigned int m = M(gen);

                  mv(n, m) = num;
                  mc(n, m) = num;

                  if(mv(n, m) != mc(n, m))
                      cout << "I valori delle matrici sono diversi!!"<<endl;
                  if(const_acc(mv, n, m) != const_acc(mc, n, m))
                      cout << "I valori delle matrici (accesso costante) sono diversi!!"<<endl;
              }
          }
          if(!eq_matr(mc, mv))
              cout << "Le matrici sono diverse!!"<<endl;
      }

      cout << "Finito, cazzo.";
    
    
    return 0;
}

bool eq_matr(const MatrixCSR<int>& mc, const MatrixVec<int>& mv){
    for(int i=0; i<mc.RowNumber(); i++)
        for(int j=0; j<mc.ColumnNumber(); j++){
            if(mc.ExistsCell(i, j))
                if(mc(i, j) != mv(i, j))
                    return false;
        }

    return true;
}


const int& const_acc(const Matrix<int>& mx, int i, int j){
    return mx(i, j);
}
