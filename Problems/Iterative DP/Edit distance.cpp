///Problem Link
///https://www.spoj.com/problems/EDIST/en/

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



int dp[2001][2001];
int main()
{
    FAST();
    int t=1,tt=1;
    cin>>t;
    while (t--){
        string a,b;
        int n,m;
        cin>>a>>b;
        n=a.size();
        m=b.size();
        //if(i==n)return max(0,m-j);
        //if(j==m)return max(0,n-i);
        for (int i = 0; i <= n; ++i) {
            dp[n][i]=m-i;
        }
        for (int i = 0; i <= m; ++i) {
            dp[i][m]=n-i;
        }
//        int op1= solve(i+1,j)+1;
//        int op2= solve(i,j+1)+1;
//        int op3= solve(i+1,j+1)+1;
//        int res=min({op1,op2,op3});

        for (int i = n-1; ~i ; --i) {
            for (int j = m-1; ~j ; --j) {
                if(a[i]==b[j]){
                    dp[i][j]=dp[i+1][j+1];
                    continue;
                }
                int op1=dp[i+1][j+1]+1;
                int op2=dp[i+1][j]+1;
                int op3=dp[i][j+1]+1;
                dp[i][j]=min({op1,op2,op3});
            }
        }
        cout<<dp[0][0]<<endl;



    }






    return 0;
}


