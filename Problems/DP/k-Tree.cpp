///Problem Link
///https://codeforces.com/problemset/problem/431/C
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
ll n,k,d;
ll mod=1e9+7,N=10005;
ll dp[105][105][105];
ll solve(ll i,ll rem,ll num){
    if(rem==0){
        return num? 1:0;
    }

    if(dp[i][rem][num]!=-1){
        return dp[i][rem][num];
    }
    ll res=0;
    for (int j = 1; j <=k ;j++ ) {
        if(rem-j>=0)
        {
            if(j>=d)res+=solve(j,rem-j,1);
            else res+=solve(j,rem-j,num);
        }
        res%=mod;
    }


    dp[i][rem][num]=res;
    return res;
}


int main()
{
    FAST();
    cin>>n>>k>>d;
    memset(dp,-1,sizeof dp);

    cout<<solve(0,n,0)<<endl;

    return 0;
}