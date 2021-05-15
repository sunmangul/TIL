#include <iostream>
#define TEXT "Hello, World!\n"
using namespace std; //std라는 네임스페이스에 속한 정의는 그냥 사용 가능

int main()
{
    std::cout << TEXT;
    cout << "안녕, 세상!"; //std 없이 사용
    return 0;
}