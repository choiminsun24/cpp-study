#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //초기값, 0번 인덱스 제외
    vector<bool> result = {true, true, false, true, true};

    //입력
    int target;
    cin >> target;
    
    //연산
    for(int i = 5; i <= target; i++){
        if(result[i -1] && result[i - 3] && result[i - 4])
            result.push_back(false);
        else
            result.push_back(true);
    }

    //출력
    if(result[target])
        cout << "SK";
    else
        cout << "CY";
}