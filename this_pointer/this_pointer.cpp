#include <iostream>

using namespace std;

class This {
private:
    int number;
public:
    This(int number) : number(number) {}
    void change() {
        number++;
    }
    This& me() {
        return *this; // this 키워드는 객체 자신을 가리키는 포인터의 역할을 함
    }
    int get_number() {
        return number;
    }
};

int main() {
    This t1(1);
    This& t2 = t1.me();
    t2.change();

    cout << t1.get_number() << endl;
}