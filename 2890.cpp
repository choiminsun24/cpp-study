#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> target)
{
    if(a.second == target.second)
        return a.first > target.first;
    
    return a.second > target.second;
}

int main(void)
{
    //입력
    int R, C;
    cin >> R >> C;
    cin.ignore();
    
    vector<string> map;
    for(int i = 0; i < R; i++)
    {
        string str;
        getline(cin, str);

        map.push_back(str);
    }

    //처리
    vector<pair<int, int>> rank;

    for(string str : map)
    {
        int distance = 0; //출발선선과의 거리
        bool isK = false; //카약이 있는지
        int num; //카약 번호
        for(char c : str)
        {
            distance++;
            if('0' <= c && c <= '9')
            {
                isK = true;
                num = c - '0';
                break;
            }
        }
        if(isK)
            rank.push_back({num, distance});
    }
    sort(rank.begin(), rank.end(), compare);

    //출력
    vector<int> rankPrnit(9);

    int r = 1; //순위
    int d = rank[0].second; //윗 순위의 남은 거리
    for(pair<int, int> a : rank)
    {   
        if(d > a.second)
            r++;
        
        rankPrnit[a.first - 1] = r;
        d = a.second;
    }

    for(int i : rankPrnit)
    {
        cout << i << '\n';
    }
}