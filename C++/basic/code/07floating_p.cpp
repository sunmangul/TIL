#include <iostream>
using namespace std;

int main()
{
    int i;
    float sum = 0;

    for (i=0; i<1000;i++)
    {
        sum += 0.1;
    }

    // 부동 소수점으로 실수를 표현할 때 방생하는 오류
    // 1000번 더했으나 99.999가 나옴(1001번 하면 100.099)
    cout << "0.1을 1000번 더한 합계는 " << sum << "입니다" << endl;
    return 0;
}