
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const BST& bst) : BinaryTreeLnk<Data>::BinaryTreeLnk(bst) {}

template <typename Data>
BST<Data>::BST(BST&& bst) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst)) {}

template <typename Data>
BST<Data>& BST<Data>::operator =(const BST& bst){
    BinaryTreeLnk<Data>::operator =(bst);
    return *this;
}

template <typename Data>
BST<Data>& BST<Data>::operator =(BST&& bst) noexcept {
    BinaryTreeLnk<Data>::operator =(std::move(bst));
    return *this;
}

template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& lc) {
    for (unsigned long i = 0; i < lc.Size(); i++) {
        Insert(lc[i]);
    }
}

template <typename Data>
bool BST<Data>::operator ==(const BST& bst) const noexcept {
    if (size!=bst.Size()) {
        return false;
    }
    
    BTInOrderIterator<Data> it2(bst);
    for(BTInOrderIterator<Data> it1(*this); !it1.Terminated(); ++it1, ++it2) {
        if (*it1 != *it2) {
            return false;
        }
    }
    
    return true;
}

template <typename Data>
bool BST<Data>::operator !=(const BST& bst) const noexcept {
    return !(*this == bst);
}

template <typename Data>
void BST<Data>::Insert(const Data& value) {
    NodeLnk*& node = *&FindPointerTo(root, value);
    if (node == nullptr) {
        node = new NodeLnk(value);
        size++;
    }
}

template <typename Data>
void BST<Data>::Insert(Data&& value) {
    NodeLnk*& node = *&FindPointerTo(root, value);
    if (node == nullptr) {
        node = new NodeLnk(std::move(value));
        size++;
    }
}

template <typename Data>
void BST<Data>::Remove(const Data& value) {
    Detach(root, value);
}

template <typename Data>
Data& BST<Data>::Min() const {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* min = FindPointerToMin(root);
    
    if (min == nullptr) {
        throw std::length_error("Value not found.");
    }
    
    return min->element;
}

template <typename Data>
Data BST<Data>::MinNRemove() {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* min = DetachMin(root, nullptr);
    
    if (min == nullptr) {
        throw std::length_error("Value not found.");
    }
    size--;
    return min->element;
}

template <typename Data>
void BST<Data>::RemoveMin() {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* min = DetachMin(root, nullptr);
    
    if (min == nullptr) {
        throw std::length_error("Value not found.");
    }
    size--;
}

template <typename Data>
Data& BST<Data>::Max() const {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* max = FindPointerToMax(root);
    
    if (max == nullptr) {
        throw std::length_error("Value not found.");
    }
    
    return max->element;
}

template <typename Data>
void BST<Data>::RemoveMax() {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* max = DetachMax(root, nullptr);
    
    if (max == nullptr) {
        throw std::length_error("Value not found.");
    }
    size--;
}

template <typename Data>
Data BST<Data>::MaxNRemove() {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* max = DetachMax(root, nullptr);
    
    if (max == nullptr) {
        throw std::length_error("Value not found.");
    }
    size--;
    return max->element;
}

template <typename Data>
Data& BST<Data>::Predecessor(const Data& value) const {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* predecessor = FindPointerToPredecessor(root, nullptr, value);
    
    if (predecessor == nullptr) {
        throw std::length_error("Value not found.");
    }
    return predecessor->element;
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& value) {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* predecessor = Detach(root, FindPointerToPredecessor(root, nullptr, value)->element);
    
    if (predecessor == nullptr) {
        throw std::length_error("Value not found.");
    }
    
    return predecessor->element;
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& value) {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* predecessor = Detach(root, FindPointerToPredecessor(root, nullptr, value)->element);
    
    if (predecessor == nullptr) {
        throw std::length_error("Value not found.");
    }
}

template <typename Data>
Data& BST<Data>::Successor(const Data& value) const {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* successor = FindPointerToSuccessor(root, nullptr, value);
    
    if (successor == nullptr) {
        throw std::length_error("Value not found.");
    }
    return successor->element;
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& value) {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* successor = Detach(root, FindPointerToSuccessor(root, nullptr, value)->element);
    
    if (successor == nullptr) {
        throw std::length_error("Value not found.");
    }
    return successor->element;
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& value) {
    if (root == nullptr) {
        throw std::length_error("Empty BST!");
    }
    
    NodeLnk* successor = Detach(root, FindPointerToSuccessor(root, value)->element);
    
    if (successor == nullptr) {
        throw std::length_error("Value not found.");
    }
}

template <typename Data>
bool BST<Data>::Exists(const Data& value) const noexcept {
    return (FindPointerTo(root, value) != nullptr);
}

