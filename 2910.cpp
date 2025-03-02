#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<int, pair<int, int>>& p, const pair<int, pair<int, int>>& target) {
    if(p.second.first == target.second.first) //빈도가 같다면
        return p.second.second < target.second.second; //등장 순 정렬
    return p.second.first > target.second.first; //빈도 순 정렬
}


int main (void)
{
    //입력
    int size; int max;
    vector<int> sequence;
    map<int, pair<int, int>> data; //문자, <빈도, 등장 순서>

    cin >> size >> max;
    for (int temp, i = 0; i < size; i++)
    {
        cin >> temp;
        if (data.find(temp) == data.end()) //첫 등장
            data[temp] = {1, i};
        else{ //중복 등장
            data[temp].first++;
        }
    }

    // 처리 - 정렬
    vector<pair<int, pair<int, int>>> outData(data.begin(), data.end());
    sort(outData.begin(), outData.end(), compare);

    // 출력하기
    for(pair<int, pair<int, int>> p : outData){
        for(int i = 0; i < p.second.first; i++)
            cout << p.first << " ";
    }
}