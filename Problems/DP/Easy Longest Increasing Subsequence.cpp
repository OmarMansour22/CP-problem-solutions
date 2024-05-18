///Problem Link
///https://www.spoj.com/problems/ELIS/en/

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
int arr[100];
int dp[105][105];
int solve(int i,int last){
    if(i==n)return 0;
    if(dp[i][last]!=-1){
        return dp[i][last];
    }
    int res1=solve(i+1,last);
    int res2=-1;

    if(arr[i]>last)
    {
        res2=1+solve(i+1,arr[i]);
    }
    dp[i][last]=max(res1,res2);
    return max({res1,res2});
}


int main()
{
    FAST();
    int t=1;
//    cin>>t;
    while(t--)
    {
        memset(dp,-1, sizeof dp);
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }


        cout<<solve(0,0)<<endl;




    }
    return 0;
}