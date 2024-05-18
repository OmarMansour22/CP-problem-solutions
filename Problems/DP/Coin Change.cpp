///Problem Link
///https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=615

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

int n;
ll arr[5]={50,25,10,5,1};
ll dp[6][7490];
ll solve(int i,int rem){
    if(rem==0)
    {
        return 1;
    }
    else if(i>=5){
        return 0;
    }
    if(dp[i][rem]!=-1){
        return dp[i][rem];
    }
    int res=0;
    for (ll j = 0; j*arr[i]<=rem; ++j) {
        res+=solve(i+1,rem-(j*arr[i]));
    }
    dp[i][rem]=res;
    return res;
}


int main()
{
    FAST();
    int t=1;
//    cin>>t;
        memset(dp,-1, sizeof dp);
    while(cin>>n)
    {
        cout<<solve(0,n)<<endl;
    }
    return 0;
}