///Problem Link
///https://codeforces.com/problemset/problem/1249/E
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
ll mod=1e9+7;
const int N=200005;
ll arr[N];
ll brr[N];
ll dp[N][2];
ll solve(ll i,int by){
    if(i==0){
        return 0;
    }

    if(dp[i][by]!=-1){
        return dp[i][by];
    }
    int res1= solve(i-1,0)+arr[i];
    int res2=0;
    if(by==0)
    {
        res2= solve(i-1,1)+brr[i]+k;
    }
    else{
        res2= solve(i-1,1)+brr[i];
    }
    dp[i][by]=min(res1,res2);
    return min(res1,res2);
}


int main()
{
    FAST();
    cin>>n>>k;
    memset(dp,-1,sizeof dp);
    dp[0][0]=dp[0][1]=arr[0]=brr[0]=0;
    for (int i = 1; i < n; ++i) {
        cin>>arr[i];
    }
    for (int i = 1; i < n; ++i) {
        cin>>brr[i];
    }
//    reverse(arr,arr+n-1);
//    reverse(brr,brr+n-1);

    solve(n-1,0);
    if(dp[n-1][1]==-1||(dp[n-1][0]<dp[n-1][1]))
    {
        for (int i = 0; i < n; ++i) {
            cout<<dp[i][0]<<' ';
        }
    }
    else{
        for (int i = 0; i < n; ++i) {
            cout<<dp[i][1]<<' ';
        }
    }


    return 0;
}