///Problem Link
///https://codeforces.com/gym/100247/problem/L
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
void FAST()
{
    ios_base::sync_with_stdio(0);
//    ios::sync_with_stdio(0);
//    cin.sync_with_stdio(0);
//    cout.sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n;
//ll mod=1e9+7;
//const int N=200005;
//ll arr[N];
//ll brr[N];

map<pair<ll,ll>,ll>mp;


ll solve(int x,int div){
    if(x<3)return x;

    if(mp[{x,div}]!=0)return mp[{x,div}];

    ll res=x/2+1;

    for (ll i = 2; i*i <=x ; ++i) {
        if(x%i==0){
            res=min({solve(x/i,i)*(i/2+1),solve(i,x/i)*((x/i)/2+1),res});
        }
    }
    mp[{x,div}]=res;
    return res;
}



int main()
{
    FAST();
    int t=1;
    while (t--){
        cin>>n;
        ll ans=solve(n,1);
        cout<<ans<<endl;

    }





    return 0;
}