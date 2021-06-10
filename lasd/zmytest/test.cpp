#include "test.hpp"

template <typename Data>
void print(const Data& dat, void* _) {
    std::cout << dat << " ";
}

template <typename Data>
void concat_head_strings(Data& dat, void* par) {
    static_cast<std::string&>(dat).insert(0, *(std::string*) par);
}

template <typename Data>
void multiply_2(Data& dat, void* par) {
    dat = dat * 2;
}

template <typename Data>
void negative_cube(Data& dat, void* par) {
    dat = (-1) * std::pow((double) dat, 3);
}

template <typename Data>
void multiply_n(const Data& dat, const void* par, void* acc) {
    if (dat < (*(Data*)par)) {
        *((Data*) acc) *= dat;
    }
}

template <typename Data>
void concat_strings_n(const Data& dat, const void* par, void* acc) {
    if (static_cast<const std::string&>(dat).size() <= *((unsigned long*) par)) {
        *((std::string*) acc) += dat;
    }
}

template <typename Data>
void sum_n(const Data& dat, const void* par, void* acc) {
    if (dat > (*(Data*)par)) {
        *((Data*) acc) += dat;
    }
}

template <typename Data, typename Parameter, typename Value>
void fold(FoldableContainer<Data> &con, typename FoldableContainer<Data>::FoldFunctor fun, const Parameter& inipar, const Value& inival) {
    Parameter par = {inipar};
    Value val = inival;
    
    con.FoldPreOrder(fun, &par, &val);
    std::cout << val;
}

template <typename Data, typename Parameter>
void map(MappableContainer<Data> &con, typename MappableContainer<Data>::MapFunctor fun, const Parameter& inipar) {
    Parameter par = {inipar};
    con.MapPreOrder(fun, &par);
}

std::string random_string(uint length) {
    char letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    std::string ran = "";
    
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,25);
    for(int i = 0; i < length; i++) {
        ran = ran + letters[dist(gen)];
    }
    
    return ran;
}

int random_int(uint start, uint end) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(start,end);
    
    return dist(gen);
}

double random_double(uint start, uint end) {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(start,end);
    
    return std::ceil(dist(gen) * 100.0) / 100.0;
}

void menu() {
    int choice = 0;
    
    do {
        std::cout << "1. MatrixVec" << std::endl;
        std::cout << "2. MatrixCSR" << std::endl;
        std::cout << "3. Test docente" << std::endl;
        std::cout << "4. Esci" << std::endl;
        
        std::cin >> choice;
        switch(choice) {
            case 1:
                types(1);
                break;
            case 2:
                types(2);
                break;
            case 3:
                lasdtest();
                menu();
                break;
            case 4:
                exit(0);
                break;
            default:
                std::cout << "Scelta non valida." << std::endl;
        }
    } while(choice > 4);
}

void types(int structure) {
    int choice = 0;
    
    do {
        std::cout << "1. Stringhe" << std::endl;
        std::cout << "2. Numeri interi" << std::endl;
        std::cout << "3. Numeri con virgola" << std::endl;
        std::cout << "4. Indietro" << std::endl;
        
        std::cin >> choice;
        switch(choice) {
            case 1:
                populate_structure(structure, 1);
                break;
            case 2:
                populate_structure(structure, 2);
                break;
            case 3:
                populate_structure(structure, 3);
                break;
            case 4:
                menu();
            default:
                std::cout << "Scelta non valida." << std::endl;
        }
    } while(choice > 4);
}

