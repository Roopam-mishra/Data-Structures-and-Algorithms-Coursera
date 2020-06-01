#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF LLONG_MAX
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,j,x,a,b,u,v;
    cin>>n>>m;
    vector<ll> adj[n+1];
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll visited[n+1];
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
    }
    ll c=0;
    for(j=1;j<=n;j++)
    {
        if(!visited[j])
        {
            visited[j]=1;
            queue<ll> q;
            q.push(j);
            while(!q.empty())
            {
                x=q.front();
                for(i=0;i<adj[x].size();i++)
                {
                    if(!visited[adj[x][i]])
                    {
                        visited[adj[x][i]]=1;
                        q.push(adj[x][i]);
                    }
                }
                q.pop();
            }
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}