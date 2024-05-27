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
//    ios::sync_with_stdio(0);
//    cin.sync_with_stdio(0);
//    cout.sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int coins[5]={50,25,10,5,1};
ll dp[6][7489+1];

int main()
{
    FAST();
    int t=1;
//    cin>>t;
    int n;
    dp[5][0]=1;
    for (int i = 4; ~i ; --i) {
        for (int rem = 0; rem <=7489 ; ++rem) {
            ll &res=dp[i][rem];
            res=dp[i+1][rem];
            if(rem>=coins[i]) res+=dp[i][rem-coins[i]];
        }
    }
    /*
     * i==n
     *
     * op1=solve(i+1,rem)
     * op2=solve(i,rem-coins[i])? rem>=coins[i]
     * ans+=op1+op2;
     *
     */

    while (cin>>n){
        cout<<dp[0][n]<<'\n';
    }






    return 0;
}


