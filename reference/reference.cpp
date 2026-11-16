#include <iostream>

using namespace std;

void reference_function(int &number) { // 참조는 대상 변수의 또 다른 이름, 따라서 기존 변수와 주소도 동일함.
    cout << "&number address = " << &number << endl;
    number++;
}

void pointer_function(int *number) { // 포인터는 참조자와 같이 기존 변수의 주소를 가리키지만 포인터 변수를 위한 메모리를 추가적으로 사용함
    cout << "*number address = " << &number << endl;
    (*number)++;
}

void reference_pointer_compare() {
    int number = 1;
    cout << "number address = " << &number << endl;
    cout << "number = " << number << endl;
    reference_function(number);
    cout << "number = " << number << endl;
    pointer_function(&number);
    cout << "number = " << number << endl;
}

int& return_local_variable_to_refint() {
    int number = 3;
    return number;
}

int& return_parameter_variable_to_refint(int &number) {
    number = 3;
    return number;
}

int return_local_variable_to_int() {
    int number = 5;
    return number;
}

void hr() {
    int i = 10; while (i--) cout << '-';
    cout << endl;
}

int main() {
    reference_pointer_compare();
    hr();
    int a = 1;
    //int &ref_a; // 컴파일 오류, 참조자는 반드시 대상 변수를 지정해야함.
    int &ref_a = a;
    int *ptr_a; // 포인터는 상관없다.
    ptr_a = &a;

    cout << "*ptr_a = " << *ptr_a << ", " << "ref_a = " << ref_a << endl;

    hr();

    int arr[3] = {1, 2, 3};
    // int &ref_arr[3] = {arr[0], arr[1], arr[2]}; // 컴파일 오류, 참조자는 주소를 가지지 못함.
    // int &ref_arr[3] = arr; // 컴파일 오류, 참조자의 배열, 참조자의 포인터, 참조자의 참조자는 존재할 수 없음.
    int (&ref_arr)[3] = arr; // 이 문법은 배열의 참조자라 가능, 앞선 코드는 int&를 가진 배열이기에 불가능
    for (int i = 0; i < 3; i++) {
        cout << "ref_arr[" << i << "] = " << ref_arr[i] << endl;
    }

    hr();

    // int &ref_function = return_local_variable_to_refint(); // 컴파일은 가능하지면 명백한 오류, 런타임 단계에서 예외가 발생하니 주의
    // 레퍼런스를 return하는 함수에서 지역변수를 반환하지 않도록 주의해야함. (댕글링 레퍼런스)
    cout << "ref_a = " << ref_a << endl;
    int &ref_function = return_parameter_variable_to_refint(ref_a);
    cout << "ref_function = " << ref_function << endl;
    // 이미 존재하는 레퍼런스를 return해주는 경우 문제없이 넘어가짐.
    // ref_function = 3;


    // int &ref_function = return_local_variable_to_int(); // 컴파일 에러, 위와 다른 점이라면 함수의 return은 함수가 끝나면 사라지기 때문에 컴파일 단계에서 막힘
    const int &ref_const = return_local_variable_to_int(); // 예외적으로 const로 선언된 참조자로 return을 받는 경우, return값의 생명이 연장된다. (참조자 해제까지)
    cout << "ref_const = " << ref_const << endl;

    return 0;
}