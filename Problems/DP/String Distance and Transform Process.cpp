///Problem Link
///https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=467
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
//ll n,k,d;
//ll mod=1e9+7;
//const int N=200005;
//ll arr[N];
//ll brr[N];
ll dp[100][100];
string a,b;
ll solve(int i,int j){
    if(j>=b.size()){
        return a.size()-i;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(i<a.size()&&a[i]==b[j]){
        int ans=solve(i+1,j+1);//equal
        dp[i][j]=ans;
        return ans;
    }
    else{//
        if(i>=a.size()){
            int ans= solve(i,j+1)+1;//add
            dp[i][j]=ans;
            return ans;
        }
        else {
            int res1= solve(i+1,j)+1;//delete
            int res2= solve(i+1,j+1)+1;//replace
            int res3= solve(i,j+1)+1;//add
            dp[i][j]=min({res1,res2,res3});
            return min({res1,res2,res3});
        }
    }
}
int add=0;
int del=0;
int cnt=1;
int cent=0;

void display(int i, int j){
    if(j>=b.size()&i>=a.size()){
        return;
    }

    if(i<a.size()&&a[i]==b[j]){
        solve(i+1,j+1);//equal
        display(i+1,j+1);
        return ;
    }
    else{//
        if(i==a.size()){
            int ans= solve(i,j+1)+1;//add
            cout<<cnt++<<" Insert "<<(i+1)+(add-del)<<','<<b[j]<<endl;
            add++;
            display(i,j+1);
            return ;
        }
        else {
            int res1= solve(i+1,j)+1;//delete
            int res2= solve(i+1,j+1)+1;//replace
            int res3= solve(i,j+1)+1;//add
            int ans=min({res1,res2,res3});
            if(ans==res1){
                cout<<cnt++<<" Delete "<<(i+1)+add-del<<endl;
                del++;
                display(i+1,j);
            }
            else if(ans==res2){
                cout<<cnt++<<" Replace "<<i+1+add-del<<','<<b[j]<<endl;
                display(i+1,j+1);
            }
            else{
                cout<<cnt++<<" Insert "<<(i+1)+(add-del)<<','<<b[j]<<endl;
                add++;
                display(i,j+1);
            }

            return ;
        }
    }



}



int main()
{
//    FAST();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=0;


    while (getline(cin,a)){
        getline(cin,b);
        if (t) cout << '\n';
        ++t;
        cnt=1;
        add=0;
        del=0;
        memset(dp,-1,sizeof dp);
        cout<<solve(0,0)<<endl;
        display(0,0);
    }





    return 0;
}