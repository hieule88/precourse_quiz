#pragma once

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <queue>

namespace getp {

template <class T>
class priority_queue {
private:
  // IMPLEMENT HERE
  std::vector<T> heap;
public:
  priority_queue();
  ~priority_queue();
  void push( const T& value );
  const T& top() const;
  void pop();
};

template <class T>
priority_queue<T>::priority_queue() {
  // IMPLEMENT HERE
  // No need to do anything because vector constructor did it
}

template <class T>
priority_queue<T>::~priority_queue() { 
  // IMPLEMENT HERE
  // heap.clear();
  // No need for deconstructor because vector can do it itself
}

template <class T>
void priority_queue<T>::push(const T &value) {
  // IMPLEMENT HERE
  heap.emplace_back(value);

  int current_index = heap.size() - 1;

  while (current_index > 0) {
    int father_index = (current_index - 1) / 2;

    if (heap[father_index] < heap[current_index]) {
      std::swap(heap[father_index], heap[current_index]);
      current_index = father_index;

    } else break;
  }
}

template <class T>
const T& priority_queue<T>::top() const {
  // IMPLEMENT HERE
  if (heap.empty()) throw std::out_of_range("Empty queue!");
  return heap[0];
}

template <class T>
void priority_queue<T>::pop() {
  // IMPLEMENT HERE
  if (heap.empty()) throw std::out_of_range("Empty queue!");
  else {
    std::swap(heap[0], heap.back());

    heap.pop_back();

    // Down heap
    int current_index = 0;
    while (true){
      int left_child_index = 2 * current_index + 1;
      int right_child_index = 2 * current_index + 2;
      int largest_index = current_index;

      if (heap.size() > left_child_index){
        largest_index = (heap[current_index] > heap[left_child_index]) \
                        ? current_index : left_child_index;
        
        if (heap.size() > right_child_index) 
          largest_index = (heap[largest_index] > heap[right_child_index]) \
                          ? largest_index : right_child_index;
      }

      if (largest_index == current_index) break;
      else {
        std::swap(heap[current_index], heap[largest_index]);
        current_index = largest_index;
      }
    }
  }
}

} // namespace getp
