#include <cstring>
#include <iostream>

using namespace std;

class Person {
private:
    char* name_;
public:
    Person();
    Person(const char* name);
    void print();
    ~Person();
};

Person::Person() {
    name_ = NULL;
}
Person::Person(const char* name) {
    name_ = new char[100];
    strcpy(name_, name);
}

void Person::print() {
    cout << name_ << endl;
}

Person::~Person() { // 소멸자는 인자를 가지지 않고, 오버로딩 될 수 없다.
    cout << "Destructor" << endl;
    if (name_ != NULL) delete[] name_;  // name_이 char배열로 동적 할당 되었기에 delete[] 로 해제한다.
}

int main() {
    Person p("Person"); // 다음과 같은 코드를 실행하였을 때 문제는 자원이 회수가 되지 않는, 메모리 누수가 발생함. 이를 소멸자로 해결할 수 있음.
    p.print();
    return 0;
}