void populate_structure(int structure, int type) {
    int rows = 0;
    int cols = 0;
    
    std::cout << "Quante righe? "; std::cin >> rows;
    std::cout << "Quante colonne? "; std::cin >> cols;
    
    switch (structure) {
            //MatrixVec
        case 1: {
            switch (type) {
                    // String
                case 1: {
                    MatrixVec<std::string> mat(rows, cols);
                    
                    int el = random_int(1, rows * cols);
                    for (uint i = 0; i < el; ++i) {
                        mat(random_int(0, rows - 1), random_int(0, cols - 1)) = random_string(random_int(1, 2));
                    }
                    
                    test_matrix_string(mat);
                    
                    break;
                }
                    // Int
                case 2: {
                    MatrixVec<int> mat(rows, cols);
                    
                    int el = random_int(1, rows * cols);
                    for (uint i = 0; i < el; ++i) {
                        mat(random_int(0, rows - 1), random_int(0, cols - 1)) = random_int(0, 9);
                    }
                    
                    test_matrix_int(mat);
                    
                    break;
                }
                    // Double
                case 3: {
                    MatrixVec<double> mat(rows, cols);
                    
                    int el = random_int(1, rows * cols);
                    for (uint i = 0; i < el; ++i) {
                        mat(random_int(0, rows - 1), random_int(0, cols - 1)) = random_double(0, 9);
                    }
                    
                    test_matrix_double(mat);
                    
                    break;
                }
                default:
                    break;
            }
            break;
        }
            //MatrixCSR
        case 2: {
            switch (type) {
                    // String
                case 1: {
                    MatrixCSR<std::string> mat(rows, cols);
                    
                    int el = random_int(rows, rows * cols);
                    for (uint i = 0; i < el; ++i) {
                        mat(random_int(0, rows - 1), random_int(0, cols - 1)) = random_string(random_int(1, 2));
                    }
                    
                    test_matrix_string(mat);
                    
                    break;
                }
                    // Int
                case 2: {
                    MatrixCSR<int> mat(rows, cols);
                    
                    int el = random_int(rows, rows * cols);
                    for (uint i = 0; i < el; ++i) {
                        mat(random_int(0, rows - 1), random_int(0, cols - 1)) = random_int(0, 9);
                    }
                    
                    test_matrix_int(mat);
                    
                    break;
                }
                    // Double
                case 3: {
                    MatrixCSR<double> mat(rows, cols);
                    
                    int el = random_int(rows, rows * cols);
                    for (uint i = 0; i < el; ++i) {
                        mat(random_int(0, rows - 1), random_int(0, cols - 1)) = random_double(0, 9);
                    }
                    
                    test_matrix_double(mat);
                    
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }
}

void test_matrix_string(Matrix<std::string>& mat) {
    std::cout << "Stampa in order: "; mat.MapPreOrder(&print<std::string>, 0); std::cout << std::endl;
    std::cout << "Stampa in pre order: "; mat.MapPostOrder(&print<std::string>, 0); std::cout << std::endl;
    
    std::string in;
    std::cout << "Controlla esistenza valore: "; std::cin >> in;
    
    if (mat.Exists(in)) {
        std::cout << "Il valore esiste" << std::endl;
    } else {
        std::cout << "Il valore NON esiste" << std::endl;
    }
    
    int input; std::string acc = "";
    std::cout << "Inserisci intero: "; std::cin >> input;
    std::cout << "Concatenazione di stringhe con lunghezza minori di questo: "; fold(mat, &concat_strings_n<std::string>, input, acc); std::cout << std::endl;
    
    std::string to_concat = "";
    std::cout << "Inserisci stringa: "; std::cin >> to_concat;
    std::cout << "Concatenazione in testa..."; map(mat, &concat_head_strings<std::string>, to_concat); std::cout << std::endl;
    
    std::cout << "Ecco la nuova struttura: "; mat.MapPreOrder(&print<std::string>, 0); std::cout << std::endl;
    
    menu();
}

void test_matrix_int(Matrix<int>& mat) {
    std::cout << "Stampa in order: "; mat.MapPreOrder(&print<int>, 0); std::cout << std::endl;
    std::cout << "Stampa in pre order: "; mat.MapPostOrder(&print<int>, 0); std::cout << std::endl;
    
    int in;
    std::cout << "Controlla esistenza valore: "; std::cin >> in;
    
    if (mat.Exists(in)) {
        std::cout << "Il valore esiste" << std::endl;
    } else {
        std::cout << "Il valore NON esiste" << std::endl;
    }
    
    int input; int acc = 1;
    std::cout << "Inserisci intero: "; std::cin >> input;
    std::cout << "Eseguo moltiplicazione di interi minori di questo: "; fold(mat, &multiply_n<int>, input, acc); std::cout << std::endl;
    std::cout << "Moltiplico tutti gli elementi per 3..."; map(mat, &multiply_2<int>, 0); std::cout << std::endl;
    std::cout << "Ecco la nuova struttura: "; mat.MapPreOrder(&print<int>, 0); std::cout << std::endl;
        
    menu();
}

void test_matrix_double(Matrix<double>& mat) {
    std::cout << "Stampa in order: "; mat.MapPreOrder(&print<double>, 0); std::cout << std::endl;
    std::cout << "Stampa in pre order: "; mat.MapPostOrder(&print<double>, 0); std::cout << std::endl;
    
    double in;
    std::cout << "Controlla esistenza valore: "; std::cin >> in;
    
    if (mat.Exists(in)) {
        std::cout << "Il valore esiste" << std::endl;
    } else {
        std::cout << "Il valore NON esiste" << std::endl;
    }
    
    int input; double acc = 0;
    std::cout << "Inserisci intero: "; std::cin >> input;
    std::cout << "Eseguo somma di float maggiori di questo: "; fold(mat, &sum_n<double>, input, acc); std::cout << std::endl;
    std::cout << "Eseguo il cubo di ogni elemento..."; map(mat, &negative_cube<double>, 0); std::cout << std::endl;
    std::cout << "Ecco la nuova struttura: "; mat.MapPreOrder(&print<double>, 0); std::cout << std::endl;
        
    menu();
}
