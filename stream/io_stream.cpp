#include <iostream>

using namespace std;

int main () {
    int t;
    while (true) {
        cin >> t;
        // 스트림에는 4가지 플래그가 있는데,
        // goodbit < 스트림에 입출력 작업이 가능할 때
        // badbit < 스트림에 복구 불가능한 오류가 발생시
        // failbit < 스트림에 복구 가능한 오류가 발생시
        // eofbit < 입력 작업시에 EOF 도달시

        // 이때 잘못된 입력으로 타입이 맞지 않은 값이 들어올때 failbit가 켜지게 됨
        // 스트림은 입력값을 받지 않고 리턴(최신 버전에서는 0을 값으로 설정 후 값을 받지 않음)
        // 버퍼에는 여전히 잘못된 입력이 남아 있어 결론적으로 무한루프에 빠짐
        cout << t << endl;
        if (cin.fail()) { // 다음 함수를 통해 failbit의 상태를 bool 형태로 받아볼 수 있다.
            cin.clear(); // 플래그를 초기화 함.
            cin.ignore(100, '\n'); // 개행문자가 나올 때 까지 100 만큼 버퍼를 무시한다.
        }
        if (t == -1) break;
    }
    while (cin >> t) {
        // 또 다른 방안으로는 while의 조건에 입력 스트림을 넣는 방법이 있음
        // ios 내부 정의를 보면 void* 에 대한 연산자 오버로딩이 있다.
        // 이 때, NULL 포인터가 아닌 값을 리턴하는 조건이 failbit와 badbit 모두가 off일 때 이다.
        // 결국 void* -> bool 변환을 통해 NULL == false 로 잘못된 값이 들어오는 경우 안전하게 반복문을 빠져나올 수 있다.
        cout << t << endl;
        if (t == -1) break;
    }
    cin.setf(ios_base::hex, ios_base::basefield); // 다른 진법 플래그를 끄고 hex 플래그만 활성화
    cin >> t;
    cout << t;

    cin >> std::hex >> t; // 이거도 동일하게 hex를 입력받을 수 있다.

    string s;
    cin >> s;
    // streambuf는 입력과 출력 버퍼를 각각 get area, put area로 부름
    // 또한 세 개의 포인터로 버퍼의 시작부분을 가리키는 포인터, 다음으로 읽을 문자를 가리키는 포인터, 버퍼의 끝을 가리키는 포인터가 있음
    char peek = cin.rdbuf()->snextc(); // cin.rdbuf() 를 호출하면 streambuf를 가리키는 포인터를 반환함. 이때 snextc()를 호출하면 스트림의 위치 지정자를 한칸 전진시킨다.(이때 그 문자를 건드리지 않는다. 소비하지 않는다는 의미)
    if (cin.fail()) {cout << "failed";}
    cout << peek << endl;
    cin >> s;
    cout << s;

    return 0;
}