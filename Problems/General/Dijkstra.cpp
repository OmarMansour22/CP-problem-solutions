///Problem Link
///https://codeforces.com/problemset/problem/20/C
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

int n,m;
vector<vector<array<ll,2>>>v;
vector<ll>dis;
vector<int>ans(500005);
void dij(ll src)
{
    for (int i = 0; i < 500005; ++i) {
        dis[i]=1e18;
    }
    priority_queue<pair<ll,ll> >pq;
    pq.push({src,0});
    dis[src]=0;
    while (!pq.empty())
    {
        auto [f,curcost] = pq.top();
        pq.pop();
        if(dis[f]<curcost)
            continue;

        for(auto [ch,cost]:v[f])
        {
            if(curcost+cost>dis[ch])
                continue;
            ans[ch]=f;
            dis[ch]=curcost+cost;
            pq.push({ch,dis[ch]});
        }
    }
}



int main()
{
    FAST();
    int t=1;
//    cin>>t;
    while(t--){
        cin>>n>>m;
        v.resize(500005);
        dis.resize(500005);
        v.assign(500005,{});
        for (int i = 0; i < m; ++i) {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }

        dij(1);
        if(dis[n]==1e18)
            cout<<"-1\n";
        else
        {
            vector<int>ss;
            ss.push_back(n);
            
            for (int i = 0; i < n; ++i) {
                if(ss.back()==1)
                    break;
                ss.push_back(ans[ss.back()]);
            }
            for (int i = 0; i < ss.size(); ++i) {
                cout<<ss[ss.size()-i-1]<<' ';
            }
            
        }

    }
    return 0;
}

