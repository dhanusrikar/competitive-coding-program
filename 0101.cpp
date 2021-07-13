// 
#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;

int sum(int a, int b)
{
    if (b == 0)
        return a;
    else
        return sum(a ^ b, (a & b) << 1);
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << sum(3,4);
    return 0;
}
