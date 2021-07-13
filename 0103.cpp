#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
ll mod = 1e9 + 7;
using namespace std;

unsigned int reverseBits(unsigned int n)
{
    int x = 0;
    while (n)
    {
        x = ((x << 1) | (n & 1));
        n = n >> 1;
    }
    return x;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // int arr[4] = {1, 2, 3, 4};
    char arr[3] = {'a', 'b', 'c'};
    subsets(arr, 3);
    return 0;
}
