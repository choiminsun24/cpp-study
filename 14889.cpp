#include <iostream>
#include <vector>

using namespace std;

class Team{
private:
    vector<vector<int>> data;
    vector<vector<int>> com;
    vector<int> temp;
    int N;

public:
    Team(int n, vector<vector<int>> d)
    {
        N = n;
        data = d;
    }

    void combination(int start){
        if(temp.size() == N/2){
            com.push_back(temp);
            return;
        }

        for(int i = start; i < N; i++)
        {
            temp.push_back(i);
            combination(i+1);
            temp.pop_back();
        }
    }

    int minDistance()
    {
        int min = 10000;
        for(vector<int> t:com){
            int teamT = 0;
            int teamF = 0;

            int index = 0;
            for(int i = 0; i < N; i++){
                if (t[index] == i){ //i가 teamT인 경우
                    index++;
                    for (int j : t)
                        teamT += data[i][j];
                }else{
                    int jndex = 0;
                    for(int j = 0; j < N; j++)
                    {
                        if(j == t[jndex])
                            jndex++;
                        else
                            teamF += data[i][j];
                    }
                }
            }
            //연산 마무리
            int d = abs(teamF - teamT);
            if (d < min)
                min = d;
        }

        return min;
    }
};

int main(void)
{
    //입력
    int size;
    cin >> size;

    vector<vector<int>> data;
    vector<int> temp;
    int count = 0;
    for (int d; cin >> d; )
    {
        temp.push_back(d);
        if(temp.size() == size){
            data.push_back(temp);
            temp.clear();
            count++;
        }
        if(count == size)
            break;
    }

    //처리
    Team t(size, data);
    t.combination(1); //어느팀에든 속하게 되어있으니 반만
    cout << t.minDistance();
}