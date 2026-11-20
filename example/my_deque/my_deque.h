#pragma once
#include <cstddef>

template <typename T>
class my_deque {
private:
    const int block_size = 5;
    size_t map_size = 3;
    size_t used_size = 0;
    T** block_map = nullptr;
    size_t start_block;
    size_t start_offset = 0;
    size_t end_block;
    size_t end_offset = 0;
    void reallocate_map();
    size_t new_map_size();
public:
    my_deque();
    ~my_deque();

    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();

    T& at(size_t index);
    T& front();
    T& back();

    size_t size() const;

    T& operator[](size_t index);
};

#include "my_deque.tpp"