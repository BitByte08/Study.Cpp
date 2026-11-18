#include <iostream>

using namespace std;

class implicit_class {
private:
    int number;
public:
    implicit_class(int number): number(number) {};
    ~implicit_class() {};
};

void i_need_implicit_class(implicit_class impl) {
    cout << "i_need_implicit_class" << endl;
}

class explicit_class {
private:
    int number;
public:
    explicit explicit_class(int number) : number(number) {};
    ~explicit_class() {};
};

void i_need_explicit_class(explicit_class expl) {
    cout << "i_need_explicit_class" << endl;
}

int main() {
    i_need_implicit_class(3); // 아래와 다르게 암시적 변환을 통해 implicit_class 생성자가 호출되어 문제없이 넘어감.
    // i_need_explicit_class(3); // 컴파일 에러, 생성자를 명시적으로 선언하였기 때문에 암시적 변환이 안됨.

    implicit_class impl = 4;
    // explicit_class expl = 4; // 위와 같이 암시적 변환이 되지 않아 컴파일 에러.
}