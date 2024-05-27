///Problem Link
///https://codeforces.com/contest/474/problem/D

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

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll mod=1e9+7,inf=1e9+7;
ll n,cap,m,a,b;
const int N=200005;

ll dp[N];
ll solve(ll cnt){

    if(cnt<=0)return 0;


    if(~dp[cnt])return dp[cnt];

    ll op1= 0;
    if(cnt-1>=0) op1=solve(cnt-1)+1;
    ll op2= 0;
    if(cnt-m>=0) op2=solve(cnt-m)+1;
    ll &res=dp[cnt];
    op1%=mod;
    op2%=mod;
    res=(op1+op2)%mod;

    return res;
}


int main()
{
    FAST();
    int t=1;
//    cin>>t;
    cin>>t>>m;
    memset(dp,-1,sizeof dp);
    solve(100001);
    dp[0]=0;
    while (t--){
        cin>>a>>b;

        cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;

        
//        cout<<dp[0]<<' '<< dp[1]<<' '<<dp[2]<<' '<<dp[3]<<' '<<dp[4]<<' '<<dp[5]<<endl;


    }





    return 0;
}