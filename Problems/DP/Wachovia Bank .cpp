///Problem Link
///https://www.spoj.com/problems/WACHOVIA/en/

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
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int k,m;
int w[1005],v[1005];
int mx=0;
int dp[1005][1005];
int solve(int i,int rem){
    if(i==m||rem==0)return 0;
    if(dp[i][rem]!=-1){
        return dp[i][rem];
    }
    int res1=solve(i+1,rem);
    int res2=-1;

    if(rem-w[i]>=0)
    {
        res2=v[i]+solve(i+1,rem-w[i]);
    }
    dp[i][rem]=max(res1,res2);
    return mx=max({res1,res2});
}


int main()
{
    FAST();
    int t=1;
    cin>>t;
    while(t--)
    {
        memset(dp,-1, sizeof dp);
        cin>>k>>m;
        for (int i = 0; i < m; ++i) {
            cin>>w[i]>>v[i];
        }


        cout<<"Hey stupid robber, you can get "<<solve(0,k)<<"."<<endl;




    }
    return 0;
}