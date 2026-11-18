#include <fstream>
#include <iostream>

using namespace std;

class Point2D {
private:
    int x, y;
public:
    Point2D(int x, int y): x(x), y(y) {}
    friend ostream & operator<<(ostream & out, const Point2D & p); // private 접근을 위한 friend 선언
};

std::ostream & operator<<(std::ostream & out, const Point2D & p) { // stream 오버로딩이 가능하다.
    out << p.x << " " << p.y;
    return out;
}

int main() {
    ifstream in("file_stream.txt"); // 여기서 두번째 인자로 ios::binary 등을 지정하면 이진의 형태로 값을 받을 수 있다. ( 옵션은 비트연산을 통해 여러 옵션을 조합할 수 있음. )
    string s;

    if (in.is_open()) {
        in >> s;
        cout << s << endl;
    } else {
        cout << "file not found" << endl;
    }

    in.close(); // ifstream은 자동으로 자원을 회수하기에 close()가 필수는 아님.( 단 다른 파일을 사용하는 경우 close() 후 다시 open()을 해야함. )
    in.open("file_stream_other.txt");

    if (in.is_open()) {
        in >> s;
        cout << s << endl;
    } else {
        cout << "file not found" << endl;
    }

    in.close();
    in.open("file_stream.txt");
    if (in.is_open()) {
        in.seekg(0, ios::end); // 위치 지정자를 파일 끝으로 옮긴다.
        int size = in.tellg(); // 그 위치를 읽는다. (파일의 총 크기)
        s.resize(size);
        in.seekg(0, ios::beg); // 위치 지정자를 파일 가장 앞으로 옮긴다.
        in.read(&s[0], size); // 파일 전체 내용을 읽어 문자열에 저장한다.
        cout << s << endl;
    } else {
        cout << "file not found" << endl;
    }

    in.close();
    s = "";

    in.open("file_stream.txt");
    if (!in.is_open()) {
        cout << "file not found" << endl;
    }
    while (in) {
        getline(in, s); //혹은 in.getline()을 사용해도 가능하다.
        cout << s << endl;
    }

    in.close();

    ofstream out("file_stream_output.txt"); // 별다른 설정이 없다면 항상 새로 덮어씀. 이때 두 번째 인자로 std::ios::app을 주게 되면 내용을 이어쓰게됨.
    s = "";
    if (out.is_open()) {
        out << "Hello";
    }
    out.close();
    out.open("file_stream_output.txt", ios::app);
    if (out.is_open()) {
        out << " World";
    }
    out.close();
    // 또한 ate 모드를 주게 될 경우 중간에 문자를 끼워넣을 수 있다. 이때 seekp를 이용하면 위치 지정자를 이동시킬 수 있다.
    Point2D p(3, 4);
    out.open("file_stream_output.txt", ios::app);
    if (out.is_open()) {
        out << endl << p;
    }

    return 0;
}