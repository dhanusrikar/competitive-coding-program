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
    vector<int> v(n + 1, 1);
    for (int i = 2; i <= n; i++)
        v[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (v[j] == j)
                    v[j] = i;
            }
        }
    }
    // for (int i = 2; i < n; i++)
    //     cout << i << " " << v[i] << endl;
    while (n != 1)
    {
        cout << v[n] << " ";
        n = n / v[n];
    }
    return 0;
}
