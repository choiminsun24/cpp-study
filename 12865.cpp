#include <iostream>

using namespace std;

int answer[101][100001] = {0}; //힙 메모리 용량 초과

int main(void)
{
    //입력
    int n, k;
    cin >> n >> k;

    pair<int, int> things[101] = {{0,0}, };
    for(int i = 1; i <= n; i++)
    {
        pair<int, int> temp;
        cin >> temp.first >> temp.second;
        things[i] = temp;
    }

    //처리
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= k; j++)
        {
            int weight = things[i].first;
            int worth = things[i].second;

            if(j >= weight)
                answer[i][j] = max(answer[i-1][j], answer[i-1][j-weight] + worth); //이전 값과 현재 물건 넣는 값 중 큰 것
            else   
                answer[i][j] = answer[i-1][j]; //이전 값 그대로
        }
    }

    //출력
    cout << answer[n][k];
}