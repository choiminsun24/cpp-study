#include <iostream>
#include <vector>

using namespace std;

int main(void){
    //피보나치 수열을 담은 배열 준비
    vector<int> one;
    vector<int> zero;

    for (int i = 0; 40 >= i; i++){
        if (i == 0){
            zero.push_back(1);
            one.push_back(0);
        }else if(i == 1){
            zero.push_back(0);
            one.push_back(1);
        }else{
            zero.push_back(zero[i-2] + zero[i-1]);
            one.push_back(one[i-2] + one[i-1]);
        }
    }

    //입력받아 해당 수열 호출
    int target;
    cin >> target; //첫번째 입력(입력 수) 무시
    while(cin >> target)
        cout << zero[target] << " " << one[target] << "\n";
}