#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int main(void)
{
    //입력
    int v, e, start;
    cin >> v >> e >> start;

    set<int> graph[1001];
    for(int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    //처리
    //BFS
    vector<int> answerB;
    vector<bool> visitedB(1001, false);
    queue<int> bfs;

    bfs.push(start);
    answerB.push_back(start);
    visitedB[start] = true;

    while(!bfs.empty()){
        int vertex = bfs.front();
        bfs.pop();

        for(int node : graph[vertex]) //이번에 방문한 노드
        {
            if(!visitedB[node]) //처음 방문한 노드일 때
            {
                visitedB[node] = true;
                bfs.push(node);
                answerB.push_back(node);
            }
        }
    }

    //DFS
    vector<int> answerD;
    vector<bool> visitedD(1001, false);
    stack<int> dfs;

    dfs.push(start);
    answerD.push_back(start);
    visitedD[start] = true;

    while (!dfs.empty())
    {
        int vertex = dfs.top(); 
        int count = 0;
        for(int node : graph[vertex]) //이번에 탐색할 노드
        {
            if(!visitedD[node]){ //처음 방문한 노드면
                visitedD[node] = true;
                dfs.push(node);
                answerD.push_back(node);
                break;
            }
            count++;
        }
        if(count == graph[vertex].size()) //자식 노드 탐색 끝
            dfs.pop();
    }

    //출력- dfs먼저
    for(int i = 0; i < answerD.size(); i++)
        cout << answerD[i] << " ";

    cout << '\n';

    for(int i = 0; i < answerB.size(); i++)
        cout << answerB[i] << " ";
}