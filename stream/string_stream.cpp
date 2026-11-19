#include <iostream>
#include <sstream>

using namespace std;

int main() {
    istringstream iss("3"); // 문자열을 입력 스트림으로 가상화
    int s;
    iss >> s; // 이런 방법으로 형변환도 가능함
    cout << s << endl;

    int n = 3;
    ostringstream oss; // 출력 스트림으로 가상화
    oss << n; // 반대로도 가능함
    cout << oss.str() << endl;

}