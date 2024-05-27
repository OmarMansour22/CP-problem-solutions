///Problem Link 
///https://www.spoj.com/problems/AIBOHP/en/

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


const int mod=1e9+7;
//
//int solve(int i,int j)
//{
//    if(i>=j)return 0;
//
//    if(~dp[i][j])return dp[i][j];
//
//    if(f[i]==f[j])return dp[i][j]=solve(i+1,j-1);
//
//
//    int op1= solve(i+1,j)+1;
//    int op2= solve(i,j-1)+1;
//    int ans=min(op1,op2);
//
//    return dp[i][j]=ans;
//}



int main()
{
    FAST();
    int t=1,tt=1;
    cin>>t;
    while (t--){
        string f;
        cin>>f;
        int n;
        n=f.size();
        int dp[n+1][n+1];
        for (int i = 0; i <=n; ++i) {
            for (int j = 0; j <=n; ++j) {
                if(i>=j)dp[i][j]=0;
            }
        }

        for (int i = n-1; ~i ; --i) {
            for (int j = 1; j <n ; ++j) {
                if(i>=j){
                    dp[i][j]=0;
                    continue;
                }
                if(f[i]==f[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                    continue;
                }
                int op1=dp[i+1][j];
                int op2=dp[i][j-1];
                dp[i][j]=min(op1,op2)+1;
            }
        }
        cout<<dp[0][n-1]<<endl;



    }






    return 0;
}



