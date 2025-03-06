#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
    //입력
    int child;
    int candy;
    vector<int> candyLength;

    cin >> child >> candy;

    long long sum = 0;

    for(int i = 0; i < candy; i++)
    {
        int l;
        cin >> l;
        candyLength.push_back(l);

        sum += l;
    }    

    //처리
    int answer = 0; //최대 길이

    int low = 1;
    long long high = sum / child;
    long long mid;

    while(low <= high)
    {
        int child0 = 0; //현재 mid값으로 나누어줄 수 있는 사탕 수

        mid = (low+high)/2;
        if(mid == 0)
            break;
        for(int i : candyLength)
            child0 += i/mid;
        
        if(child0 >= child)
        {
            answer = mid;
            low = mid + 1;
        }
        else
            high = mid -1;
    }

    //출력
    cout << answer;
}