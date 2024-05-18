///Problem Link
///https://codeforces.com/contest/1968/problem/E

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
        cout<<1<<' '<<1<<endl;
        cout<<1<<' '<<2<<endl;
        for (int i = 3; i <=n ; ++i) {
            cout<<i<<' '<<i<<endl;
        }
        cout<<endl;


    }
    return 0;
}