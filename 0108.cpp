#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;
int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 2; i < n; i++)
    {
        if (v[i] == 0)
        {
            for (int j = (i * i); j < n; j += i)
            {
                v[j] = 1;
            }
        }
    }
    for (int i = 2; i < n; i++)
        if (v[i] == 0)
            cout << i << endl;
    return 0;
}
