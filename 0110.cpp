#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;

int MissingNumber(vector<int> &array, int n)
{
    int ans = n;
    for (int i = 0; i < n - 1; i++)
        ans = ans ^ array[i] ^ i + 1;
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
    vector<int> v(n), res;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << MissingNumber(v, n) << endl;

    return 0;
}
