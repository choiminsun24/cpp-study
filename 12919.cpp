#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

pair<int, int> target;
int targetSize;

bool promise(string str)
{
    if(str.size() <= targetSize)
        return false;
    if(count(str.begin(), str.end(), 'A') < target.first)
        return false;
    if(count(str.begin(), str.end(), 'B') < target.second)
        return false;

    return true;
}

int main(void)
{
    //입력
    string s, t;
    cin >> s >> t;

    target.first = count(s.begin(), s.end(), 'A');
    target.second = count(s.begin(), s.end(), 'B');
    targetSize = s.size();

    //처리
    bool success = false;

    stack<string> ss;
    ss.push(t);

    while(!ss.empty())
    {
        string str = ss.top(); ss.pop();

        if(str == s){
            success = true;
            break;
        }
        else if(promise(str)){
            if(str.back() == 'A')
                ss.push(str.substr(0, str.size() - 1));

            if(str.front() == 'B'){
                reverse(str.begin(), str.end());
                ss.push(str.substr(0, str.size() - 1));
            }
        }
    }

    if(success)
        cout << 1;
    else
        cout << 0;
}