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
    ll t;
    cin >> t;
    ll mod = 1e9 + 7;
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = 1;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        ll diff = n - 1;
        while (diff > 0)
        {
            ll x = 2;
            ll f = 2;
            while (f <= diff)
            {
                x = ((x % mod) * (x % mod)) % mod;
                f = f * 2;
            }
            f = f / 2;
            diff -= f;
            ans = ((ans % mod) * (x % mod)) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
