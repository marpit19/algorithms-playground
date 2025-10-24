#ifndef DARY_HEAP_H
#define DARY_HEAP_H

#include <vector>

template <typename T>
struct Pair {
    T element;
    int priority;
};

template <typename T>
class DHeap {
   private:
    std::vector<Pair<T>> pairs;
    int D;

    void bubbleUp(size_t index);
    size_t getParentIndex(size_t index = static_cast<size_t>(-1));

   public:
    explicit DHeap() {}
    explicit DHeap(int d) : D(d) {}
};

#endif  // DARY_HEAP_H
