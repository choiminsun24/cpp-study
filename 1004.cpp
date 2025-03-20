#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
    //입력
    int t;
    cin >> t;

    vector<vector<pair<int, int>>> coord;
    vector<vector<vector<int>>> planet;

    for(int i = 0; i < t; i++)
    {
        //출발, 도착 좌표 입력
        vector<pair<int, int>> coordTemp;
        pair<int, int> start, finish;

        cin >> start.first >> start.second
            >> finish.first >> finish.second;

        coordTemp.push_back(start);
        coordTemp.push_back(finish);

        coord.push_back(coordTemp);

        //각 행성 정보 입력
        int n;
        cin >> n;

        vector<vector<int>> planetTemp;
        for(int j = 0; j < n; j++)
        {
            vector<int> p(3);
            cin >> p[0] >> p[1] >> p[2];
            
            planetTemp.push_back(p);
        }

        planet.push_back(planetTemp);
    }

    //처리
    for(int i = 0; i < t; i++)
    {
        int answer = 0;

        //좌표 꺼내기
        pair<int, int> start, finish;
        start = coord[i][0]; finish = coord[i][1];

        //행성 꺼내기
        for(vector<int> p : planet[i])
        {
            int xs = abs(start.first - p[0]);
            int ys = abs(start.second - p[1]);
            double rs = sqrt(pow(xs, 2) + pow(ys, 2));

            int xf = abs(finish.first - p[0]);
            int yf = abs(finish.second - p[1]);
            double rf = sqrt(pow(xf, 2) + pow(yf, 2));

            if((p[2] > rs && p[2] < rf) || p[2] < rs && p[2] > rf) //행성에 출발점만 있거나 도착점만 있음.
                answer++;
        }

        cout << answer << '\n';
    }
}