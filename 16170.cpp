#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{
    time_t now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm *time = gmtime(&now);

    cout << time->tm_year + 1900 << '\n'
        << time->tm_mon +1 << '\n'
        << time->tm_mday;
}