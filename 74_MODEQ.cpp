#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll int T;cin>>T;
    while(T--)
    {    
    ll int N,M;
    cin>>N>>M;
    ll int count=0;
    //if((M%a==0)&&(M%b==0))
    vector<ll> me(N+1,1);    
    for(ll i=2;i<=N;i++)
    {
        ll a=M%i;
        count+=me[a];
        for(ll j=a;j<=N;j+=i)
            {
                    me[j]++;
            }
    }
    cout<<count<<endl;    

   }
    return 0;
}
