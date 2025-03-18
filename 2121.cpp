#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    //입력
	int n, wide, height; 
	vector<pair<int, int>> list;

	cin >> n >> wide >> height;

	for (int i = 0; i < n; i++)
	{
        int x, y;
		cin >> x >> y;

		list.push_back({x, y});
	}

    //처리
	sort(list.begin(), list.end());

    int answer = 0;

	for (int lb = 0; lb < n-3; lb++)
	{
        bool ltc = false, rbc = false, rtc = false;

		//LB
		int x1 = list[lb].first;
		int y1 = list[lb].second;

		//LT
        int lt;
		for (lt = lb + 1; lt < n - 2; lt++)
		{
			int x2 = list[lt].first;
			int y2 = list[lt].second;

            if (x2 > x1) break;
			if (x2 == x1 && y2 == y1 + height) {
                ltc = true;
                break;
            }
		}

		if (!ltc) 
            continue;

		//RB
		int rb;
		for (rb = lt + 1; rb < n - 1; rb++)
		{
			int x3 = list[rb].first;
			int y3 = list[rb].second;

            if (x3 > x1 + wide) break;

			if (x3 == x1 + wide && y3 == y1)
            {
                rb = true;
                break;
            }
		}

		if(!rbc)
            continue;

		//RT
		int rt;
		for (rt = rb+1; rt < n; rt++)
		{
			int x4 = list[rt].first;
			int y4 = list[rt].second;

            if(x4 > x1 + wide)
                break;

			if (x4 == x1 + wide && y4 == y1 + height)
            {
                rt = true;
                break;
            }
		}
		if (rtc) answer++;
	}

    //출력
	cout << answer;
}