/* ************************************************************************** */

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk* node, const Data& value) {
    NodeLnk*& to_be_detached = *&FindPointerTo(root, value);
    
    if (to_be_detached != nullptr) {
        if (to_be_detached->left == nullptr && to_be_detached->right == nullptr) {
            delete to_be_detached;
            to_be_detached = nullptr;
        } else if (to_be_detached->left != nullptr && to_be_detached->right == nullptr) {
            SkipOnLeft(to_be_detached);
        } else if (to_be_detached->left == nullptr && to_be_detached->right != nullptr) {
            SkipOnRight(to_be_detached);
        } else {
            NodeLnk* tmp = DetachMin(to_be_detached->right, to_be_detached);
            to_be_detached->element = tmp->element;
            delete tmp;
        }
        size--;
    }
    
    return to_be_detached;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk* node, NodeLnk* parent) {
    if (node != nullptr) {
        if (node->left != nullptr) {
            return DetachMin(node->left, node);
        } else {
            if (parent->left == node)
                parent->left = node->right;
            else
                parent->right = node->right;
        }
    }
    
    return node;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk* node, NodeLnk* parent) {
    if (node != nullptr) {
        if (node->right != nullptr) {
            return DetachMax(node->right, node);
        } else {
            if (node->left == node)
                parent->left = node->left;
            else
                parent->right = node->left;
        }
    }
    
    return node;
}

template <typename Data>
void BST<Data>::SkipOnLeft(NodeLnk*& node) {
    NodeLnk* tmp = node;
    node = node->left;
    delete tmp;
}

template <typename Data>
void BST<Data>::SkipOnRight(NodeLnk*& node) {
    NodeLnk* tmp = node;
    node = node->right;
    delete tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {
    NodeLnk* current = node;
    
    while (current && current->left != nullptr) {
        current = current->left;
    }
    
    return current;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::FindPointerToMin(NodeLnk* node) const noexcept {
    NodeLnk* current = node;
    
    while (current && current->left != nullptr) {
        current = current->left;
    }
    
    return current;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {
    NodeLnk* current = node;
    
    while (current && current->right != nullptr) {
        current = current->right;
    }
    
    return current;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::FindPointerToMax(NodeLnk* node) const noexcept {
    NodeLnk* current = node;
    
    while (current && current->right != nullptr) {
        current = current->right;
    }
    
    return current;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, const Data& value) noexcept {
    if (node == nullptr || node->element == value)
        return node;
    
    if (node->element < value)
        return FindPointerTo(node->right, value);
    
    return FindPointerTo(node->left, value);
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::FindPointerTo(NodeLnk* node, const Data& value) const noexcept {
    if (node == nullptr || node->element == value)
        return node;
    
    if (node->element < value)
        return FindPointerTo(node->right, value);
    
    return FindPointerTo(node->left, value);
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node, NodeLnk*& parent, const Data& value) noexcept {
    if (node == nullptr) {
        return node;
    } else if (value <= node->element) {
        return FindPointerToPredecessor(node->left, nullptr, value);
    } else {
        NodeLnk* m = FindPointerToPredecessor(node->right, nullptr, value);
        if (m != nullptr) {
            return m;
        } else {
            return node;
        }
    }
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::FindPointerToPredecessor(NodeLnk* node, NodeLnk* parent, const Data& value) const noexcept {
    if (node == nullptr) {
        return node;
    } else if (value <= node->element) {
        return FindPointerToPredecessor(node->left, nullptr, value);
    } else {
        NodeLnk* m = FindPointerToPredecessor(node->right, nullptr, value);
        if (m != nullptr) {
            return m;
        } else {
            return node;
        }
    }
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node, NodeLnk*& parent, const Data& value) noexcept {
    if (node == nullptr) {
        return node;
    }

    if (root->element == value) {
        if (root->left) {
            return FindPointerToMax(root->left);
        }
    } else if (value < root->element) {
        return FindPointerToPredecessor(root->left, parent, value);
    } else {
        parent = node;
        FindPointerToPredecessor(root->right, parent, value);
    }
    
    return parent;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::FindPointerToSuccessor(NodeLnk* node, NodeLnk* parent, const Data& value) const noexcept {
    if (node == nullptr) {
        return node;
    }

    if (value < node->element) {
        return FindPointerToSuccessor(node->left, node, value);
    } else if (value > node->element) {
        return FindPointerToSuccessor(node->right, parent, value);
    }
    
    if (node->right != nullptr) {
        return FindPointerToMin(node->right);
    }
    
    return parent;
}

/* ************************************************************************** */

}
