#include "dary_heap.h"

#include <cstddef>

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
void DHeap<T>::pushDown(size_t index) {
    if (index == static_cast<size_t>(-1)) {
        index = pairs.size() - 1;
    }

    size_t current_index = index;

    // continue until current node is before the first leaf
    while (current_index < firstLeafIndex(pairs)) {
        auto [child, child_index] = highestPriorityChild(current_index);

        // If the child has higher priority, swap
        if (child.priority > pairs[current_index].priority) {
            std::swap(pairs[current_index], pairs[child_index]);
            current_index = child_index;  // move down
        } else {
            break;  // heap property restored
        }
    }
}

template <typename T>
size_t DHeap<T>::getParentIndex(size_t index) {
    return (index - 1) / D;
}

template <typename T>
size_t DHeap<T>::firstLeafIndex(const std::vector<Pair<T>>& pairs) {
    if (pairs.empty()) return 0;
    return (pairs.size() - 2) / D + 1;
}

template <typename T>
std::pair<Pair<T>, size_t> DHeap<T>::highestPriorityChild(size_t index) {
    size_t first_child = D * index + 1;
    size_t last_child = std::min(first_child + D, pairs.size());

    // If there are no children, return the current node itself (safe default)
    if (first_child >= pairs.size()) {
        return {pairs[index], index};
    }

    // Find the child with the highest priority
    size_t best_index = first_child;
    T best_priority = pairs[first_child].priority;

    for (size_t i = first_child + 1; i < last_child; ++i) {
        if (pairs[i].priority > best_priority) {
            best_priority = pairs[i].priority;
            best_index = i;
        }
    }

    return {pairs[best_index], best_index};
}
