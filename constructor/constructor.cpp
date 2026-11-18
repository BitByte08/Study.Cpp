#include <iostream>

using namespace std;

class User {
private:
    int id_;
public:
    int get_id();
};

int User::get_id() {
    return id_;
}

class ConstructorUser {
private:
    int id_;
public:
    int get_id();
    ConstructorUser() { // 디폴트 생성자는 원래 사용자가 어떠한 생성자도 명시적으로 정의하지 않으면 컴파일러가 자동으로 추가하는 생성자. 사용자가 직접 정의할 수 있음.
        id_ = 0;
        cout << "ConstructorUser()" << endl;
    }
    // ConstructorUser() = default; // c++11 이전에는 디폴트 생성자가 필요하면 무조건 생성자를 정의하여야 하지만, c++11부터 명시적으로 디폴트 생성자를 명시할 수 있음.
    ConstructorUser(int id) { // 다음과 같이 하나의 클래스 안에 여러 생성자를 오버로딩 할 수 있다.
        id_ = id;
        cout << "ConstructorUser(int id)" << endl;
    }
};

int ConstructorUser::get_id() {
    return id_;
}

int main() {
    User u;
    cout << u.get_id() << endl; // 당연히 객체가 생성되었을 때 초기화를 하지 않아 쓰레기 값이 출력됨.
    // 실수로 객체를 초기화하지 않고 사용하는 경우를 방지하기 위해 생성자를 구현함.
    ConstructorUser cu(3); // 암시적 선언
    // ConstructorUser cu = ConstructorUser(3); // 다음처럼 명시적으로 선언도 가능하다.
    cout << cu.get_id() << endl; // ConstructorUser의 경우 생성자를 통해 초기화를 하여 문제없이 의도한 결과가 나옴

    ConstructorUser cu2;
    cout << cu2.get_id() << endl;

    // ConstructorUser cu3(); // 잘못된 문법, cu3를 ConstructorUser를 반환하는 함수로 인식함.
}