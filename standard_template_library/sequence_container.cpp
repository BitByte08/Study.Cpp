#include <deque>
#include <iostream>
#include <ostream>
#include <vector>
#include <list>

using namespace std;

template <typename T>
void vector_print(vector<T>& vec) {
    for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++) { // iterator는 vector<T>의 의존타입이므로 typename 선언
        cout << *it << endl;
    }
}

void vector_container() {
    vector<int> v; // 메모리에 순차적으로 저장되는 컨테이너
    v.push_back(1); //O(1) (단 기존 할당된 메모리가 부족할땐 O(n)
    v.pop_back(); // O(1)
    v.insert(v.begin(), 30); // O(n)
    v.erase(v.begin(), v.end()); // O(n)

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it; // vector의 반복자, 컨테이너의 원소에 접근할 수 있는 포인터와 같은 객체
    it = v.begin();
    for (; it != v.end(); it++) {
        cout << *it << endl; // 실제 포인터는 아님 연산자 오버로딩이 되어있음.
    }
    vector_print(v);
    v.push_back(1);

    it = v.begin();
    vector<int>::iterator it_end = v.end();
    for (; it != it_end; it++) { // 디버그 모드로 컴파일시 런타임 에러, 반복자의 경우 insert, erase등의 연산이 일어나면 유효한 반복자가 아니기 때문(release로 변경하면 동작은 가능) 따라서 위와 같이 end로 받아야함.
        if (*it == 3) {
            v.erase(it);
        }
    }

    vector<int>::const_iterator cit = v.cbegin(); // 상수 반복자도 있다. (읽기 전용)

    vector<int>::reverse_iterator rit = v.rbegin(); // 역반복자도 있다. begin이 end를 가리킴
    for (; v.rend() != rit; cit++) { // 증가할수록 첫번째 원소 방향으로 이동함.
        cout << *cit << endl;
    }

    for (int i: v) { // 범위 기반 for 문(python의 in과 비슷함) 복사가 일어난다.
        cout << i << endl;
    }
    for (const int& i: v) { // 참조로도 받아 최적화를 할 수 있다.
        cout << i << endl;
    }

    vector_print(v);
}

void list_container() {
    list<int> l; // linked-list, 원소들이 양방향으로 링크된 자료형
    l.push_back(1); // 항상 O(1)의 속도를 가진다.
    l.pop_back(); // 항상 O(1)의 속도를 가진다.
    l.insert(l.begin(), 30); // 어느 위치여도 항상 O(1)의 속도를 가진다.
    l.erase(l.begin(), l.end()); // 어느 위치여도 항상 O(1)의 속도를 가진다.

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    // list는 vector와 다르게 메모리에 순차적으로 저장되지 않아 배열 연산자나 at을 지원하지 않는다. 따라서 데이터를 찾는 속도는 O(n)이다.
    for (list<int>::iterator itr = l.begin(); itr != l.end(); ++itr) { // list의 반복자는 증감연산만 가능하다. itr+5 와 같은 연산은 불가능.
        // 그 이유는 앞에서 나온 이유와 동일하게 메모리에 순차적으로 저장되는 구조가 아니다보니 링크되어 있는 요소를 따라가야하기 때문에 하나하나 움직어야 하기 때문.
        cout << *itr << endl;
    }
    for (list<int>::iterator itr = l.begin(); itr != l.end(); ++itr) {
        if (*itr == 3) {
            l.erase(itr); // 이와 같이 삭제를 진행해도 vector와 다르게 반복자가 무효화 되지 않는다. 각 원소의 주소값은 변하지 않기 때문.
            break;
        }
    }
}

void deque_container() {
    deque<int> d;
    d.push_back(1); // O(1) 속도로 수행한다.
    d.pop_back(); // O(1) 속도로 수행한다.
    d.push_front(30); // O(1) 속도로 수행한다.
    d.pop_front(); // O(1) 속도로 수행한다.
    d.insert(d.begin(), 30); // O(n) 속도로 수행한다.
    d.erase(d.begin(), d.end()); // O(n) 속도로 수행한다.

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    cout << d[2] << endl; // 배열 연산자로 접근이 가능하다.
    // deque는 vector와 다르게 원소들을 일정 크기로 잘라서 각각의 블록에 존재함 (성능을 위해 많은 메모리를 사용)
}

int main() {
    // vector_container();
    list_container();
}