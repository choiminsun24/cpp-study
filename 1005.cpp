#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    //입력
    int t; //테스트 케이스 수
    cin >> t;

    vector<int> output;

    for(int tc = 0; tc < t; tc++){
        //입력
        int n, k;
        cin >> n >> k;
    
        int craftTime[1001];
        for(int j = 0; j < n; j++)
            cin >> craftTime[j+1];
        
        int depth[1001] = {0};
        vector<int> next0[1001];
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            next0[x].push_back(y);
            depth[y]++;
        }
    
        int w;
        cin >> w;

        //처리
        vector<int> answer(n+1, 0);
        queue<int> bfs;

        for (int i = 1; i <= n; i++)
        {
            if(depth[i] == 0)
                bfs.push(i);
        }

        while (!bfs.empty())
        {
            int i = bfs.front(); bfs.pop();
            for(int it : next0[i]){
                answer[it] = answer[it] < answer[i]+craftTime[i] ? answer[i]+craftTime[i] : answer[it];
                if((--depth[it]) == 0)
                    bfs.push(it);
            }
        }

        output.push_back(craftTime[w] + answer[w]);
    }

    //출력
    for(int i : output)
        cout << i << '\n';
}
