#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;

int maxConsecutiveOnes(int N)
{
    // code here
    int ans = 0, count = 0;
    while (N)
    {
        if (N & 1)
        {
            count++;
            ans = max(ans, count);
        }
        else
            count = 0;
        N = N >> 1;
    }
    return ans;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n;
    maxConsecutiveOnes(n);
    return 0;
}
