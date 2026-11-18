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

class Base {
public:
    Base() {cout << "Base Class\n";}
    virtual void whomi() {cout << "Base Class whomi()\n";} // virtual 키워드를 사용하면 동적 바인딩을 통해 함수를 선택한다.
    // virtual 키워드로 선언된 함수를 가상 함수라고 칭한다.
};

class Derived : public Base {
public:
    Derived(): Base() {cout << "Derived Class\n";}
    void whomi() override {cout << "Derived Class whomi()\n";}
    // 또한 가상 함수를 오버라이딩한다면 override 키워드를 통해 명시하여 컴파일 단계에서 오버라이딩이 되지 않는 버그를 잡아낼 수 있다.
    // void whomi() const override {cout << "Derived Class whomi()\n";} // 이와 같이 이름은 같지만 const 함수로 선언 하는 등 다른 함수를 컴파일에서 잡아낼 수 있다.
};

int main() {
    i_need_implicit_class(3); // 아래와 다르게 암시적 변환을 통해 implicit_class 생성자가 호출되어 문제없이 넘어감.
    // i_need_explicit_class(3); // 컴파일 에러, 생성자를 명시적으로 선언하였기 때문에 암시적 변환이 안됨.

    implicit_class impl = 4;
    // explicit_class expl = 4; // 위와 같이 암시적 변환이 되지 않아 컴파일 에러.

    Base b;
    Derived d;

    Base* b_ptr = &b;
    Base* d_ptr = &d; // Base 포인터로 Derived 객체를 가르키는 것은 가능하다. ( is a 관계 )

    b_ptr->whomi();
    d_ptr->whomi(); // Base 포인터의 whomi를 실행하면 Base 객체의 함수를 가리키기 때문에 Base Class whomi() 출력이 나온다. 이를 방지하기 위해 virtual 키워드로 해결 가능하다.
}

// virtual 함수의 동적 바인딩 원리
// virtual로 선언된 함수의 주소를 가리키는 함수 포인터 배열 vtable을 생성한다. 이는 각 클래스마다 하나씩 존재한다.
// 이를 통해 생성된 객체는 vptr을 가진다. vptr은 객체가 생성될 때 그 생성자의 클래스의 vtable을 가리키도록 되어있다.