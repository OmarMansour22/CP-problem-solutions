///Problem Link
///https://atcoder.jp/contests/dp/tasks/dp_e?lang=en

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
ll n,cap;
const int N=100001;
ll w[N],v[N];
ll dp[101][N];
ll solve(int i,int c){
    if(i==n){
        return c? inf:0;
    }
    if(~dp[i][c])return dp[i][c];
    
    ll &res=dp[i][c];
    
    ll op1= solve(i+1,c);
    ll op2=inf;
    if(v[i]<=c){
        op2=solve(i+1,c-v[i])+w[i];
    }
    res=min(op1,op2);
    return res;
}


int main()
{
    FAST();
    int t=1;
//    cin>>t;
    while (t--){
        memset(dp,-1,sizeof dp);
        cin>>n>>cap;
        for (int i = 0; i < n; ++i) {
            cin>>w[i]>>v[i];
        }

        for (int i = 100000; i >=0 ; --i) {
            ll ans= solve(0,i);
            if(ans<=cap){
                cout<<i;
                return 0;
            }
        }


    }





    return 0;
}