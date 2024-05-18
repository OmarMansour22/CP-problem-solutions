///Problem Link
///https://codeforces.com/problemset/problem/545/C
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

ll dp[100005];
ll frq[100005];
ll solve(ll i){
    if(i>=100001){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }


    ll res1=0;
    res1=solve(i+2)+(frq[i]*i);

    ll res2= solve(i+1);
    ll res=max(res1,res2);
    dp[i]=res;

    return res;
}


int main()
{
    FAST();
    int t=1;
//    cin>>t;
    while(t--)
    {
//        memset(dp,-1,sizeof dp);
        int n;
        cin>>n;
        ll arr[n];
        ll brr[n];
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
            cin>>brr[i];
        }

        ll last=arr[0],ans=1;
        for (int i = 0; i < n-1; ++i) {
            if(i==0)
            {
                ans++;
            }
            else{
                if(arr[i]-brr[i]>last)
                {
                    ans++;
                    last=arr[i];
                }
                else if(arr[i]+brr[i]<arr[i+1])
                {
                    ans++;
                    last=arr[i]+brr[i];
                }
                else
                    last=arr[i];
            }
//            cout<<arr[i]<<' '<<brr[i]<<' '<<arr[i+1]<<endl;
        }
        cout<<ans<<endl;









//        ll ans=solve(1);
//        cout<<ans<<endl;
    }
    return 0;
}