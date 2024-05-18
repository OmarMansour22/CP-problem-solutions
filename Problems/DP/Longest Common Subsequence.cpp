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
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;
string a,b;
int dp[1005][1005];
int solve(int i,int j){
    if(i==a.size()||j==b.size())return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int res1=0;
    int res2=0;
    int res3=0;
    if(a[i]==b[j])
    {
        res1=1+solve(i+1,j+1);
    }
    else
    {
        res2=solve(i+1,j);
        res3=solve(i,j+1);
    }


    dp[i][j]=max({res1,res2,res3});
    return max({res1,res2,res3});
}


int main()
{
    FAST();
    int t=1;
//    cin>>t;
    while(getline(cin,a), getline(cin,b))
    {
        memset(dp,-1, sizeof dp);

        cout<<solve(0,0)<<endl;




    }
    return 0;
}