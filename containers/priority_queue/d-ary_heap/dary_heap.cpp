#include "dary_heap.h"

#include <cstddef>
#include <utility>

template <typename T>
void DHeap<T>::bubbleUp(size_t index) {
    if (index == static_cast<size_t>(-1)) {
        index = pairs.size() - 1;
    }

    Pair<T> current = pairs[index];
    while (index > 0) {
        size_t parent_index = getParentIndex(index);
        if (pairs[parent_index].priority < current.priority) {
            pairs[index] = pairs[parent_index];
            index = parent_index;
        } else {
            break;
        }
    }
    pairs[index] = current;
}

template <typename T>
size_t DHeap<T>::getParentIndex(size_t index) {
    return (index - 1) / D;
}
