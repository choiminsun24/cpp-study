#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int main(void)
{
    //입력
    int n, k;
    cin >> n >> k;

    //처리
    unordered_map<int, bool> visited;
    int sec = 0;
    int distance;

    queue<int> search;
    if(n < k){
        search.push(n);
        visited[n] = true;
        distance = k - n;
    }
    else
        sec = n - k;

    int sibling = 1;
    while(!search.empty())
    {
        if(sibling == 0)
        {
            sibling = search.size(); sec++;
        }
        
        int now = search.front(); search.pop(); sibling --;
        if(now == k)
            break;
        

        if(now - 1 >= 0 && visited.find(now - 1) == visited.end()){
            search.push(now-1);
            visited[now-1] = true;
        }
        if(now + 1 <= 100000 && visited.find(now + 1) == visited.end()){
            search.push(now+1);
            visited[now+1] = true;
        }
        if(2*now <= 100000 && visited.find(now*2) == visited.end() && now < k+distance){
            search.push(2*now);
            visited[now*2] = true;
        }
    }

    //출력
    cout << sec;
}