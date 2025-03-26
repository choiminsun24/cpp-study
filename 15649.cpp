#include <iostream>

using namespace std;

bool visited[9] = {false, };
int n, m;
int output[9] = {0, };

void permu(int c){
    if(c == m){
        for(int i = 0; i < m; i++)
            cout << output[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            output[c] = i;
            visited[i] = true;
            permu(c+1);
            visited[i] = false;
        }
    }
}

int main(void){
    cin >> n >> m;
    permu(0);
}