#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //입력
    int k, n; //가진 수, 만들 수
    cin >> k >> n;

    vector<int> len(k); //가진 렌선의 각 길이

    long sum = 0; //도합

    for(int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        len[i] = temp;
        sum += temp;
    }

    //처리
    long high = sum/k;
    int low = 1;
    int answer = 1;

    while(low <= high)
    {
        long mid = (low + high) / 2;
        if(mid == 0)
            break;
        int n0 = 0;

        for (int i : len) //현재 길이로 구할 수 있는 렌선 수
            n0 += i/mid;

        if(n0 < n){ //high, low 갱신
            high = mid - 1;
        }else{
            answer = mid; 
            low = mid + 1;   
        }
    }

    //출력
    cout << answer;
}