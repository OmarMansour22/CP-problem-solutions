///Problem Link
///https://codeforces.com/contest/1968/problem/C

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




int main()
{
    FAST();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int ans[n];
        for (int i = 0; i < n-1; ++i) {
            cin>>arr[i];
        }
        ans[n-1]=arr[n-2];
        ans[n-2]=1000000000;
        for (int i = n-3; i >=0; --i) {
            ans[i]=ans[i+1]-arr[i];
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout<<endl;








    }
    return 0;
}