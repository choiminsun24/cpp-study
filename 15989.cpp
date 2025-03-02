#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    //입력
    int size;
    cin >> size;

    //처리
    vector<int> outData;

    int temp;
    for(int i = 0; i < size; i++)
    {
        cin >> temp;
        int answer = 0;
        while(temp > 3){
            answer += 1 + (temp /2);
            temp -= 3;
        }
        outData.push_back(answer + temp);
    }
    
    //출력
    for (int i = 0; i < outData.size(); i++)
    {
        cout << outData[i] << '\n';
    }
}
