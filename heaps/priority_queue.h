#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <cstddef>
#include <vector>

class PriorityQueue {
   private:
    std::vector<int> heap;

    void heapifyUp(size_t index);
    void heapifyDown(size_t index);

   public:
    void push(int element);
    int pop();
    int top();
    bool empty() const;
    size_t size() const;
};

#endif  // PRIORITY_QUEUE_H
