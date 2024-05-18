///Problem Link
///https://www.spoj.com/problems/HIGHWAYS/en/

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

int n,m,s,e;
vector<vector<array<ll,2>>>v;
vector<ll>dis;

void dij(ll src)
{
    priority_queue<array<ll,2>>pq;
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
           dis[ch]=curcost+cost;
           pq.push({ch,dis[ch]});
       }
    }


}



int main()
{
    int t=1;
    cin>>t;
    while(t--){
        cin>>n>>m>>s>>e;
        v.resize(n+1);
        dis.resize(n+1);
        v.assign(n+1,{});
        dis.assign(n+1,1e18);
        for (int i = 0; i < m; ++i) {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }

        dij(s);
        if(dis[e]==1e18)
            cout<<"NONE\n";
        else
            cout<<dis[e]<<endl;

    }
    return 0;
}

