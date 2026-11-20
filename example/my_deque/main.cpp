#include <iostream>
#include "my_deque.h"

using namespace std;

int main() {
    my_deque<int> deque;
    deque.push_back(1);
    deque.push_back(2);
    deque.push_back(3);
    deque.push_front(0);
    cout << deque.size() << endl;
    cout << deque.at(3) << endl;
    cout << deque[2] << endl;
    cout << deque.front() << endl;
    cout << deque.back() << endl;

    for (size_t index = 0; index < deque.size(); index++) {
        cout << deque[index] << " ";
    }
}