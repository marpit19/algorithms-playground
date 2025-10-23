#include "priority_queue.h"

#include <iostream>
#include <vector>

void PriorityQueue::heapifyUp(size_t index) {
    /*
    parent node of i: (i-1) / 2
    left child: 2*i + 1
    right child: 2*i + 2
    */
    while (index > 0) {
        size_t parent_index = (index - 1) / 2;
        if (heap[index] > heap[parent_index]) {
            std::swap(heap[index], heap[parent_index]);
            index = parent_index;
        } else {
            break;
        }
    }
}

void PriorityQueue::heapifyDown(size_t index) {
    /*
    parent node of i: (i-1) / 2
    left child: 2*i + 1
    right child: 2*i + 2
    */
    size_t size = heap.size();
    while (true) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t largest = index;

        if (left < size && heap[left] > heap[largest]) largest = left;

        if (right < size && heap[right] > heap[largest]) largest = right;

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            index = largest;
        } else {
            break;
        }
    }
}

void PriorityQueue::push(int element) {
    heap.emplace_back(element);
    heapifyUp(heap.size() - 1);
}

int PriorityQueue::pop() {
    if (empty()) {
        std::cout << "Priority Queue is empty!\n";
        return -1;
    }

    int root = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!empty()) heapifyDown(0);
    return root;
}

int PriorityQueue::top() {
    if (empty()) {
        std::cout << "add an element to Priority Queue first" << std::endl;
        return -1;
    }
    return heap[0];
}

bool PriorityQueue::empty() const { return heap.empty(); }

size_t PriorityQueue::size() const { return heap.size(); }
