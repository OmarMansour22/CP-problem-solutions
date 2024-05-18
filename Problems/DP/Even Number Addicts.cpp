///Problem Link
///https://codeforces.com/problemset/problem/1738/C
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n,w;
ll mod=1e9+7;
const int N=100005;
ll arr[N];
ll dp[105][105][2][2];
int solve(int e,int o,bool who,int sum){

    if(o<=0 && e<=0)return sum;

    if(dp[e][o][who][sum]!=-1)return dp[e][o][who][sum];

    int res=-1;
    if(who%2==0){
        int op1=1;
        if(e>0){
            op1= solve(e-1,o,!who,(sum+2)%2==0? 0:1);
        }
        if(o>0){
            op1=min(op1, solve(e,o-1,!who,(sum+1)%2==0? 0:1));
        }
        res=op1;
    }
    else{
        int op1=-1;
        if(e>0){
            op1= solve(e-1,o,!who,sum);
        }
        if(o>0){
            op1=max(op1, solve(e,o-1,!who,sum));
        }
        res=op1;
    }

    dp[e][o][who][sum]=res;
    return res;
}


int main()
{
    FAST();
    int t=1;
    cin>>t;
    while (t--){
        memset(dp,-1,sizeof dp);
        cin>>n;
        int x=0,y=0;
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            if(arr[i]%2==0)x++;
            else y++;
        }
        if(solve(x,y,0,0))cout<<"Bob\n";
        else cout<<"Alice"<<endl;

    }





    return 0;
}