///Problem Link
///https://vjudge.net/problem/POJ-1260/origin

#include<iostream>
#include "cstring"
using namespace std;


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

string f;
int n;
int num[101];
int cost[101];
int dp[101][101];
int solve(int i,int last,int sum)
{
    if(i==n){
        if(sum==0)return 0;
        return 2e9;
    }

    if(~dp[i][last])return dp[i][last];

    int op1=solve(i+1,i+1,0)+((sum+num[i]+10)*cost[i]);
    int op2=solve(i+1,last,sum+num[i]);
    int res=min(op1,op2);

    return dp[i][last]=res;
}




int main()
{
    FAST();
    int t=1,tt=1;
    cin>>t;
    while (t--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>num[i]>>cost[i];
        }

        cout<<solve(0,0,0)<<endl;

    }






    return 0;
}



