// Find a unique number in an array where all numbers except one are present thrice.
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> arr(64, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> x;
        cout << "number: ";
        cout << v[i] << endl;
        while (v[i])
        {
            x.push_back(v[i] & 1);
            v[i] = (v[i] >> 1);
        }
        cout << "binary rep: ";
        for (int j = 0; j < x.size(); j++)
        {
            cout << x[j] << " ";
            arr[j] += x[j];
        }
        cout << endl;
    }
    int temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        temp = (temp | (arr[i] % 5) << i);
        // temp = temp << 1;
    }
    cout << temp;
    return 0;
}
