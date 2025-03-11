#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void)
{
    //입력
    int t;
    cin >> t;

    vector<vector<int>> quest;
    for(int i = 0; i < t; i++)
    {
        vector<int> v(6, 0);
        cin >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];
        
        quest.push_back(v);
    }

    for(vector<int> v : quest){
        pair<int, int> p1;
        int r1;
        pair<int, int> p2;
        int r2;

        p1.first = v[0]; p1.second = v[1]; r1 = v[2];
        p2.first = v[3]; p2.second = v[4]; r2 = v[5];

        int answer;
        double between = sqrt(pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2));

        if(p1 == p2){
            if(r1 == r2)
                answer = -1;  
            else
                answer = 0;
        }
        else{
            if(between > r1+r2)
                answer = 0;
            else if(between == r1 + r2)
                answer = 1;
            else if(between > abs(r1 - r2))
                answer = 2;
            else if(between == abs(r1 - r2))
                answer = 1;
            else
                answer = 0;
        }

        cout << answer << '\n';
    }
}