#include <iostream>

using namespace std;

int main(void)
{
    //입력
    string str;
    cin >> str;

    int countA = 0; //a의 수
    for (char c : str)
        if (c == 'a')
            countA++;

    //처리
    int answer = 1000;
    for (int first = 0; first < str.size(); first++) //a를 위치시킬 공간 묶음
    {
        int b = 0; //교환해야 할 b의 수

        for (int i = 0; i < countA; i++) //묶음의 first~last
        {
            int index = first + i;
            if(index >= str.size())
                index = index%str.size();

            if(str[index] == 'b')
                b++;
        }

        if(b < answer)
            answer = b;
    }

    //출력
    cout << answer;
}