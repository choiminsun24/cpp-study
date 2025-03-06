#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

int main(void)
{
    //입력
    int people;
    int fsize;
    cin >> people >> fsize;

    multimap<int, int> friendList;

    for(int i = 0; i < fsize; i++)
    {
        int a, b;
        cin >> a >> b;
        friendList.insert({a, b});
        friendList.insert({b, a});
    }

    //처리
    int answer;
    unordered_set<int> myfriend;

    //내 친구 구하기
    auto range = friendList.equal_range(1);
    for(auto i = range.first; i != range.second; i++)
        myfriend.insert(i->second);

    //친구의 친구 구하기
    unordered_set<int> copy(myfriend);

    for(int i : copy){
        range = friendList.equal_range(i);
        for(auto j = range.first; j != range.second; j++)
            myfriend.insert(j->second);
    }

    answer = myfriend.size();

    if(myfriend.count(1) > 0)
        answer--;

    cout << answer;
}
