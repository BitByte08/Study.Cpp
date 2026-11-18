#include <iostream>

using namespace std;

class static_member_class {
private:
    static int static_member; // static_member_class 안에 있는 모든 함수에서 접근 가능한 static 변수(static_member_class 객체끼리 공유함)
    // inline static int static_member; // 다음과 같은 문법으로 초기화까지 한번에 가능함 c++17
public:
    static_member_class() = default;

    void count_static_member();
    void count_function_static_member();
};

void static_member_class::count_static_member() {
    static_member++;
    cout << static_member << endl;
}

int static_member_class::static_member = 0; // 외부에서 초기화를 한번 해줘야함.

void static_member_class::count_function_static_member() {
    static int function_static_member; // count_function_static_member 안에서 접근 가능한 static 변수(static_member_class 객체끼리 공유함)
    function_static_member++;
    cout << function_static_member << endl;
}

class Server {
private:
    mutable class Cache {
    private:
    public:
        void update() {};
    } cache;
public:
    void update() const {
        cache.update(); // const 함수에서 맴버 변수 변경은 불가능( const T& )
        // 하지만 위와 같이 특정한 상황에서 const 함수 내부에서 변경하기 위해 mutable 키워드를 사용할 수 있음.
        // mutable 키워드는 간략하게 설명하자면 const 함수 내부에서 맴버 변수에 const가 아닌 작업을 할 수 있게 해줌.
    }
};

int main() {
    static_member_class smc1;
    static_member_class smc2;

    smc1.count_static_member();
    smc1.count_function_static_member();

    smc2.count_static_member();
    smc2.count_function_static_member();

}