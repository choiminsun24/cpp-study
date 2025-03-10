#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //입력
    vector<vector<int>> input;

    while(true){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0)
            break;
        
        vector<int> temp = {a, b, c};
        input.push_back(temp);
    }
    
    //처리
    for(vector<int> temp : input)
    {
        string answer;

        //어떤 삼각형?
        if(temp[0] == temp[1] && temp[0] == temp[2])
            answer = "Equilateral";
        else if(temp[0] == temp[1] || temp[1] == temp[2] || temp[0] == temp[2])
            answer = "Isosceles";
        else
            answer = "Scalene";

        //삼각형 맞긴한지?
        int high = temp[0] > temp[1] ? temp[0] : temp[1];
        high = high > temp[2] ? high : temp[2];

        if(high >= (temp[0] + temp[1] + temp[2] - high))
            answer = "Invalid";

        //출력
        cout << answer << '\n';
    }
}