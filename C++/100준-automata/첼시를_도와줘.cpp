#include<iostream>
#include<vector>
#define MAX 10000
using namespace std;

int main()
{
    int n, p;
    cin >> n;       // case 횟수 입력
    while (n--){
        cin >> p;   //선수 수 입력
        vector<pair<int, string >> s(p); // 입력값 두개의 벡터를 s라는 변수명으로 선수수만큼 초기화
        int i = 0, max = 0, res;
        while(p--)  
        {
            cin >> s[i].first >> s[i].second; // 선수정보 입력
            if(s[i].first > max)
            {
                max = s[i].first;
                res = i;
            }
            i++;
        }
        cout << s[res].second << endl;
    }
}