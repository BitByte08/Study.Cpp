#include <iostream>
#include <vector>

using namespace std;

template <typename T> // 임의의 타입 T를 사용하는 객체(템플릿)
// template <class T> // 간혹 이렇게 사용하는 경우가 있다. 동작은 동일하나 typename을 권장한다.
class Array {
private:
    T* data;
public:
    Array(int size = 0): data(new T[size]) {}
    ~Array() {delete[] data;}
    T& operator[](int i) {
        return data[i];
    }

};

template <>
class Array<string> { // 이와 같이 특정 타입에는 다른 동작을 구현할 수 있다. (템플릿 특수화)
private:
    char* data;
public:
    Array(int size = 0) : data(new char[size]) {}
    ~Array() {delete[] data;}
    char& operator[](int i) {
        return data[i];
    }
};

template <typename T>
T max_t(T a, T b) { // 함수도 가능하다.
    return a > b ? a : b;
}

template <typename T, typename C>
void sort(T& data, C& c) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = i + 1; j < data.size(); j++) {
            if (c(data[i], data[j])) { // 여기서 c는 Compare1, Compare2릐 객체로, 함수 인 척을 하는 객체를 함수 객체라 한다.
                auto temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

struct Compare1 { // 함수 객체를 사용하면 함수 포인터와 다르게 컴파일 단게에서 최적화가 가능하여 빠르게 호출될 수 있다.
    bool operator() (int a, int b) { return a > b; }
};

struct Compare2 {
    bool operator() (int a, int b) { return a < b; }
};

template <typename T, int num = 5> // 템플릿 인자(디폴트 값을 지정할 수 있다.)
T add_num(T t) { // 템플릿을 타입이 아닌 인자로도 받을 수 있다.
    // 가능한 타입은 float, double을 제외한 정수타입, 포인터 타입, enum, null 포인터를 받을 수 있다.
    return t + num;
}

template <typename T>
struct Compare {
    bool operator() (T a, T b) { return a < b; }
};

template <typename T, typename C = Compare<T>> // 디폴트 값으로 다음과 같이 지정할 수 있다.
T min_t(T a, T b) {
    C comp;
    if (comp(a, b)) {
        return a;
    }
    return b;
}

int main() {
    Array<int> array(3);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    cout << array[0] << endl;

    // Array<string> string_array(3);
    // string_array[0] = "Hello";
    // string_array[1] = "World";
    // string_array[2] = "!";
    // cout << string_array[0] << " " << string_array[1] << " " << string_array[2] << endl;

    Array<string> string_array(10);
    string_array[0] = 'H';
    string_array[1] = 'e';
    string_array[2] = 'l';
    string_array[3] = 'l';
    string_array[4] = 'o';
    for (int i = 0; i < 5; i++) {
        cout << string_array[i];
    }
    cout << endl;

    cout << max_t(3, 4) << endl;
    cout << max_t('b', 'a') << endl;


    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    Compare1 comp1;
    sort(v, comp1);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    Compare2 comp2;
    sort(v, comp2);
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    cout << add_num<int, 3>(5) << endl;
    cout << add_num<int>(3) << endl;

    cout << min_t<int, Compare<int>>(3, 4) << endl;
    cout << min_t(3, 4) << endl; // 디폴트 템플릿 인자를 사용하면 간략하게 작성할 수 있다.
}