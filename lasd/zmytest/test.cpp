#include "test.hpp"

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
        std::cout << "1. Pila implementata con vettore" << std::endl;
        std::cout << "2. Pila implementata con lista" << std::endl;
        std::cout << "3. Coda implementata con vettore" << std::endl;
        std::cout << "4. Coda implementata con lista" << std::endl;
        std::cout << "5. Test docente" << std::endl;
        std::cout << "6. Esci" << std::endl;
        
        std::cin >> choice;
        switch(choice) {
            case 1:
                types(1);
                break;
            case 2:
                types(2);
                break;
            case 3:
                types(3);
                break;
            case 4:
                types(4);
                break;
            case 5:
                lasdtest();
                break;
            case 6:
                exit(0);
            default:
                std::cout << "Scelta non valida." << std::endl;
        }
    } while(choice > 6);
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
                    StackVec<std::string> stk;
                    for (unsigned long i = 0; i < n; i++) {
                        stk.Push(random_string());
                    }
                    
                    std::string toPush = random_string();
                    stack_test(stk, toPush);
                    break;
                }
                case 2: {
                    StackVec<int> stk;
                    for (unsigned long i = 0; i < n; i++) {
                        stk.Push(random_int());
                    }
                    
                    int toPush = random_int();
                    stack_test(stk, toPush);
                   
                    break;
                }
                case 3: {
                    StackVec<double> stk;
                    for (unsigned long i = 0; i < n; i++) {
                        stk.Push(random_double());
                    }
                    
                    double toPush = random_double();
                    stack_test(stk, toPush);
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
                    StackLst<std::string> stk;
                    for (unsigned long i = 0; i < n; i++) {
                        stk.Push(random_string());
                    }
                    
                    std::string toPush = random_string();
                    stack_test(stk, toPush);
                    break;
                }
                case 2: {
                    StackLst<int> stk;
                    for (unsigned long i = 0; i < n; i++) {
                        stk.Push(random_int());
                    }
                    
                    int toPush = random_int();
                    stack_test(stk, toPush);
                    break;
                }
                case 3: {
                    StackLst<double> stk;
                    for (unsigned long i = 0; i < n; i++) {
                        stk.Push(random_double());
                    }
                    
                    double toPush = random_double();
                    stack_test(stk, toPush);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 3: {
            switch (type) {
                case 1: {
                    QueueVec<std::string> queue;
                    for (unsigned long i = 0; i < n; i++) {
                        queue.Enqueue(random_string());
                    }
                    
                    std::string toEnqueue = random_string();
                    queue_test(queue, toEnqueue);
                    break;
                }
                case 2: {
                    QueueVec<int> queue;
                    for (unsigned long i = 0; i < n; i++) {
                        queue.Enqueue(random_int());
                    }
                    
                    int toEnqueue = random_int();
                    queue_test(queue, toEnqueue);
                    break;
                }
                case 3: {
                    QueueVec<double> queue;
                    for (unsigned long i = 0; i < n; i++) {
                        queue.Enqueue(random_double());
                    }
                    
                    double toEnqueue = random_double();
                    queue_test(queue, toEnqueue);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 4: {
            switch (type) {
                case 1: {
                    QueueLst<std::string> queue;
                    for (unsigned long i = 0; i < n; i++) {
                        queue.Enqueue(random_string());
                    }
                    
                    std::string toEnqueue = random_string();
                    queue_test(queue, toEnqueue);
                    break;
                }
                case 2: {
                    QueueLst<int> queue;
                    for (unsigned long i = 0; i < n; i++) {
                        queue.Enqueue(random_int());
                    }
                    
                    int toEnqueue = random_int();
                    queue_test(queue, toEnqueue);
                    break;
                }
                case 3: {
                    QueueLst<double> queue;
                    for (unsigned long i = 0; i < n; i++) {
                        queue.Enqueue(random_double());
                    }
                    
                    double toEnqueue = random_double();
                    queue_test(queue, toEnqueue);
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

template <typename Data>
void queue_test(Queue<Data>& queue, Data& toEnqueue) {
    std::cout << std::endl;
    std::cout << "1) Inserisco l'elemento " << toEnqueue << " nella struttura." << std::endl; queue.Enqueue(toEnqueue);
    std::cout << "2) La dimensione della struttura è: " << queue.Size() << std::endl;
    std::cout << "3) Il primo elemento della struttura è: " << queue.Head() << std::endl;
    std::cout << "4) Elimino il primo elemento leggendolo: " << queue.HeadNDequeue() << std::endl;
    std::cout << "5) Elimino il primo elemento" << std::endl; queue.Dequeue();
    std::cout << "6) La dimensione della struttura è: " << queue.Size() << std::endl;
    std::cout << "7) La struttura è " << ((queue.Empty() == false) ? "piena" : "vuota") << std::endl;
    std::cout << "8) Pulisco la struttura..." << std::endl; queue.Clear();
    std::cout << "9) La struttura è " << ((queue.Empty() == false) ? "piena" : "vuota") << std::endl;
    std::cout << std::endl;
    
    menu();
}

template <typename Data>
void stack_test(Stack<Data>& stack, Data& toPush) {
    std::cout << std::endl;
    std::cout << "1) Inserisco l'elemento " << toPush << " nella struttura." << std::endl; stack.Push(toPush);
    std::cout << "2) La dimensione della struttura è: " << stack.Size() << std::endl;
    std::cout << "3) Il primo elemento della struttura è: " << stack.Top() << std::endl;
    std::cout << "4) Elimino il primo elemento leggendolo: " << stack.TopNPop() << std::endl;
    std::cout << "5) Elimino il primo elemento" << std::endl; stack.Pop();
    std::cout << "6) La dimensione della struttura è: " << stack.Size() << std::endl;
    std::cout << "7) La struttura è " << ((stack.Empty() == false) ? "piena" : "vuota") << std::endl;
    std::cout << "8) Pulisco la struttura..." << std::endl; stack.Clear();
    std::cout << "9) La struttura è " << ((stack.Empty() == false) ? "piena" : "vuota") << std::endl;
    std::cout << std::endl;
    
    menu();
}
