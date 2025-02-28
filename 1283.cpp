#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    vector<bool> check(26, false);
    vector<vector<string>> data;

    //입력
    int size;
    cin >> size;
    cin.ignore();

    for(int i = 0; i < size; i++)
    {
        string str;
        getline(cin, str);
        stringstream ss(str);

        vector<string> v;
        string word;
        while(ss >> word)
            v.push_back(word);
        
        data.push_back(v);
    }

    //처리
    vector<vector<string>> answer;

    for(vector<string> str : data)
    {
        bool complete = false;
        for(int i = 0; i < str.size(); i++) //각 단어
        {
            char c = tolower(str[i][0]); //첫 글자의 소문자
            if(check[c - 'a']) //이미 단축키가 있다면
                continue; //다음 단어

            str[i].insert(0, "[");
            str[i].insert(2, "]");
            answer.push_back(str);
            check[c-'a'] = true;
            complete = true;
            break;
        }
        if (complete) //위에서 찾았다면 아래 볼 필요x
            continue;

        for(int i = 0; i < str.size(); i++)
        {
            for(int j = 1; j < str[i].size(); j++) //각 단어의 두 번째 문자부터
            {
                char c = tolower(str[i][j]); //각 문자
                if(check[c - 'a']) //이미 단축키가 있다면
                    continue; //다음 단어

                str[i].insert(j, "[");
                str[i].insert(j+2, "]");
                answer.push_back(str);
                check[c-'a'] = true;
                complete = true;
                break;
            }
            if(complete)
                break;
        }

        if(complete)
            continue;
        
        answer.push_back(str);
    }

    //출력
    for(vector<string> str : answer)
    {
        string temp;
        for(string s: str)
        {
            temp += s + " ";
        }
        temp.pop_back();
        cout << temp + '\n';
    }
}