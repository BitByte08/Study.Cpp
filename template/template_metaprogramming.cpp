#include <cmath>
#include <iostream>

using namespace std;

// 팩토리얼
template <int N>
struct Factorial {
    static const int result = N * Factorial<N - 1>::result;
};

template <>
struct Factorial<0> {
    static const int result = 1;
};

// c++에서는 타입은 반드시 컴파일 타임에 확정되어야 함.
// 템플릿의 경우 그 타입을 활용하게 됨.
// 이를 활용하면 타입에 값을 부여할 수 있고 그를 통해 연산을 수행할 수 있게 됨.
// 이 과정을 통틀어 메타 프로그래밍(컴파일 타임에 생성되는 코드로 프로그래밍) 이라고 칭함
// c++에서는 템플릿을 통하여 메타 프로그래밍을 수행할 수 있어 템플릿 메타 프로그래밍(TMP) 라고 칭한다.

//유클리드 호제법
template <int A, int B>
struct GCD {
    static const int value = GCD<B, A % B>::value;
};

template <int A>
struct GCD<A, 0> {
    static const int value = A;
};

//유리수
template <int P, int Q = 1>
struct Rational {
    using type = Rational<P, Q>;
    static const int num = P;
    static const int den = Q;
};

template <class R1, class R2>
struct _Radional_add {
    using type = Rational<R1::num * R2::den + R2::num * R1::den,R1::den * R2::den>;
};
template <class R1, class R2>
struct Rational_add : _Radional_add<R1, R2>::type {};

template <class R1, class R2>
struct _Radional_subtract {
    using type = Rational<R1::num * R2::den - R2::num * R1::den,R1::den * R2::den>;
};
template <class R1, class R2>
struct Rational_subtract : _Radional_subtract<R1, R2>::type {};

template <class R1, class R2>
struct _Radional_multiply {
    using type = Rational<R1::num * R2::num,R1::den * R2::den>;
};
template <class R1, class R2>
struct Rational_multiply : _Radional_multiply<R1, R2>::type {};

template <class R1, class R2>
struct _Radional_divide {
    using type = Rational<R1::num * R2::den,R1::den * R2::num>;
};
template <class R1, class R2>
struct Rational_divide : _Radional_divide<R1, R2>::type {};

// 피보나치

template <int N>
struct Fibonacci {
    static const int result = Fibonacci<N - 1>::result + Fibonacci<N - 2>::result;
};

template <>
struct Fibonacci<1> {
    static const int result = 1;
};

template <>
struct Fibonacci<2> {
    static const int result = 1;
};

// 소수 판별

template <int N, int D>
struct Devide {
    static const bool result = (N % D != 0) && Devide<N, D - 1>::result;
};

template <int N>
struct Devide<N, 1> {
    static const bool result = true;
};

template <int N>
struct Prime {
    static const bool result = Devide<N, N/2>::result;
};

int main() {
    cout << Factorial<5>::result << endl;
    // 대부분의 for문 등을 사용하여 구현되는 연산은 TMP로 구현 가능하다(템플릿 특수화를 쓰면 분기도 가능)
    // 하지만 컴파일 타임에 연산을 진행하기에 디버깅이 불가능(객체의 형태이긴 하나 런타임에서는 값임)
    // 그러기에 TMP는 복잡한 프로그램일수록 난이도가 매우 높아짐
    cout << GCD<36, 24>::value << endl;

    using rat1 = Rational<2, 3>;
    using rat2 = Rational<3, 2>;
    using rat3 = Rational_add<rat1, rat2>;

    cout << rat3::num << "/" << rat3::den << std::endl;

    cout << Fibonacci<10>::result << endl;

    cout << Prime<2>::result << endl;
    cout << Prime<3>::result << endl;
    cout << Prime<4>::result << endl;


    return 0;
}