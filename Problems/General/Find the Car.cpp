///Problem Link
///https://codeforces.com/contest/1971/problem/E

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




int main()
{
    FAST();
        int t=1;
        cin>>t;
        while (t--)
        {
            ll n,k,q;
            cin>>n>>k>>q;
            ll arr[k];
            ll brr[k];
            for (int i = 0; i < k; ++i) {
                cin>>arr[i];
            }
            for (int i = 0; i < k; ++i) {
                cin>>brr[i];
            }
            for (int i = 0; i < q; ++i) {
                ll d;
                cin>>d;
                int ind= lower_bound(arr,arr+k,d)-arr;
                if(arr[ind]==d)cout<<brr[ind]<<' ';
                else{
                    ll ans=0;
                    ld pre1=0;
                    ld pre2=0;
                    if(ind-1>=0)
                    {
                        pre1=arr[ind-1];
                        pre2=brr[ind-1];
                        ans=brr[ind-1];
                    }
                    ans+=(((d-pre1)*(brr[ind]-pre2))/(((arr[ind]-pre1))));
                    cout<<ans<<' ';
                }
            }
            cout<<endl;
        }






    return 0;
}