#include <iostream>
#include <vector>

using namespace std;

int meal5or3(int n)
{
    if (n%5 == 0) //5kg만 들면 됨.
        return n/5;

    for (int i = n/5; i >= 0 ; i--)
    {
        int r;
        if (i == 0) //5kg 안 들 경우
            r = n;
        else
            r = n - (i*5); //5kg로 제외된 무게

        if(r%3 == 0)
            return i + (r/3);
    }

    return -1;  //5와 3으로 불가능한 경우
}

int main(void)
{
    int target;
    cin >> target;

    cout << meal5or3(target);
}