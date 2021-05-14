#include "test.hpp"

template <typename Data>
void print(const Data& dat, void* _) {
  std::cout << dat << " ";
}

template <typename Data>
void multiply_3(Data& dat, void* par) {
    dat = dat * 3;
}

template <typename Data>
void multiply_n(const Data& dat, const void* par, void* acc) {
    if (dat < (*(Data*)par)) {
        *((Data*) acc) *= dat;
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

std::string random_string() {
    char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string ran = "";
    
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(0,25);
    for(int i = 0; i < dist(gen); i++) {
        ran = ran + letters[dist(gen)];
    }
    
    return ran;
}

int random_int() {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(1,100);
    
    return dist(gen);
}

double random_double() {
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<double> dist(1,100);
    
    return std::ceil(dist(gen) * 100.0) / 100.0;
}

void menu() {
    int choice = 0;
    
    do {
        std::cout << "1. Albero implementato con vettore" << std::endl;
        std::cout << "2. Albero implementato con lista" << std::endl;
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
    int n = 0;
    std::cout << "Quanti elementi vuoi inserire nella tua struttura? "; std::cin >> n;
    
    switch (structure) {
        case 1: {
            switch (type) {
                case 1: {
                    List<std::string> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_string());
                    }
                    
                    BinaryTreeVec<std::string> btv(lst);
                    testBT(btv);
                    break;
                }
                case 2: {
                    List<int> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_int());
                    }
                    
                    BinaryTreeVec<int> btv(lst);
                    testBTInt(btv);
                    break;
                }
                case 3: {
                    List<double> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_double());
                    }
                    
                    BinaryTreeVec<double> btv(lst);
                    testBT(btv);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2: {
            switch (type) {
                case 1: {
                    List<std::string> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_string());
                    }
                    
                    BinaryTreeLnk<std::string> btl(lst);
                    testBT(btl);
                    break;
                }
                case 2: {
                    List<int> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_int());
                    }
                    
                    BinaryTreeLnk<int> btl(lst);
                    testBTInt(btl);
                    break;
                }
                case 3: {
                    List<double> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_double());
                    }
                    
                    BinaryTreeLnk<double> btl(lst);
                    testBT(btl);
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

void testBTInt(BinaryTree<int>& bt) {
    std::cout << "Stampa in order: "; bt.MapInOrder(&print<int>, 0); std::cout << std::endl;
    std::cout << "Stampa in post order: "; bt.MapPostOrder(&print<int>, 0); std::cout << std::endl;
    std::cout << "Stampa in ampiezza: "; bt.MapBreadth(&print<int>, 0); std::cout << std::endl;
    std::cout << "Stampa in pre order: "; bt.MapPreOrder(&print<int>, 0); std::cout << std::endl;
    
    int in;
    std::cout << "Controlla esistenza valore: "; std::cin >> in;
    
    if (bt.Exists(in)) {
        std::cout << "Il valore esiste" << std::endl;
    } else {
        std::cout << "Il valore NON esiste" << std::endl;
    }
    
    int input; unsigned long acc = 1;
    std::cout << "Inserisci intero: "; std::cin >> input;
    std::cout << "Eseguo moltiplicazione di interi minori di questo: "; fold(bt, &multiply_n<int>, input, acc); std::cout << std::endl;
    std::cout << "Moltiplico tutti gli elementi per 3..."; map(bt, &multiply_3<int>, 0); std::cout << std::endl;
    std::cout << "Ecco la nuova struttura: "; bt.MapBreadth(&print<int>, 0); std::cout << std::endl;
    
    nodeOptions(bt);
}

template <typename Data>
void testBT(BinaryTree<Data>& bt) {
    std::cout << "Stampa in order: "; bt.MapInOrder(&print<Data>, 0); std::cout << std::endl;
    std::cout << "Stampa in post order: "; bt.MapPostOrder(&print<Data>, 0); std::cout << std::endl;
    std::cout << "Stampa in ampiezza: "; bt.MapBreadth(&print<Data>, 0); std::cout << std::endl;
    std::cout << "Stampa in pre order: "; bt.MapPreOrder(&print<Data>, 0); std::cout << std::endl;

    Data in;
    std::cout << "Controlla esistenza valore: "; std::cin >> in;

    if (bt.Exists(in)) {
        std::cout << "Il valore esiste" << std::endl;
    } else {
        std::cout << "Il valore NON esiste" << std::endl;
    }

    nodeOptions(bt);
}

template <typename Data>
void nodeOptions(BinaryTree<Data>& bt) {
    int choice = 0;
    BTBreadthIterator<Data> it(bt);
    Data value;

    do {
        std::cout << "\n1. Modifica nodo" << std::endl;
        std::cout << "2. Visualizza elemento" << std::endl;
        std::cout << "3. Procedi in breadth" << std::endl;

        std::cin >> choice;
        switch(choice) {
            case 1:
                std::cout << "Inserire valore: "; std::cin >> value;
                std::cout << "Nodo modificato" << std::endl;
                *it = value;
                break;
            case 2:
                std::cout << "Elemento corrente: " << *it;
                break;
            case 3:
                ++it;
                break;
            default:
                std::cout << "Scelta non valida." << std::endl;
        }

    } while(!it.Terminated());
}
