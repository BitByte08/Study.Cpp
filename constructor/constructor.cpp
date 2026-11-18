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
    ConstructorUser(const ConstructorUser& c) { // 복사 생성자, const를 통해 c를 받았기에 값을 읽는것은 가능하나 수정은 불가능(private 값도 읽을 수 있음)
        id_ = c.id_; // 복사 생성자는 디폴트로 생성되기에 단순히 값을 대응해야한다면 디폴트 복사 생성자를 이용하는 것이 좋다.

        // 이때 주의해야 할 사항은 동적인 메모리는 깊은 복사를 수행해야 한다는 점이다.
        // 디폴트 복사 생성자 등은 기본적으로 값을 대입하는 얕은 복사를 수행함.
        // 만약 포인터 변수에 이를 수행하는 경우 두 객체가 같은 메모리 주소를 가리키게 되어
        // 메모리가 해제되는 등 여러 문제점이 발생 할 수 있음.
        // 이때는 깊은 복사를 수행하여 메모리 공간도 새로 할당해주는 것이 좋다. (사용자 정의 복사 생성자를 만들어야 할 상황)

        cout << "ConstructorUser(const ConstructorUser& c)" << endl;
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

    ConstructorUser cu3(cu);
    cout << cu3.get_id() << endl;
}