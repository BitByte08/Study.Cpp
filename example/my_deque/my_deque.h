#pragma once
#include <cstddef>

template <typename T>
class my_deque {
private:
    const int block_size = 5;
    T** block_map;
    void reallocate_map();
public:
    my_deque();
    ~my_deque();

    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();

    T& at(int index);
    T& front();
    T& back();

    std::size_t size();

    T& operator[](int index);
};
