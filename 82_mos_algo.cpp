#include <bits/stdc++.h>
#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
using namespace std;

bool sortBySec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

ll cnt[1000];
ll current_ans = 0;

void add(ll x)
{
    current_ans -= cnt[x] * cnt[x] * x;
    cnt[x]++;
    current_ans += cnt[x] * cnt[x] * x;
}

void remove(ll x)
{
    current_ans -= cnt[x] * cnt[x] * x;
    cnt[x]--;
    current_ans += cnt[x] * cnt[x] * x;
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m;
    cin >> n >> m;
    ll block_size = sqrt(n);
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<pair<ll, ll>> query;
    for (ll i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        pair<ll, ll> x;
        x = make_pair(l, r);
        query.push_back(x);
    }
    vector<vector<pair<ll, ll>>> mo_order(block_size + 1);
    // sending into groups
    for (auto x : query)
    {
        pair<ll, ll> q = x;
        ll f = q.first / block_size;
        cout << "\t" << f << endl;
        // cout << q.first << " " << q.second << " " << f << endl;
        mo_order[f].push_back(q);
    }

    // sorted the groups accourding to right element
    for (auto i : mo_order)
    {
        cout << "\t wew" << endl;
        sort(i.begin(), i.end(), sortBySec);
        for (auto x : i)
        {
            cout << x.first << " " << x.second << endl;
        }
    }

    ll mo_left = 0, mo_right = -1;
    cout << "ans" << endl;
    for (auto i : mo_order)
    {
        for (auto x : i)
        {
            ll r = x.second;
            ll l = x.first;
            while (mo_right < r)
            {
                // extend current segment to [mo_left, mo_right+1]
                mo_right++;
                add(arr[mo_right]);
            }

            while (mo_right > r)
            {
                // cut current segment to [mo_left, mo_right-1]
                remove(arr[mo_right]);
                mo_right--;
            }

            while (mo_left > l)
            {
                // extend current segment to [mo_left - 1, mo_right]
                mo_left--;
                add(arr[mo_left]);
            }
            while (mo_left < l)
            {
                // cut current segment to [mo_left + 1, mo_right]
                remove(arr[mo_left]);
                mo_left++;
            }

            // cout << current_ans << endl;
        }
    }

    return 0;
}

/*
18 7
0 1 1 0 2 3 4 1 3 5 1 5 3 5 4 0 2 2
0 8
2 5 
2 11
16 17
13 14
1 17
17 17
*/
