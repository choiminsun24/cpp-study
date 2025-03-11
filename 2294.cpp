#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //입력
    int n, k;
    cin >> n >> k;

    vector<int> coin;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if(c <= k)
            coin.push_back(c);
    }

    //처리
    sort(coin.begin(), coin.end());

    int answer = 0;
    vector<int> min(10001, 10001);
    min[0] = 0;
    for(int i : coin)
    {
        for(int j = i; j <= k; j++)
        {
            int m = min[j-i] + 1;
            min[j] = min[j] < m ? min[j] : m;
        }
    }

    //출력
    if(min[k] == 10001)
        cout << -1;
    else
        cout << min[k];
}