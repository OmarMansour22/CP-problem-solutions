///Problem Link
///https://atcoder.jp/contests/dp/tasks/dp_g?lang=en
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
ll n,m;
ll mod=1e9+7;
const int N=100005;
ll arr[N];
ll brr[N];
vector<int>v[100005];
ll dp[N];
ll solve(int i){

    if(i==n+1)return 0;

    if(dp[i]!=-1)return dp[i];

    ll res=0;
    for(auto ch:v[i]){
        res= max(res,solve(ch)+1);
    }


    dp[i]=res;
    return res;
}


int main()
{
    FAST();
    int t=1;
    memset(dp,-1,sizeof dp);
    while (t--){
        cin>>n>>m;
        vector<int>in(n+2,0);
        for (int i = 0; i < m; ++i) {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            in[y]++;
        }
        ll ans=0;
        for (int i = 1; i <=n ; ++i) {
            if(in[i]==0){
                ans=max(ans,solve(i));
            }
        }
        cout<<ans;
    }





    return 0;
}