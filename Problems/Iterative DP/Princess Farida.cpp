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
//    ios::sync_with_stdio(0);
//    cin.sync_with_stdio(0);
//    cout.sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




int main()
{
    FAST();
    int t=1,tt=1;
    cin>>t;

    while (t--){
        int n;
        cin>>n;
        ll coins[n+1];
        for (int i = 0; i < n; ++i) {
            cin>>coins[i];
        }
        ll dp[n+2];
        dp[n]=0;
        dp[n+1]=0;
        for (int i = n-1; ~i; --i) {
            dp[i]=max(dp[i+1],dp[i+2]+coins[i]);
        }
        cout<<"Case "<<tt++<<": "<<dp[0]<<endl;

        /*
         * i==n
         *
         * op1=solve(i+1)
         * op2=solve(i+2)+coins[i]
         * ans=max op1,op2;
         *
         */

    }






    return 0;
}


