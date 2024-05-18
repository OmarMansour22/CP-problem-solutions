///Problem Link
///https://www.spoj.com/problems/FARIDA/en/
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
ll arr[10005];
ll dp[10005];
ll solve(int i){
    if(i>=n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }

    ll res1= solve(i+2)+arr[i];
    ll res2= solve(i+1);

    dp[i]=max(res1,res2);
//    dp[i][rem]=res;
    return max(res1,res2);
}


int main()
{
    FAST();
    int t=1,c=1;
    cin>>t;
    while(t--)
    {
        memset(dp,-1, sizeof dp);
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        cout<<"Case "<<c++<<": "<<solve(0)<<endl;
    }
    return 0;
}