#include <bits/stdc++.h>
#define ll long long
ll mod = 1e9;
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
    while (t--)
    {
        ll D, p, q, d;
        cin >> D >> d >> p >> q;
        ll sum = 0;
        ll rem = D % d;
        ll div = (D - 1) / d;
        sum = p * D;
        sum += ((q * d * div * (div + 1)) / 2);
        if(rem != 0)
            sum -= (q * div * (d-rem));
        cout << sum << endl;
    }
    return 0;
}
