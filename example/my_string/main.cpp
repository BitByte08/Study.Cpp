#include <iostream>
#include <ostream>

#include "my_string.h"

int main() {
    my_string str = "Hello world";
    my_string str2 = "Hello world";
    str.print();
    std::cout << str.compare(str2) << std::endl;
    std::cout << (str==str2) << std::endl;
    str.concat(str2);
    str.print();
    std::cout << str.compare(str2) << std::endl;
    return 0;
}