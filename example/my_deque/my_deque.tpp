#pragma once

#include <cassert>
#include <iostream>

template <typename T>
my_deque<T>::my_deque() : block_map(new T*[map_size]()) {
    start_block = end_block = map_size / 2;
    block_map[start_block] = new T[block_size];
}

template <typename T>
my_deque<T>::~my_deque() {
    for (size_t i = start_block; i <= end_block; i++) {
        delete[] block_map[i];
    }
    delete[] block_map;
};

template <typename T>
size_t my_deque<T>::new_map_size() {
    return map_size*2+2;
}

template <typename T>
void my_deque<T>::reallocate_map() {
    const size_t new_size = new_map_size();
    T** new_map = new T*[new_size]();
    const size_t gap = (new_size - map_size) / 2;
    for (size_t i = 0; i < map_size; i++) {
        new_map[i+gap] = block_map[i];
    }
    delete[] block_map;
    block_map = new_map;
    map_size = new_size;
    start_block+=gap;
    end_block+=gap;
    std::cout << "[reallocate_map] realloc new map: " << new_size << std::endl;
}

template <typename T>
size_t my_deque<T>::size() const {
    return (end_block*block_size+end_offset)-(start_block*block_size+start_offset);
}

template <typename T>
void my_deque<T>::push_front(T value) {
    if (start_block == 0 && start_offset == 0) reallocate_map();
    if (start_offset == 0) {
        start_block--;
        start_offset = block_size;
    }
    if (block_map[start_block] == nullptr) {
        block_map[start_block] = new T[block_size]();
        std::cout << "[push_front] alloc new block: " << start_block << std::endl;
    }

    T* select_block = block_map[start_block];
    select_block[--start_offset] = value;
}

template <typename T>
void my_deque<T>::push_back(T value) {
    if (end_block == map_size - 1 && end_offset == block_size) reallocate_map();
    if (end_offset == block_size) {
        end_block++;
        end_offset = 0;
    }
    if (block_map[end_block] == nullptr) {
        block_map[end_block] = new T[block_size]();
        std::cout << "[push_back] alloc new block: " << end_block << std::endl;
    }

    T* select_block = block_map[end_block];
    select_block[end_offset++] = value;
}

template <typename T>
void my_deque<T>::pop_front() {
    assert(size() > 0);
    start_offset++;
    if (start_offset == block_size) {
        delete[] block_map[start_block];
        block_map[start_block] = nullptr;
        std::cout << "[pop_front] free block: " << start_block << std::endl;
        start_block++;
        start_offset = 0;
    }
}

template <typename T>
void my_deque<T>::pop_back() {
    assert(size() > 0);
    if (end_offset == 0) {
        delete[] block_map[end_block];
        block_map[end_block] = nullptr;
        std::cout << "[pop_back] free block: " << end_block << std::endl;
        end_block--;
        end_offset = block_size;
    }

    end_offset--;
}

template <typename T>
T& my_deque<T>::at(size_t index) {
    if (index >= size()) throw std::out_of_range("[at] index out of range");
    return (*this)[index];
}

template <typename T>
T& my_deque<T>::operator[](size_t index) {
    assert(index < size());
    const size_t deque_index = index + start_offset + start_block * block_size;
    const size_t block = deque_index / block_size;
    const size_t offset = deque_index % block_size;
    return block_map[block][offset];
}

template <typename T>
T& my_deque<T>::front() {
    assert(size() > 0);
    return block_map[start_block][start_offset];
}

template <typename T>
T& my_deque<T>::back() {
    assert(size() > 0);
    return (*this)[size()-1];
}