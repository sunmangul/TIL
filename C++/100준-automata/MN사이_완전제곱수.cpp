#include<iostream>
using namespace std;

int main()
{
    int a, b, sum=0, min=0;

    cin >> a >> b;

    for (int i = 0; i*i <= b; i++)
    {
        if(i*i >= a)
        {
            sum += i*i;
            if(min == 0)
                min = i*i;
        }
    }
    
    if(sum == 0)
        cout << -1;
    else
    {
        cout << sum << endl;
        cout << min << endl;
    }
}