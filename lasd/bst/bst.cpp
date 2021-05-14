
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& lc) {
    size = lc.Size();
    for (unsigned long i = 0; i < lc.Size(); i++) {
        Insert(lc[i]);
    }
}

template <typename Data>
void BST<Data>::Insert(const Data& value) {
    typename BinaryTreeLnk<Data>::NodeLnk*& node = *&FindPointerTo(root, value);
    if (node == nullptr) {
        node = new typename BinaryTreeLnk<Data>::NodeLnk(value);
        size++;
    }
}

template <typename Data>
bool BST<Data>::Exists(const Data& value) const noexcept {
    return (FindPointerTo(root, value) != nullptr);
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk*& BST<Data>::FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk*& node, const Data& value) noexcept {
    if (node == nullptr || node->element == value)
        return node;

    if (node->element < value)
        return FindPointerTo(node->right, value);

    return FindPointerTo(node->left, value);
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* const& BST<Data>::FindPointerTo(typename BinaryTreeLnk<Data>::NodeLnk* const& node, const Data& value) const noexcept {
    if (node == nullptr || node->element == value)
        return node;

    if (node->element < value)
        return FindPointerTo(node->right, value);

    return FindPointerTo(node->left, value);
}

/* ************************************************************************** */

}
