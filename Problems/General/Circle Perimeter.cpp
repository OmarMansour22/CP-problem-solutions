///Problem Link
///https://codeforces.com/contest/1971/problem/F

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
        ld n;
        cin>>n;
        ll ans=0;
        for (ll i = 1; i <=2*n ; ++i) {
            ll l=0,r=(n*n)+1,m=(l+r)/2;
            ll low=0;
            while (l+1<r)
            {
                m=(l+r)/2;
                ld ss= sqrtl((i*i)+(m*m));

                if(ss-n<1){
                    l=m;
                    low=m;
                }
                else{
                    r=m;
                }
            }

            l=0,r=(n*n)+1,m=(l+r)/2;
            while (l+1<r)
            {
                m=(l+r)/2;
                ld ss= sqrtl((i*i)+(m*m));
                if(ss-(n-1)<1){
                    l=m;
                }
                else{
                    r=m;
                }
            }

            ll high=l;
            if(high!=low){
                ans+=abs(high-low);

            }
        }
        cout<<(ans*4)+4<<endl;
    }






    return 0;
}