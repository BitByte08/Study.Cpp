#include <iostream>

using namespace std;

// 같은 이름의 함수라면 호출 하였을 때 사용하는 인자로 결정됨
void print(int x) { cout << x << endl; }
// c++ 컴파일러는 적합한 인자를 선택하여 호출하기 때문에 char에 대응되는 구현이 없어도 최대로 근접하는 함수를 호출함
// 이때 char, unsigned char, short 는 int로 변환된다.
// unsigned short는 int의 크기에 따라 int 혹은 unsigned int로 변환된다.
// float는 double로 변환된다.
// enum은 int로 변환된다.

// 위와 같은 과정을 거쳐도 일치하는 것이 없다면 조금 더 포괄적으로 형변환을 통해 함수를 찾음.
// 임의의 숫자(numeric) 타입은 다른 숫자 타입으로 변환된다. ex) float -> int
// enum 또한 임의의 숫자 타입으로 변환된다. ex) enum -> double
// 포인터는 void 타입의 포인터로 변환된다.
// 0은 포인터 타입이나 숫자 타입으로 변환된다.

// 이 과정으로도 함수를 찾지 못하면 마지막으로 유저 정의된 타입 변환으로 일치하는 함수를 찾음.

// void print(char x) { cout << x << endl; }

void print(double x) { cout << x << endl; }

void print_ambiguous(int x) { cout << x << endl; }

void print_ambiguous(char x) { cout << x << endl; }

int main() {
    int a = 5;
    char b = 'a';
    double c = 3.5f;

    print(a);
    print(b);
    print(c);

    print_ambiguous(b);
    // print_ambiguous(c); // 컴파일 에러, double은 char, int로 변환될 수 있어 모호함이 발생함.

    return 0;
}