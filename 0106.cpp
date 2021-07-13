#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;

vector<int> singleNumber(vector<int> nums)
{
    int temp = 0;
    for (int i = 0; i < nums.size(); i++)
        temp = temp ^ nums[i];
    int t = temp, count = 0;
    count = temp & ~(temp - 1);
    int x = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count & nums[i])
            x = x ^ nums[i];
    }
    count = x ^ temp;

    vector<int> result = {min(count, x), max(count, x)};
    return result;
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
    res = singleNumber(v);
    for (auto i : res)
        cout << i << endl;

    return 0;
}
