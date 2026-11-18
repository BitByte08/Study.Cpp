#pragma once

class my_string {
private:
    char *str_ = nullptr;
    int len_ = 0;
public:
    // Constructor
    my_string() = default;
    my_string(const char *str);
    my_string(const my_string &str);
    my_string(char c);

    // Destructor
    ~my_string();

    // Function
    int len() const;
    void concat(const my_string &str);
    bool compare(const my_string &str) const;
    void print();

    // Operator
    bool operator == (const my_string &) const;
};