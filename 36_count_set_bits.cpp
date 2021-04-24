#include <bits/stdc++.h>
using namespace std;

int task(int x)
{
    int count = 0;
    while (x)
    {
        x = x & (x - 1);
        count++;
    }
    return count;
}

int main()
{
    int x;
    cin >> x;
    cout << task(x) << endl;
    return 0;
}
