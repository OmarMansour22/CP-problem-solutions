///Problem Link
///https://codeforces.com/problemset/problem/189/A
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




int dp[10001];
int main()
{
    FAST();
    int t=1,tt=1;
//    cin>>t;

    while (t--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        const int inf=1e9;
        for (int i = 1; i <= n; ++i) {
            dp[i]=-inf;
        }


        for (int i = 1; i <=n ; ++i) {
            int ans1=-inf;
            int ans2=-inf;
            int ans3=-inf;
            if(i>=a)ans1=dp[i-a]+1;
            if(i>=b)ans2=dp[i-b]+1;
            if(i>=c)ans3=dp[i-c]+1;
            dp[i]=max({ans1,ans2,ans3});
        }

        cout<<dp[n]<<endl;
        

    }






    return 0;
}


