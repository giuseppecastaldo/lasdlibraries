namespace lasd {

template <typename Data>
List<Data>::Node::Node(const Data& data) {
    Element = data;
}

template <typename Data>
List<Data>::Node::Node(const Node& node) {
    Element = node.Element;
}

template <typename Data>
List<Data>::Node::Node(Node&& node) noexcept {
    std::swap(Element, node.Element);
    std::swap(NextElement, node.NextElement);
}

template <typename Data>
bool List<Data>::Node::operator==(const Node& node) const noexcept {
    if (node.Element == Element && node.NextElement == NextElement) {
        return true;
    }
    
    return false;
}

template <typename Data>
bool List<Data>::Node::operator!=(const Node& node) const noexcept {
    return !(*this == node);
}

/* ************************************************************************** */

template <typename Data>
List<Data>::List(const LinearContainer<Data>& con) {
    for (unsigned long index = 0; index < con.Size(); ++index) {
        List<Data>::InsertAtBack(con[index]);
    }
}

template <typename Data>
List<Data>::List(const List& list) {
    if (list.Head != nullptr) {
        Node* temp = list.Head;
        while (temp != nullptr) {
            InsertAtBack(temp->Element);
            temp = temp->NextElement;
        }
    }
}

template <typename Data>
List<Data>::List(List&& list) noexcept {
    std::swap(size, list.size);
    std::swap(Head, list.Head);
    std::swap(Tail, list.Tail);
}

template <typename Data>
List<Data>::~List() {
    Clear();
}

template <typename Data>
List<Data>& List<Data>::operator=(const List& list) {
    if(this != &list) {
        Clear();
        if(list.Head != nullptr){
            struct Node *tmp = list.Head;
            while(tmp != nullptr){
                InsertAtBack(tmp->Element);
                tmp = tmp->NextElement;
            }
        }
    }
    return *this;
}

template <typename Data>
List<Data>& List<Data>::operator=(List&& list) noexcept {
    if(this != &list) {
        std::swap(size, list.size);
        std::swap(Head, list.Head);
        std::swap(Tail, list.Tail);
    }
    
    return *this;
}

/* ************************************************************************** */

template <typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept {
    if(size != list.size)
        return false;
    
    struct Node *tmp = Head;
    struct Node *tmp2 = list.Head;
    
    for(unsigned long i = 0; i < size; i++){
        if(tmp->Element != tmp2->Element)
            return false;
        
        tmp = tmp->NextElement;
        tmp2 = tmp2->NextElement;
    }
    
    return true;
}

template <typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept {
    return !(*this == list);
}

template <typename Data>
void List<Data>::InsertAtFront(const Data& dat) {
    size++;
    Node* node = new Node(dat);
    node->NextElement = Head;
    Head = node;
    
    if (size == 1) {
        Tail = Head;
    }
}

template <typename Data>
void List<Data>::InsertAtFront(Data&& dat) {
    size++;
    Node* node = new Node(std::move(dat));
    node->NextElement = Head;
    Head = node;
    
    if (size == 1) {
        Tail = Head;
    }
}

template <typename Data>
void List<Data>::RemoveFromFront() {
    if (size == 0) {
        throw std::length_error("Empty list exception.");
    }
    
    if (size == 1) {
        Tail = nullptr;
    }
    
    size--;
    Node* tmp = Head;
    Head = Head->NextElement;
    tmp->NextElement = nullptr;
    delete tmp;
}

template <typename Data>
Data List<Data>::FrontNRemove() {
    Data result = Front();
    RemoveFromFront();
    
    return result;
}

template <typename Data>
void List<Data>::InsertAtBack(const Data& data) {
    size++;
    Node* node = new Node(data);
    
    if (Head == nullptr) {
        Head = Tail = node;
        return;
    }
    
    Tail->NextElement = node;
    Tail = Tail->NextElement;
}

template <typename Data>
void List<Data>::InsertAtBack(Data&& data) {
    size++;
    Node* node = new Node(std::move(data));
    
    if (Head == nullptr) {
        Head = Tail = node;
        return;
    }
    
    Tail->NextElement = node;
    Tail = Tail->NextElement;
}

template <typename Data>
void List<Data>::Clear() {
    while (Head != nullptr)
        RemoveFromFront();
}

template <typename Data>
Data& List<Data>::Front() const {
    if (size == 0) {
        throw std::length_error("Empty list exception.");
    }
    
    return Head->Element;
}

template <typename Data>
Data& List<Data>::Back() const {
    if (size == 0) {
        throw std::length_error("Empty list exception.");
    }
    
    return Tail->Element;
}

template <typename Data>
Data& List<Data>::operator[](const unsigned long index) const {
    if (size == 0) {
        throw std::length_error("Empty list exception.");
    } else if (index == size - 1) {
        return Back();
    } else if (index >= size) {
        throw std::out_of_range("Index out of bound exception.");
    }
    
    Node* current = Head;
    for (unsigned long i = 0; i < index; i++, current = current->NextElement);
    return current->Element;
}

template <typename Data>
void List<Data>::MapPreOrder(MapFunctor function, void *par) {
    MapPreOrder(function, par, Head);
}

template <typename Data>
void List<Data>::MapPostOrder(MapFunctor function, void *par) {
    MapPostOrder(function, par, Head);
}

template <typename Data>
void List<Data>::FoldPreOrder(FoldFunctor function, const void *constPar, void *par) const {
    FoldPreOrder(function, constPar, par, Head);
}

template <typename Data>
void List<Data>::FoldPostOrder(FoldFunctor function, const void *constPar, void *par) const {
    FoldPostOrder(function, constPar, par, Head);
}

//OVERLOAD Accessory Function

template <typename Data>
void List<Data>::MapPreOrder(MapFunctor function, void *par, struct Node *node) {
    if (node == nullptr)
        return;
    
    function(node->Element, par);
    MapPreOrder(function, par, node->NextElement);
}

template <typename Data>
void List<Data>::MapPostOrder(MapFunctor function, void *par, struct Node *node) {
    if (node == nullptr)
        return;
    
    MapPostOrder(function, par, node->NextElement);
    function(node->Element, par);
}

template <typename Data>
void List<Data>::FoldPreOrder(FoldFunctor function, const void *constPar, void *par, struct Node *node) const {
    if (node == nullptr)
        return;
    
    function(node->Element, constPar, par);
    FoldPreOrder(function, constPar, par, node->NextElement);
}

template <typename Data>
void List<Data>::FoldPostOrder(FoldFunctor function, const void *constPar, void *par, struct Node *node) const {
    if (node == nullptr)
        return;
    
    FoldPostOrder(function, constPar, par, node->NextElement);
    function(node->Element, constPar, par);
}

}
