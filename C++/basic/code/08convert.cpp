#include <iostream>
using namespace std;

void input()
{
    int    num1 = 5.1234;
    int    num2 = 8.5e+12;
    double num3 = 5;

    cout << "num1의 값은 " << num1 << "," << endl;
    cout << "num2의 값은 " << num2 << "," << endl;
    cout << "num3의 값은 " << num3 << endl;
}

void calculate()
{
    double result1 = 5 + 3.14;
    double result2 = 5.0f + 3.14;

    cout << "result1의 값은 " << result1 << "입니다." << endl;
    cout << "result2의 값은 " << result2 << "입니다." << endl;
}

int main()
{
    input();
    calculate();

    return 0;
}