#include "dary_heap.h"

#include <cstddef>
#include <utility>

template <typename T>
void DHeap<T>::bubbleUp(size_t index) {
    if (index == static_cast<size_t>(-1)) {
        index = pairs.size() - 1;
    }

    size_t parent_index = index;
    while (parent_index > 0) {
        size_t current_index = parent_index;
        parent_index = getParentIndex(parent_index);

        if (pairs[parent_index].priority < pairs[current_index].priority) {
            std::swap(pairs[current_index], pairs[parent_index]);
        } else {
            break;
        }
    }
}

template <typename T>
size_t DHeap<T>::getParentIndex(size_t index) {
    return (index - 1) / D;
}
