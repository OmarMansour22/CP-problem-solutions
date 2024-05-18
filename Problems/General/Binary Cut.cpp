///Problem Link
///https://codeforces.com/contest/1971/problem/D

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
        string f;
        cin>>f;
        int cnt=0,ans=1;
        for (int i = 1; i < f.size(); ++i) {
            if(f[i]==f[i-1])
                continue;
            else if(f[i]=='1'&&f[i-1]=='0'&&cnt==0)
            {
                cnt++;
            }
            else ans++;
        }
        cout<<ans<<endl;
    }






    return 0;
}