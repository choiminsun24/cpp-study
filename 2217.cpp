#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //입력
    int size;
    cin >> size;

    vector<int> rope;
    for (int g, i = 0; i < size; i++)
    {
        cin >> g;
        rope.push_back(g);
    }

    //처리
    int max = 0;

    sort(rope.begin(), rope.end());

    for(int temp, i = 0; i < size; i++)
    {
        temp = rope[i] * (size-i);
        if(temp > max){
            max = temp;
        }
    }

    //출력
    cout << max;
}