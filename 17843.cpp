#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    //입력
    int n;
    cin >> n;

    vector<vector<double>> quest;
    for(int i = 0; i < n; i++)
    {
        vector<double> temp(3, 0);
        cin >> temp[0] >> temp[1] >> temp[2];
        quest.push_back(temp);
    }

    //처리
    for(vector<double> v : quest)
    {
        v[2] = v[2]*6;
        
        v[1] = (v[1]*6) + (v[2]/60);
        if(v[1] >= 360) v[1] -= 360;
        
        v[0] = (v[0]*30) + (v[1]/12);
        if (v[0] >= 360) v[0] -= 360;

        sort(v.begin(), v.end());

        double angle1 = v[1] - v[0];
        double angle2 = v[2] - v[1];
        double angle3 = 360 + v[0] - v[2];

        cout << fixed << setprecision(6) << min(min(angle1, angle2), angle3) << "\n";
    }
}