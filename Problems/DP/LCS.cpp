///Problem Link
///https://atcoder.jp/contests/dp/tasks/dp_f?lang=en
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
ll n;
//ll mod=1e9+7;
//const int N=200005;
//ll arr[N];
//ll brr[N];

string a,b;
ll dp[3005][3005];
ll solve(int i,int j){
    if(i>=a.size()||j>=b.size())return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    ll res=0;
    if(a[i]==b[j]){
        res= solve(i+1,j+1)+1;
    }
    else{
        res=max({res, solve(i+1,j), solve(i,j+1),res});
    }
    dp[i][j]=res;
    return res;
}

void display(int i,int j){
    if(i>=a.size()||j>=b.size())return;


    if(a[i]==b[j]){
        cout<<a[i];
        display(i+1,j+1);
    }
    else{
        ll res1=solve(i+1,j);
        ll res2=solve(i,j+1);
        if(res1>=res2){
            display(i+1,j);
        }
        else{
            display(i,j+1);
        }
    }
}


int main()
{
    FAST();
    int t=1;
    memset(dp,-1,sizeof dp);
    while (t--){
        cin>>a>>b;
        display(0,0);

    }





    return 0;
}