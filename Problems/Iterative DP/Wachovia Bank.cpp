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
    int t=1;
    cin>>t;
    while (t--){
        int k,n;
        int w[100],v[100];
        cin>>k>>n;
        for (int i = 0; i < n; ++i) {
            cin>>w[i]>>v[i];
        }
        /*
         * res=dp[i+1][rem];
         * res=max(res,dp[i+1][rem]+v[i]);
         * */
        int dp[2][k+1];
        for (int i = 0; i <=k; ++i) {
            dp[n&1][i]=0;
        }
        for (int i = n-1; ~i ; --i) {
            for (int j = 0; j <=k ; ++j) {
                int &res=dp[i&1][j];
                res=dp[(i+1)&1][j];
                if(j-w[i]>=0)res=max(res,dp[(i+1)&1][j-w[i]]+v[i]);
            }
        }
        cout<<"Hey stupid robber, you can get "<<dp[0][k]<<".\n";




    }






    return 0;
}


