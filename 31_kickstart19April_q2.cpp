#include <bits/stdc++.h>
using namespace std;

/*
Sarasvati again has an array of N non-negative integers. The i-th integer of the array is Ai. She can replace at most one element in the array with any (possibly negative) integer she wants.

For an array A, Sarasvati defines a subarray as any contiguous part of A. Please help Sarasvati determine the length of the longest possible arithmetic subarray she can create by replacing at most one element in the original array.

*/

void show(long long a[], int n)
{
    // cout << endl;
    cout << "array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int long_arithmetic_subarray(long long a[], int n)
{
    int ans = 2, i, curr = 2;
    int pd = a[1] - a[0];
    // show(a, n);
    // cout << "pd: " << pd << endl;
    for (int i = 1; i < n - 1; i++)
    {
        int x = a[i + 1] - a[i];
        // cout << x << endl;
        if (pd == x)
            curr += 1;
        else
        {
            ans = max(curr, ans);
            pd = x;
            curr = 2;
        }
    }
    ans = max(curr, ans);
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        long long a[n], b[n];
        int dp[n][n - 1];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            b[j] = a[j];
            // cout << b[j] << endl;
        }
        cout << "Case #" << (k + 1) << ": ";
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n - 1; j++)
                dp[i][j] = 0;
        int diff[n - 1];
        // cout << endl
        //      << "diff => ";
        for (int i = 0; i < n - 1; i++)
        {
            diff[i] = a[i] - a[i + 1];
            // cout << diff[i] << " ";
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << "\t\t" << i << endl;
            int f;
            if (i == 0)
            {
                b[0] = a[1] + diff[1];
                // cout << "diff first = " << diff[1] << endl;
                f = long_arithmetic_subarray(b, n);
                ans = max(ans, f);
                b[0] = a[0];
            }
            else if (i == n - 1)
            {

                // cout << "diff last = " << diff[n - 2] << "\t a = " << a[n - 1] << endl;
                b[n - 1] = a[n - 2] - diff[n - 3];
                // cout << "b = " << b[n - 1] << endl;
                // cout << "\t bullshit " << b[n - 1];
                f = long_arithmetic_subarray(b, n);
                ans = max(ans, f);
                b[n - 1] = a[n - 1];
            }
            else
            {

                b[i] = a[i - 1] - diff[i - 2];
                // cout << "\t mid " << b[i];
                // cout << "diff prev = " << diff[i - 1] << " a = " << a[i] << endl;
                f = long_arithmetic_subarray(b, n);
                ans = max(ans, f);
                b[i] = a[i];

                b[i] = a[i + 1] + diff[i + 1];
                // cout << "diff next" << diff[i] << endl;
                f = long_arithmetic_subarray(b, n);
                ans = max(ans, f);
                b[i] = a[i];
            }
            // cout << endl;
        }
        // int ans = long_arithmetic_subarray(a, n);
        // cout << "ans: " << ans << endl;
        cout << ans << endl;
    }

    return 0;
}
