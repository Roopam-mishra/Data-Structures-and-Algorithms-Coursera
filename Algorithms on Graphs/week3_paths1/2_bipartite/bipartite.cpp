#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,i,j,z,x,flag,m,a,b,k=1;
    cin>>n>>m;
    vector<ll> adj[n+1];
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> color(n+1,-1);
    queue<ll> q;
    flag=1;
    for(i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            q.push(i);
            while(!q.empty())
            {
                x=q.front();
                for(j=0;j<adj[x].size();j++)
                {
                    if(color[adj[x][j]]==-1)
                    {
                        color[adj[x][j]]=color[x]^1;
                        q.push(adj[x][j]);
                    }
                    else
                    {
                        if(color[x]!=color[adj[x][j]])
                        z=1;
                        else
                        z=0;
                        flag=flag&z;
                    }
                }
                q.pop();
            }
        }
    }
    if(flag==1)
    cout<<"1"<<endl;
    else
    cout<<"0"<<endl;
    return 0;
}