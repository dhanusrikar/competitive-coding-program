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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> tab(n, -1);
        int mini = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (a[i] == 1)
                mini = i;
            if (mini != -1)
                tab[i] = (i - mini);
            // cout << tab[i] << " ";
        }
        // cout << endl;
        mini = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {

            if (a[i] == 2)
                mini = i;
            if (tab[i] > (mini - i) || (tab[i] == -1 && mini != INT_MAX))
                tab[i] = (mini - i);
            // cout << tab[i] << " ";
        }
        // for (auto f : tab)
        //     cout << f << " ";
        // cout << endl;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            x--;
            if (x == 0)
                cout << 0 << " ";
            else
                cout << tab[x] << " ";
        }
        cout << endl;
    }
    return 0;
}
