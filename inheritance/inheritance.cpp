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

int main() {
    base_class b;
    derived_class d;
    return 0;
}