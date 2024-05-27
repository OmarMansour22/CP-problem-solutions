///Problem Link
///https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1346


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
//    cin>>t;
    string a,b;
    while (getline(cin,a)&& getline(cin,b)){
        int n=a.size();
        int m=b.size();

        int dp[2][m+1];
        for (int i = 0; i <=m; ++i)dp[n&1][i]=0;
        for (int i = 0; i <2; ++i)dp[i&1][m]=0;

        for (int i = n-1; ~i ; --i) {
            for (int j = m-1; ~j ; --j) {
                if(a[i]==b[j])dp[i&1][j]=dp[(i+1)&1][j+1]+1;
                else{
                    int op1=dp[(i+1)&1][j];
                    int op2=dp[i&1][j+1];
                    dp[i&1][j]=max(op1,op2);
                }
            }
        }

        cout<<dp[0][0]<<endl;
        /*
         * i==n || j==m
         *
         * a[i]==b[j]: i++,j++;
         * op1=solve(i+1,j)
         * op2=solve(i,j+1)
         *
         */
        
    }






    return 0;
}


