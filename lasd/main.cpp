#include "zlasdtest/test.hpp"
//#include "zmytest/test.hpp"
#include <random>
#define seed 3499211612

/* ************************************************************************** */

#include <iostream>
#include "matrix/csr/matrixcsr.hpp"
#include "matrix/vec/matrixvec.hpp"

using namespace std;
using namespace lasd;

enum Action{
    RowResize,
    ColResize,
    InsertValue,
    TestCopy,
    TestMove
};

bool eq_matr(const MatrixCSR<int>& mc, const MatrixVec<int>& mv);
const int& const_acc(const Matrix<int>& mx, unsigned int i, unsigned int j);

/* *** Random generation *** */
default_random_engine gen(seed);
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

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
//  lasdtest(); // To call in the menu of your library test!

  MatrixVec<int> mv;
  MatrixCSR<int> mc;
  int valMatr[100][100];
  unsigned long err = 0, test = 0;

  cout<< "Seed: "<< seed << endl;

  for(int i=1; i <= 1000; i++){
      auto action = static_cast<Action>(distr0_4(gen));
      cout<< "["<< i << "] ";
      if(action == RowResize){
          unsigned int r = distr0_100(gen);
          try {
              cout << "Set row to " << r;
              mv.RowResize(r);
              mc.RowResize(r);
              cout << " ok" << endl;
          } catch (...){
              cerr<< "Exception in RowResize" << endl;
              err++;
          }
          test++;
      }
      if(action == ColResize){
          unsigned int c = distr0_100(gen);
          try {
              cout << "Set col to " << c;
              mv.ColumnResize(c);
              mc.ColumnResize(c);
              cout << " ok" << endl;
          } catch (...){
              cerr<< "Exception in ColResize" << endl;
              err++;
          }
          test++;
      }
      if(action == InsertValue && mc.RowNumber() != 0 && mc.ColumnNumber() != 0){
          uniform_int_distribution<unsigned int> N(0, mc.RowNumber()-1);
          uniform_int_distribution<unsigned int> M(0, mc.ColumnNumber()-1);

          unsigned int nElements = distr0_100(gen)/3;
          cout<< "Insert " << nElements << " values" << endl;
          for(int k = 0; k < nElements; k++){
              try {
                  int num = distr0_100(gen);
                  unsigned int n = N(gen);
                  unsigned int m = M(gen);

                  cout << "\tInsert " << num << " in (" << n << ", " << m << ")";
                  mv(n, m) = num;
                  mc(n, m) = num;
                  valMatr[n][m] = num;
                  cout << " ok" << endl;

                  test++;
                  if (mv(n, m) != mc(n, m)) {
                      cerr << "ERRORE! I valori delle matrici sono diversi!! (mv(n, m) != mc(n, m))" << endl;
                      err++;
                  }test++;
                  if (mc(n, m) != valMatr[n][m]) {
                      cerr << "ERRORE! I valori delle matrici sono diversi!! (mc(n, m) != valMatr[n][m])" << endl;
                      err++;
                  }test++;
                  if (mv(n, m) != valMatr[n][m]) {
                      cerr << "ERRORE! I valori delle matrici sono diversi!! (mv(n, m) != valMatr[n][m])" << endl;
                      err++;
                  }test++;
                  if (const_acc(mv, n, m) != const_acc(mc, n, m)) {
                      cerr<< "ERRORE! I valori delle matrici (accesso costante) sono diversi!! const_acc(mv, n, m) != const_acc(mc, n, m)"<< endl;
                      err++;
                  }
              } catch (...){
                  cerr<< "Exception in Insert" << endl;
                  err++;
              }
          }
          cout<< "ok" << endl;
      }
      if(action == TestCopy){
          cout<< "Test Copy";
          try {
              MatrixVec<int> mv_copy(mv);
              MatrixCSR<int> mc_copy(mc);

              if (mc.RowNumber() != 0 && mc.ColumnNumber() != 0) {
                  uniform_int_distribution<unsigned int> N(0, mc.RowNumber() - 1);
                  uniform_int_distribution<unsigned int> M(0, mc.ColumnNumber() - 1);
                  unsigned int nElements = distr0_100(gen)/3;
                  for (int k = 0; k < nElements; k++) {
                      int num = distr0_100(gen);
                      unsigned int n = N(gen);
                      unsigned int m = M(gen);
                      mv(n, m) = num;
                      mc(n, m) = num;

                      mv_copy(n, m) = num;
                      mc_copy(n, m) = num;
                  }
              }


              test++;
              if (!eq_matr(mc_copy, mv_copy)) {
                  err++;
                  cerr << "Le matrici copiate col costruttore sono diverse!!(mc_copy, mv_copy)" << endl;
              } test++;
              if (mv != mv_copy) {
                  err++;
                  cerr << "Le matrici copiate col costruttore sono diverse!!(mv != mv_copy)" << endl;
              } test++;
              if (mc != mc_copy) {
                  err++;
                  cerr << "Le matrici copiate col costruttore sono diverse!!(mc != mc_copy)" << endl;
              }
              mv_copy = mv;
              mc_copy = mc;

              test++;
              if (!eq_matr(mc_copy, mv_copy)) {
                  cerr << "Le matrici copiate per assegnazione sono diverse!!" << endl;
              }
              cout << " ok" << endl;
          } catch (...){
              cerr<< "Exception in Copy" << endl;
              err++;
          }
      }
      if(action == TestMove){
          cout<< "Test Move";
          try {
              MatrixVec<int> mv_copy(mv);
              MatrixCSR<int> mc_copy(mc);

              MatrixVec<int> mv_move(move(mv_copy));
              MatrixCSR<int> mc_move(move(mc_copy));
              test++;
              if (!eq_matr(mc_move, mv_move)) {
                  err++;
                  cout << "Le matrici spostate col costruttore sono diverse!!" << endl;
              }test++;
              if (mv != mv_move) {
                  err++;
                  cout << "Le matrici spostate col costruttore sono diverse!!" << endl;
              }test++;
              if (mc != mc_move) {
                  err++;
                  cout << "Le matrici spostate col costruttore sono diverse!!" << endl;
              }
              mv = move(mv_move);
              mc = move(mc_move);
              test++;
              if (!eq_matr(mc, mv)) {
                  err++;
                  cout << "Le matrici spostate per assegnazione sono diverse!!" << endl;
              }
              cout << " ok" << endl;


          test++;
          if (mv.RowNumber() != mc.RowNumber()) {
              err++;
              cerr << "ERRORE! Il numero di righe delle matrici sono diversi!!" << "mc: " << mc.RowNumber() << " mv: "
                   << mv.RowNumber() << endl;
          }test++;
          if (mv.ColumnNumber() != mc.ColumnNumber()) {
              err++;
              cerr << "ERRORE! Il numero di colonne delle matrici sono diversi!! " << "mc: " << mc.ColumnNumber()
                   << " mv: " << mv.ColumnNumber() << endl;
          }test++;
          if (!eq_matr(mc, mv)) {
              err++;
              cerr << "ERRORE! Le matrici sono diverse!!" << endl;
          }
          }catch (...){
              cerr<< "Exception in Move" << endl;
              err++;
          }
      }
      test++;
  }

  cout << "End. errors/tests: "<< err << "/" << test << endl;
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


const int& const_acc(const Matrix<int>& mx, unsigned int i, unsigned int j){
    return mx(i, j);
}
