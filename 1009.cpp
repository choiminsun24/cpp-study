#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //입력
    int n;
    cin >> n;
    vector<pair<int, int>> quest;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        quest.push_back({a, b});
    }

    //처리
    for(pair<int, int> temp : quest)
    {
        int data = 1;
        for(int i = 0; i < temp.second; i++)
        {
            data *= temp.first;
            data %= 10;
        }
        if(data == 0) data = 10;
        cout << data << '\n';
    }
}