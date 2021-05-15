#include <iostream>
using namespace std;

int main()
{
    int num = 2147483648;
    cout << "변수에 2147483648을 담았고 나오는 값은 " << num << "이다." << endl;
    num = -2147483648; // 직접 -2147483649 넣으면 컴파일러가 빠꾸 먹임
    num -= 1;
    cout << "변수에 -2147483649을 담았고 나오는 값은 " << num << "이다." << endl;
}