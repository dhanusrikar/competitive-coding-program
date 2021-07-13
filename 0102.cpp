// Find a unique number in an array where all numbers except one are present twice.
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
    vector<int> in(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    int temp = 0;
    for (int i = 0; i < n; i++)
        temp = temp ^ in[i];
    cout << temp;
    return 0;
}
