#include <iostream>
using namespace std;

int main()
{
    float  fnum = 0.12345678901234567890; // float  타입은 소수점 6자리
    double dnum = 0.12345678901234567890; // double 타입은 소수점 16자리

    cout.precision(20);
    cout << "float  형에 저장된 값은 " << fnum << "이고," << endl;
    cout << "double 형에 저장된 값은 " << dnum << "이다." << endl;
    // 각각 소수점 6자리, 16자리 이후로 아무 쓰레기 값이 들어가는게 확인 가능
}