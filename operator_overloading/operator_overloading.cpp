#include <iostream>
#include <vector>

using namespace std;

class Point2D {
private:
    int x, y;
public:
    explicit Point2D(int _x, int _y) : x(_x), y(_y) {}

    int get_x() const { return x; }
    int get_y() const { return y; }

    Point2D operator + (const Point2D &p) { // 호출 시 복사를 막기 위해 참조로 원본 객체를 받아온다.
        return Point2D(x + p.x, y + p.y); // 생성자가 명시적으로 선언되어 있기 때문에 암시적으로 생성할 수 없다.
    }

    Point2D& operator += (const Point2D &p) { // (p1 += p2) += p3; 와 같은 코드에서 복사본을 반환하면 원본에 다음 연산이 반영되지 않으므로 참조를 반환한다.
        x += p.x;
        y += p.y;
        return *this;
    }

    Point2D& operator ++ () { // operator +=와 동일하다. ++(++p1); 와 같은 코드에서 복사본을 반환하면 원본에 다음 연산이 반영되지 않으므로 참조를 반환한다.
        ++x;
        ++y;
        return *this;
    }

    Point2D& operator ++ (int) { // operator ++와 동일하다. (p1++)++; 와 같은 코드에서 복사본을 반환하면 원본에 다음 연산이 반영되지 않으므로 참조를 반환한다.
        return ++(*this);
    }

    bool operator == (const Point2D &p) const { // 비교 연산자는 bool을 반환함
        return x == p.x && y == p.y;
    }

    bool operator != (const Point2D &p) const { // 기존에 먼저 오버로딩한 == 연산자를 활용
        return !(*this == p);
    }

    friend Point2D operator - (const Point2D &argL, const Point2D &argR); // 클래스 내부에 있는 모든 맴버에 접근 가능하게 프렌드로 지정 ( 캡슐화를 깨는 안티패턴이기 때문에 지양하기 )

    operator string() const { // 타입 변환 연산자 오버로딩
        return "(string) x: " + to_string(x) + " y: " + to_string(y);
    }

    void HelloWorld() {
        cout << "Hello World!" << '\n';
    }

};

class PointPrint {
public:
    void operator() (const Point2D &p) { // 함수 호출 오버로딩 ( 여러 인자를 받을 수 있음 )
        cout << "(PointPrint) x: " + to_string(p.get_x()) + " y: " + to_string(p.get_y()) << '\n';
    }
};

class PointArray {
private:
    vector<Point2D> points;
public:
    void push_back(const Point2D &p) {
        points.push_back(p);
    }
    void pop_back() {
        points.pop_back();
    }

    Point2D operator[] (int i) const { // 인덱스 연산자 오버로딩 ( const 키워드를 사용하여 연산의 범위를 지정할 수 있음 )
        return points[i];
    }
};

std::ostream& operator << (std::ostream& os, const Point2D &p) {
    os << p.get_x() << " " << p.get_y();
    return os;
}

class Point2D_ptr {
private:
    Point2D *p;
public:
    Point2D_ptr(Point2D *_p) : p(_p) {}
    ~Point2D_ptr()
    {
        delete p;
    }
    Point2D* operator -> () { // 접근 연산자 오버로딩
        return p;
    }
};

Point2D operator - (const Point2D &argL, const Point2D &argR) { // 전역함수를 이용한 연산자 오버로딩
    return Point2D(argL.x - argR.x, argL.y - argR.y);
}

int main() {
    PointPrint pout;
    Point2D p1(1, 2);
    Point2D p2(3, 4);
    Point2D p3(5, 6);
    cout << &p2 << '\n';

    (p1 += p2) += p3;
    cout << (string)p1 << '\n';
    pout(p1);
    (p2++)++;
    cout << (string)p2 << '\n';
    pout(p2);

    cout << (p2 == p3) << '\n';
    cout << (p2 != p3) << '\n';

    p2 = p2 - p3;
    cout << (string)p2 << '\n';
    // pout(p2);
    cout << p2 << endl;

    PointArray parray;

    parray.push_back(p1);
    parray.push_back(p2);
    parray.push_back(p3);

    pout(parray[1]); // p2 를 출력
    cout << (parray[1] == p2)<< '\n';

    Point2D *p_p1 = new Point2D(1, 2);
    Point2D_ptr p_p2 = new Point2D(2, 3);

    p_p1->HelloWorld();
    p_p2->HelloWorld();

    delete p_p1;

    return 0;
}