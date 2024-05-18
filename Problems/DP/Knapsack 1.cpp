///Problem Link
///https://atcoder.jp/contests/math-and-algorithm/tasks/dp_d?lang=en

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
ll n,w;
ll mod=1e9+7;
const int N=100005;
ll arr[N];
ll brr[N];

ll dp[105][N];
ll solve(int i,int rem){

    if(i==n)return 0;

    if(dp[i][rem]!=-1)return dp[i][rem];

    ll res= solve(i+1,rem);
    if(rem-arr[i]>=0){
       res= max(solve(i+1,rem-arr[i])+brr[i],res);
    }


    dp[i][rem]=res;
    return res;
}


int main()
{
    FAST();
    int t=1;
    memset(dp,-1,sizeof dp);
    while (t--){
        cin>>n>>w;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i]>>brr[i];
        }
        cout<<solve(0,w)<<endl;
    }





    return 0;
}