///Problem Link
///https://codeforces.com/problemset/problem/414/B
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
ll n,k;
ll mod=1e9+7,N=10005;
ll dp[2005][2005];
ll solve(ll i,ll rem){
    if(rem<=0){
        return 1;
    }
    if(dp[i][rem]!=-1){
        return dp[i][rem];
    }
    ll res=0;
    for (int j = i; j <=n ;j+=i ) {
        res+=solve(j,rem-1);
        res%=mod;
    }


    dp[i][rem]=res;
//    cout<<res<<endl;
    return res;
}


int main()
{
    FAST();
    cin>>n>>k;
    memset(dp,-1,sizeof dp);

    cout<<solve(1,k)<<endl;

    return 0;
}