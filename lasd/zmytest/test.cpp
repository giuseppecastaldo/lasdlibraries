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

void personal_test() {
    unsigned int loctestnum = 0, loctesterr = 0;
    std::cout << std::endl << "Begin of BST<int> Test" << std::endl;
    try {
        BST<int> bst;
        Empty(loctestnum, loctesterr, bst, true);

        InsertC(loctestnum, loctesterr, bst, 3);
        InsertC(loctestnum, loctesterr, bst, 21);
        InsertC(loctestnum, loctesterr, bst, 1);
        InsertC(loctestnum, loctesterr, bst, 4);
        InsertC(loctestnum, loctesterr, bst, -7);
        InsertC(loctestnum, loctesterr, bst, 5);
        InsertC(loctestnum, loctesterr, bst, 22);
        InsertC(loctestnum, loctesterr, bst, 2);
        InsertC(loctestnum, loctesterr, bst, 13);
        InsertC(loctestnum, loctesterr, bst, -9);

        Size(loctestnum, loctesterr, bst, true, 10);

        Remove(loctestnum, loctesterr, bst, 22);
        Remove(loctestnum, loctesterr, bst, 4);
        Remove(loctestnum, loctesterr, bst, 5);

        Exists(loctestnum, loctesterr, bst, false, 22);
        Exists(loctestnum, loctesterr, bst, false, 4);
        Exists(loctestnum, loctesterr, bst, false, 5);
        Exists(loctestnum, loctesterr, bst, true, 13);
        Size(loctestnum, loctesterr, bst, true, 7);

        Min(loctestnum, loctesterr, bst, true, -9);
        MinNRemove(loctestnum, loctesterr, bst, true, -9);
        Exists(loctestnum, loctesterr, bst, false, -9);
        Size(loctestnum, loctesterr, bst, true, 6);

        Remove(loctestnum, loctesterr, bst, 22);
        Remove(loctestnum, loctesterr, bst, 4);
        Remove(loctestnum, loctesterr, bst, 5);
        Size(loctestnum, loctesterr, bst, true, 6);

        Predecessor(loctestnum, loctesterr, bst, true, 5, 3);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        MapBreadth(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, 5, 3);
        Size(loctestnum, loctesterr, bst, true, 5);
        Exists(loctestnum, loctesterr, bst, true, 13);

        PredecessorNRemove(loctestnum, loctesterr, bst, false, -9, 3);
        Size(loctestnum, loctesterr, bst, true, 5);

        RemovePredecessor(loctestnum, loctesterr, bst, false, -7);
        Size(loctestnum, loctesterr, bst, true, 5);

        bst.Clear();

        Size(loctestnum, loctesterr, bst, true, 0);

        InsertC(loctestnum, loctesterr, bst, 14);
        InsertC(loctestnum, loctesterr, bst, -70);
        InsertC(loctestnum, loctesterr, bst, -1500);
        InsertC(loctestnum, loctesterr, bst, 1);
        InsertC(loctestnum, loctesterr, bst, -6);
        InsertC(loctestnum, loctesterr, bst, -5);
        InsertC(loctestnum, loctesterr, bst, -5);
        InsertC(loctestnum, loctesterr, bst, 7);
        InsertC(loctestnum, loctesterr, bst, 13);
        InsertC(loctestnum, loctesterr, bst, 13);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);

        Size(loctestnum, loctesterr, bst, true, 8);

        Successor(loctestnum, loctesterr, bst, true, 13, 14);
        SuccessorNRemove(loctestnum, loctesterr, bst, true, 13, 14);
        RemoveSuccessor(loctestnum, loctesterr, bst, true, -70);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);

        Predecessor(loctestnum, loctesterr, bst, true, -70, -1500);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, -70, -1500);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, -5, -70);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, 1, -5);
        PredecessorNRemove(loctestnum, loctesterr, bst, true, 7, 1);

        Size(loctestnum, loctesterr, bst, true, 2);

        BST<int> bst1(std::move(bst));
        Size(loctestnum, loctesterr, bst1, true, 2);
        Size(loctestnum, loctesterr, bst, true, 0);
        Empty(loctestnum, loctesterr, bst, true);

        MapInOrder(loctestnum, loctesterr, bst1, true, &MapPrint<int>, 0);
        RemoveMin(loctestnum, loctesterr, bst1, true);
        RemoveMax(loctestnum, loctesterr, bst1, true);

        Empty(loctestnum, loctesterr, bst1, true);
        bst1.Clear();

        EqualBST(loctestnum, loctesterr, bst, bst1);
        bst.Insert(-1);
        bst.Insert(2);
        bst.Insert(3);

        NonEqualBST(loctestnum, loctesterr, bst, bst1);
        RemoveMin(loctestnum, loctesterr, bst, true);

        InsertC(loctestnum, loctesterr, bst, -1);
        InsertC(loctestnum, loctesterr, bst, 2);
        InsertC(loctestnum, loctesterr, bst, 3);

        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);

        RemoveMin(loctestnum, loctesterr, bst, true);
        MinNRemove(loctestnum, loctesterr, bst, true, 2);
        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        Size(loctestnum, loctesterr, bst, true, 1);

        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);

        bst = bst1;

        EqualBST(loctestnum, loctesterr, bst, bst1);
        Empty(loctestnum, loctesterr, bst, true);
        Empty(loctestnum, loctesterr, bst1, true);

        InsertC(loctestnum, loctesterr, bst, 50);
        InsertC(loctestnum, loctesterr, bst, 17);
        InsertC(loctestnum, loctesterr, bst, 72);
        InsertC(loctestnum, loctesterr, bst, 12);
        InsertC(loctestnum, loctesterr, bst, 23);
        InsertC(loctestnum, loctesterr, bst, 54);
        InsertC(loctestnum, loctesterr, bst, 76);
        InsertC(loctestnum, loctesterr, bst, 9);
        InsertC(loctestnum, loctesterr, bst, 14);
        InsertC(loctestnum, loctesterr, bst, 19);
        InsertC(loctestnum, loctesterr, bst, 67);

        bst1 = bst;
        EqualBST(loctestnum, loctesterr, bst, bst1);

        Remove(loctestnum, loctesterr, bst, 14);
        Exists(loctestnum, loctesterr, bst, false, 14);
        Remove(loctestnum, loctesterr, bst, 12);
        Exists(loctestnum, loctesterr, bst, false, 12);
        Remove(loctestnum, loctesterr, bst, 54);
        Exists(loctestnum, loctesterr, bst, false, 54);

        Exists(loctestnum, loctesterr, bst, true, 9);
        Exists(loctestnum, loctesterr, bst, true, 67);

        Remove(loctestnum, loctesterr, bst, 50);
        Exists(loctestnum, loctesterr, bst, false, 50);

        Exists(loctestnum, loctesterr, bst, true, 17);
        Exists(loctestnum, loctesterr, bst, true, 72);

        Size(loctestnum, loctesterr, bst, true, 7);

        Remove(loctestnum, loctesterr, bst, 17);
        Remove(loctestnum, loctesterr, bst, 12);
        Remove(loctestnum, loctesterr, bst, 23);
        Remove(loctestnum, loctesterr, bst, 9);
        Remove(loctestnum, loctesterr, bst, 19);

        MapInOrder(loctestnum, loctesterr, bst, true, &MapPrint<int>, 0);
        MinNRemove(loctestnum, loctesterr, bst, true, 67);
        RemoveMin(loctestnum, loctesterr, bst, true);
        Min(loctestnum, loctesterr, bst, true, 76);
        MinNRemove(loctestnum, loctesterr, bst, true, 76);
        Empty(loctestnum, loctesterr, bst, true);

        MapInOrder(loctestnum, loctesterr, bst1, true, &MapPrint<int>, 0);

        Max(loctestnum, loctesterr, bst1, true, 76);
        RemoveMax(loctestnum, loctesterr, bst1, true);
        MaxNRemove(loctestnum, loctesterr, bst1, true, 72);
        MaxNRemove(loctestnum, loctesterr, bst1, true, 67);
        MaxNRemove(loctestnum, loctesterr, bst1, true, 54);
        RemoveMax(loctestnum, loctesterr, bst1, true);
        InsertC(loctestnum, loctesterr, bst1, 50);
        Max(loctestnum, loctesterr, bst1, true, 50);

        Size(loctestnum, loctesterr, bst1, true, 7);

    } catch(...) {
        loctestnum++; loctesterr++;
        std::cout << std::endl << "Unmanaged error! " << std::endl;
    }
    std::cout << "End of BST<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << std::endl;
}

void menu() {
    int choice = 0;
    
    do {
        std::cout << "1. BST" << std::endl;
        std::cout << "2. Test docente" << std::endl;
        std::cout << "3. Test personali" << std::endl;
        std::cout << "4. Esci" << std::endl;
        
        std::cin >> choice;
        switch(choice) {
            case 1:
                types(1);
                break;
            case 2:
                lasdtest();
                menu();
                break;
            case 3:
                personal_test();
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
                    
                    BST<std::string> bst(lst);
                    testBST(bst);
                    break;
                }
                case 2: {
                    List<int> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_int());
                    }
                    
                    BST<int> bst(lst);
                    testBSTInt(bst);
                    break;
                }
                case 3: {
                    List<double> lst;
                    for (unsigned long i = 0; i < n; i++) {
                        lst.InsertAtBack(random_double());
                    }
                    
                    BST<double> bst(lst);
                    testBST(bst);
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

void testBSTInt(BinaryTree<int>& bt) {
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
    
    menu();
}

template <typename Data>
void testBST(BinaryTree<Data>& bt) {
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
    
    menu();
}
