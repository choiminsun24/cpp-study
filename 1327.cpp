#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void)
{
    //입력
    int n, k;
    cin >> n >> k;

    string str = "";
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        str += c;
    }

    //처리
    string target = str; //목표값 생성
    sort(target.begin(), target.end());

    unordered_map<string, bool> visited; //이미 방문한 노드라면 제거

    bool found = true; //답안 찾았는지
    int answer = 0; //현재 교환 횟수

    //루트 노드 탐색
    queue<string> search; //교환 대상
    if(str != target)
    {
        search.push(str);
        visited[str] = true;
        found = false;
    }
    int count = 0;

    //bfs
    while (!search.empty())
    {
        if(count == 0) //answer회 이동 모두 검사.
        {
            count = search.size();
            answer++;
        }

        //다음 문장 탐색
        string s = search.front(); search.pop();
        count--;
        for(int i = 0; i <= n-k; i++) //i부터 k개 reverse
        {
            //변환
            string new_str = s;
            string temp = s.substr(i, k);
            reverse(temp.begin(), temp.end());
            new_str.replace(i, k, temp);

            //검사
            if(new_str == target)
            {
                found = true; break;
            }else{
                if (visited.find(new_str) == visited.end()) //처음 방문한 노드
                {
                    visited[new_str] = true;
                    search.push(new_str);
                }
            }
        }

        if(found)
            break;
    }
    
    //출력
    if(found)
        cout << answer;
    else
        cout << -1;
}