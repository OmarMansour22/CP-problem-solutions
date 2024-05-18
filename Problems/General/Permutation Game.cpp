///Problem Link
///https://codeforces.com/contest/1968/problem/D
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
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        int arr[n];
        int brr[n];
        for (int i = 0; i < n; ++i) {
            cin>>brr[i];
        }
        for (int i = 0; i < n; ++i) {
            cin>>arr[i];
        }
        ll ansa=0,ansb=0;
        ll suma=0;
        ll sumb=0;
        for (int i = 0; i < min(n,k); ++i) {
            suma+=arr[a-1];
            sumb+=arr[b-1];
            ansa=max(ansa,(1ll*(k-i-1)*arr[a-1])+suma);
            ansb=max(ansb,(1ll*(k-i-1)*arr[b-1])+sumb);
            a=brr[a-1];
            b=brr[b-1];
        }
        if(ansa>ansb)cout<<"Bodya\n";
        else if(ansa<ansb)cout<<"Sasha\n";
        else cout<<"Draw\n";





    }
    return 0;
}