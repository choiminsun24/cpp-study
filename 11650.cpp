#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> p, pair<int, int> target){
    if(p.first == target.first)
        return p.second < target.second;
    return p.first < target.first;
}

int main(void)
{
    //입력
    int size;
    cin >> size;

    vector<pair<int, int>> N;

    for(int i = 0; i < size; i++)
    {
        int x, y;
        cin >> x >> y;
        pair<int, int> temp(x, y);
        N.push_back(temp);
    }

    //정렬

    // 선택 정렬
    // for(int i = 0; i < size; i++) //작은 수가 올 자리
    // {
    //     int x = N[i][0]; int y = N[i][1];

    //     int index = i;
    //     for(int j = i+1; j < size; j++) //작은 수
    //     {
    //         if (N[index][0] > N[j][0])
    //             index = j;
    //         else if(N[index][0] == N[j][0]){
    //             if(N[j][1] < N[index][1])
    //                 index = j;
    //         }  
    //     }
    //     swap(N[i], N[index]);
    // }

    // 버블 정렬
    // for(int i = size - 1; i >= 0; i--) //마지막 인덱스
    // {
    //     for(int j = 0; j < i; j++) //비교 대상
    //     {
    //         if(N[j].first > N[j+1].first)
    //             swap(N[j], N[j+1]);
    //         else if(N[j].first == N[j+1].first)
    //             if(N[j].second > N[j+1].second)
    //                 swap(N[j], N[j+1]);
    //     }
    // }
    
    // sort
    sort(N.begin(), N.end(), compare);

    //출력
    for(pair<int, int> v : N){
        cout << v.first << " " << v.second << "\n";
    }
}