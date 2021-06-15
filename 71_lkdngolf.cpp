#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;
int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, x;
        cin >> n >> x >> k;
        ll rev = (n + 1 - x);
        // cout << rev << endl;
        if (x % k == 0 || rev % k == 0 || x == 0 || x == n + 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
