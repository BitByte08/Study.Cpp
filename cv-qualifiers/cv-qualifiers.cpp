#include <iostream>

using namespace std;

class Point2D {
private:
    int x, y;
public:
    Point2D(int x, int y): x(x), y(y) {};
    int get_x() const { return x; } // 함수에서 맴버 수정을 명시적으로 막기 위해 const 함수를 선언할 수 있다.
    int get_y() const {
        // y = 30; // 컴파일 에러, const 함수 내부의 this는 const T*이기 때문이다.
        return y;
    }
    const int& get_x_ref() const { return x; } // const를 반환하는 함수도 가능하다. (주로 레퍼런스 혹은 포인터와 같이 원본 값을 수정할 수 있는 문법에서 읽기를 강제할 때 사용.)
};

int main() {
    const int number = 3;
    // number = 4; // 컴파일 에러, const 변수에는 값을 대입할 수 없다.
    // const int i; // 컴파일 에러, const 변수는 초기화를 해주어야 한다.

    Point2D p(2, 3);
    cout << p.get_x() << " " << p.get_y() << endl;

    const int& ref = p.get_x_ref();
    cout << ref << endl;

}