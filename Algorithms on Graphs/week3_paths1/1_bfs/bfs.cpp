#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 100000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,x,a,b,u,v;
    cin>>n>>m;
    vector<ll> adj[n+1];
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll visited[n+1];
    ll level[n+1];
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
        level[i]=-1;
    }
    cin>>u>>v;
    queue<ll> q;
    q.push(u);
    level[u]=0;
    visited[u]=1;
    while(!q.empty())
    {
        x=q.front();
        for(i=0;i<adj[x].size();i++)
        {
            if(!visited[adj[x][i]])
            {
                visited[adj[x][i]]=1;
                q.push(adj[x][i]);
                level[adj[x][i]]=level[x]+1;
            }
        }
        q.pop();
    }
    if(level[v]==-1)
    cout<<-1<<endl;
    else
    cout<<level[v]<<endl;
    return 0;
}