#include <iostream>
using namespace std;

auto add(int x, int y)
{
    return x+y;
}

int main()
{
    auto num1 = 5.1234;
    cout << "num1(" << num1 << ")의 타입은 " << typeid(num1).name() << endl;
    auto sum = add(5, 6);
    cout << "sum("<< sum << ")의 타입은 " << typeid(sum).name() << endl;
    return 0;
}