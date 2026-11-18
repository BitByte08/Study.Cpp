#include <iostream>

using namespace std;

class base_class {
protected:
    string protected_b_s;
private:
    string b_s;
public:
    base_class(): b_s("base") {
        cout << "create base_class" << endl;
    }
    void whomi() {
        cout << b_s << endl;
    }
};

class derived_class: public base_class { // derived_class는 base_class를 public으로 상속받음
    //이때 상속을 protected, private로 각각 받을시 public 기준으로 protected, private로 격하된다.
private:
    string s;
public:
    derived_class(): base_class(), s("derived") {
        cout << "create derived_class" << endl;

        whomi(); // 만약 아래에서 whomi() 를 overridingrmw 하지 않았다면 base_class() 의 whomi() 를 호출한다.
        // b_s = "derived"; // 아무리 class를 public으로 상속을 받았다 하더라고 private 맴버에는 접근할 수 없다.
        protected_b_s = "derived"; // 이를 위해 protected로 지정하여 해결할 수 있다.
        // protected는 상속받은 클래스에서는 접근이 가능하고 그 이외 외부에서는 접근할 수 없다. private -> protected -> public 순서대로 접근성이 높아진다.

    }
    void whomi() {
        cout << s << endl;
    }
};

class target_class_a {
public:
    int a;
};
class target_class_b {
public:
    int b;
};

class multiple_inheritance_class: public target_class_a , public target_class_b {
public: // c++은 다중 상속을 지원한다. 이때 상속을 받을 때 동일한 이름의 함수 혹은 변수가 있다면 구분하지 못하는 문제가 있으므로 주의해야한다.(컴파일 오류)
    int c;
};

class diamond_inheritance_top {
public:
    int x;
};

class diamond_inheritance_middle_a : virtual public diamond_inheritance_top {
public:
    int a;
};

class diamond_inheritance_middle_b : virtual public diamond_inheritance_top {
public:
    int b;
};

class diamond_inheritance_bottom : public diamond_inheritance_middle_a, public diamond_inheritance_middle_b {
public:
    int y;
};

// 다음과 같은 다이아몬드 형태의 상속이 일어난 경우 최하단 class의 경우 top 클래스를 2번 상속 받는것과 동일한 효과가 나타나게 됨.
// 이로 인하여 앞에서 발생했었던 동일한 이름의 함수 혹은 변수가 선언되므로 구분하지 못하여 컴파일 에러가 뜨게 된다.
// 이를 해결하기 위해선 virtual 로 클래스를 상속받으면 해결된다.
// virtual로 상속받게 되면 컴파일러는 언제나 top 클래스를 한 번만 포함하도록 지정할 수 있게됨.
// 가상 상속시 각 생성자를 호출해야 함

int main() {
    base_class b;
    derived_class d;

    multiple_inheritance_class m;
    m.a = 3;
    m.b = 4;
    m.c = 5;
    cout << m.a << " " << m.b << " " << m.c << endl;

    diamond_inheritance_bottom db;
    db.x = 1;

    return 0;
}