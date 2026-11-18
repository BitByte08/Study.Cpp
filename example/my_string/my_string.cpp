#include "my_string.h"

#include <iostream>
#include <ostream>

int strlen(const char *str) {
    int len = 0;
    for (;str[len] != '\0'; len++);
    return len;
}

my_string::my_string(const my_string &str) {
    this->len_ = str.len();
    this->str_ = new char[str.len()+1];
    for (int i = 0; i<= this->len_; i++) {
        this->str_[i] = str.str_[i];
    }
}

my_string::my_string(const char *str) {
    this->len_ = strlen(str);
    this->str_ = new char[len_+1];
    for (int i = 0; i <= this->len_; i++) {
        this->str_[i] = str[i];
    }
}

my_string::my_string(char c) {
    this->len_ = 1;
    this->str_ = new char[1];
    this->str_[0] = c;
}

my_string::~my_string() { delete[] this->str_; }

int my_string::len() const {
    return len_;
}

void my_string::concat(const my_string &str) {
    char *tmp = new char[this->len() + str.len() - 1];
    int point = 0;
    for (int i = 0; i < this->len(); i++, point++) {
        tmp[point] = this->str_[i];
    }
    for (int i = 0; i < str.len(); i++, point++) {
        tmp[point] = str.str_[i];
    }
    tmp[point] = '\0';
    this->len_ = strlen(tmp);
    delete[] this->str_;
    this->str_ = tmp;
}

bool my_string::compare(const my_string &str) const {
    if (this->len() != str.len()) {
        return this->len() > str.len();
    }
    for (int i = 0; i < this->len(); i++) {
        if (this->str_[i] != str.str_[i]) {
            return this->str_[i] > str.str_[i];
        }
    }
    return false;
}

bool my_string::operator == (const my_string &str) const {
    if (this->len() != str.len()) {
        return false;
    }
    for (int i = 0; i < this->len(); i++) {
        if (this->str_[i] != str.str_[i]) {
            return false;
        }
    }
    return true;
}

void my_string::print() {
    std::cout << this->str_ << std::endl;
}