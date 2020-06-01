#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define mp make_pair
#define F first
#define S second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<bool> visited;
stack<ll> st;
void dfs1(vector<ll> adj[],ll v)
{
    visited[v]=true;
    for(int u:adj[v])
    {
        if(!visited[u])
        dfs1(adj,u);
    }
    st.push(v);
}
void dfs2(vector<ll> adj[],ll v)
{
    visited[v]=true;
    for(int u:adj[v])
    {
        if(!visited[u])
        dfs2(adj,u);
    }
}
int main()
{
    fast_io;
    ll n,m,i,x,c,a,b;
    cin>>n>>m;
    vector<ll> adj1[n+1];
    vector<ll> adj2[n+1];
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        adj1[a].pb(b);
        adj2[b].pb(a);
    }
    visited.assign(n+1,false);
    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(adj1,i);
        }
    }
    visited.assign(n+1,false);
    c=0;
    while(!st.empty())
    {
        x=st.top();
        if(!visited[x])
        {
            dfs2(adj2,x);
            c++;
        }
        st.pop();
    }
    cout<<c<<endl;
    return 0;
}