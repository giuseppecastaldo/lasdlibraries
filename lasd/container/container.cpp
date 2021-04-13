//
//  container.cpp
//  exercise1
//
//  Created by Giuseppe Castaldo on 02/04/21.
//

namespace lasd {

/* ************************************************************************** */

template <typename Data>
void AuxFoldExists(const Data& dat, const void* val, void* exists) {
    if (dat == *((Data*) val)) {
        *((bool*) exists) = true;
    }
}

template <typename Data>
bool FoldableContainer<Data>::Exists(const Data& dat) const noexcept {
    bool exists = false;
    FoldPreOrder(&AuxFoldExists<Data>, &dat, &exists);
    return exists;
}

/* ************************************************************************** */

}
