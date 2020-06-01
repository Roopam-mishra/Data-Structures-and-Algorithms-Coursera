#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 100000000000
struct edge
{
    ll u,v,cost;
};
ll bellman_ford(struct edge e[],ll n,ll m,ll s,ll visited[])
{
    vector<ll> dist(n+1,INF);
    dist[s]=0;
    ll x;
    for(ll i=0;i<n;i++)
    {
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
    }
    for(ll i=1;i<=n;i++)
    {
        if(dist[i]!=INF)
        visited[i]=1;
    }
    if(x==-1)
    return 0;
    else
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m,i,flag=0,x;
    cin>>n>>m;
    ll visited[n+1]={0};
    struct edge e[m+1];
    for(i=0;i<m;i++)
    {
        cin>>e[i].u>>e[i].v>>e[i].cost;
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            x=bellman_ford(e,n,m,i,visited);
            if(x==1)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1)
    cout<<1<<endl;
    else
    cout<<0<<endl;
    
    return 0;
}
