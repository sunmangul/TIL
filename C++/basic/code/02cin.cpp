#include <iostream>
using namespace std;

int main()
{
    string name;
    int age;

    cout << "이름과 나이를 공백으로 나누어 입력해 주세요 : ";
    cin >> name >> age;

    cout << name << "님의 나이는 " << age << "살 입니다." << endl; //endl = \n
    return 0;
}