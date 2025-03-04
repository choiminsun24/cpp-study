#include <iostream>

using namespace std;

int main(void)
{
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        int score;
        cin >> score;

        if (score >= 40)
            sum += score;
        else
            sum += 40;
    }

    cout << sum/5;
}