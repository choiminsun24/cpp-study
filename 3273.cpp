#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(void)
{
    ////입력
    int size, target;
    vector<int> sequence;

    //첫번째, 수열 크기 입력
    cin >> size;
    cin.ignore();

    //두번째, 수열 입력
    string str;

    getline(cin, str);
    stringstream ss(str);

    for(int n; ss >> n; ){
        sequence.push_back(n);
    }

    //세번째, x 입력
    cin >> target;

    ////처리
    int answer = 0;
    int first = 0; int last = size-1;

    sort(sequence.begin(), sequence.end()); //오름차순 정렬

    while (first < last)
    {
        int num = sequence[first] + sequence[last];
        if(num < target)
            first++;
        else if(num == target)
        {
            first++; last--;
            answer++;
        }else //num > target
            last--;
    }
    
    cout << answer;
}