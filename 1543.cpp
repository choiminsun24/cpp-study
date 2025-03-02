#include <iostream>
#include <sstream>

using namespace std;

int main(void)
{
    //입력
    string str; //원문
    getline(cin, str);

    string target; //찾을 문자
    getline(cin, target);

    //처리
    int answer = 0;
    int count = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if(str[i] == target[count])
        {
            count++;
            if(count == target.size()){
                answer++;
                count = 0;
            }
        }else{
            i -= count;
            count = 0;
        }
    }

    //출력
    cout << answer;
}