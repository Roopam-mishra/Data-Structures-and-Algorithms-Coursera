#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 10000000000
struct edge
{
    ll u,v,cost;
};
vector<ll> Bellman_Ford(struct edge e[],ll n,ll m,ll v)
{
    vector<ll> dist(n+1,INF);
    dist[v]=0;
    vector<ll> prev(n+1,-1);
    ll x;
    for(ll i=0;i<n-1;i++)
    {
        x=-1;
        for(ll j=0;j<m;j++)
        {
            if(dist[e[j].u]<INF)
            {
                if(dist[e[j].v]>dist[e[j].u]+e[j].cost)
                {
                    dist[e[j].v]=dist[e[j].u]+e[j].cost;
                    prev[e[j].v] = e[j].u;
                    x=e[j].v;
                }
            }
        }
    }
    vector<ll> dist2(n+1);
    for(ll i=0;i<=n;i++)
    {
        dist2[i]=dist[i];
    }
    x=-1;
    for(ll j=0;j<m;j++)
    {
        if(dist[e[j].u]<INF)
        {
            if(dist[e[j].v]>dist[e[j].u]+e[j].cost)
            {
                dist[e[j].v]=dist[e[j].u]+e[j].cost;
                x=e[j].v;
            }
        }
    }
    if(x==-1)
    {
        return dist2;
    }
    else
    {
        ll y=x;
        for(ll i=0;i<n;i++)
        y=prev[y];
        vector<ll> path;
        for(ll current=y;;current=prev[current])
        {
            path.push_back(current);
            if(current==y && path.size()>1)
            break;
        }
        for(ll j=0;j<path.size();j++)
        dist2[path[j]]=-1;
        return dist2;
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,s;
    cin>>n>>m;
    struct edge e[m+1];
    for(i=0;i<m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].cost;
    }
    cin>>s;
    vector<ll> distance(n+1);
    distance=Bellman_Ford(e,n,m,s);
    for(i=1;i<=n;i++)
    {
        if(distance[i]==INF)
        cout<<"*"<<endl;
        else
        if(distance[i]==-1)
        cout<<"-"<<endl;
        else
        cout<<distance[i]<<endl;
    }
    return 0;
}
