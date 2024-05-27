///Problem Link
///https://codeforces.com/problemset/problem/166/E

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


ll n;
const int mod=1e9+7;




int dp[4][10000001];
int main()
{
    FAST();
    int t=1,tt=1;
//    cin>>t;
    while (t--){
        cin>>n;
        dp[0][0]=1;
        for (int j = 1; j<=n ; ++j) {
            for (int i = 0; i <4; ++i) {
                int &res=dp[i][j];
                ll a=dp[(i+1)%4][j-1];
                ll b=dp[(i+2)%4][j-1];
                ll c=dp[(i+3)%4][j-1];
                res=(a+b+c)%mod;
            }
        }
        int ans=dp[0][n];
      
        cout<<ans;




    }






    return 0;
}


