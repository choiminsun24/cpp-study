#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //입력
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> road[10001];
    for(int i = 0; i < N; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        road[end].push_back({start, cost}); 
    }

    //처리
    vector<int> minCost(10001);
    minCost[1] = 1;
    for(int i = 2; i <= D; i++)
    {
        int min = minCost[i-1] + 1;

        for(int j = 0; j < road[i].size(); j++)
        {
            int useIt = minCost[road[i][j].first] + road[i][j].second;
            min = min < useIt ? min : useIt; //더 작은 쪽
        }

        minCost[i] = min;
    }

    //출력
    cout << minCost[D];
}