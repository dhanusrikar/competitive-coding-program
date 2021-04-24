#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    string a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cin >> a;
        cout << "Case #" << (i + 1) << ": ";
        int dp[x];
        for (int i = 0; i < x; i++)
            dp[i] = 1;
        cout << dp[0] << " ";
        for (int i = 1; i < x; i++)
        {
            if (a[i - 1] < a[i])
                dp[i] += dp[i - 1];
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
