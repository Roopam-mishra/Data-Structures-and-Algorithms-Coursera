#include<bits/stdc++.h>
using namespace std;
#define INF LLONG_MAX
typedef long long int ll;
vector<ll> Dijkstra(ll s,vector<vector<pair<ll,ll>>> adj)
{
    ll n=adj.size();
    vector<ll> dist(n+5,INF);
    vector<ll> prev(n+5,0);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    dist[s]=0;
    while(!pq.empty())
    {
        ll v=pq.top().second;
        ll dist_v=pq.top().first;
        pq.pop();
        if(dist_v!=dist[v])
        continue;
        for(ll i=0;i<adj[v].size();i++)
        {
            ll to=adj[v][i].first;
            ll len=adj[v][i].second;
            if(dist[v]+len<dist[to])
            {
                dist[to]=dist[v]+len;
                prev[to]=v;
                pq.push({dist[to],to});
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j,b,w,u,v,a;
    cin>>n>>m;;
    vector<vector<pair<ll,ll>>> adj(n+5);
    for(i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    cin>>u>>v;
    vector<ll> dist(n+1);
    dist=Dijkstra(u,adj);
    if(dist[v]==INF)
    cout<<-1<<endl;
    else
    cout<<dist[v]<<endl;
    return 0;
}