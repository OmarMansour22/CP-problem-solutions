///Problem Link
///httpswww.spoj.comproblemsELISen
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
    while (t--){
        int n;
        cin>>n;
        int arr[n+1];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }

        int dp[n+1];
        for (int i = 0; i <=n; ++i) {
            dp[i]=1;
        }
        int mx=1;
        for (int i = 0; i <n ; ++i) {
            for (int j = 0; j <i; ++j) {
                int &res=dp[i];
                if(arr[i]>arr[j])res=max(res,dp[j]+1);
                mx=max(mx,dp[i]);
            }
        }
        cout<<mx;




    }






    return 0;
}


