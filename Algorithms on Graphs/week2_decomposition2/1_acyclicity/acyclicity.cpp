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
#define f first
#define s second
#define Test ll t;cin>>t;while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<ll> color;
vector<ll> parent;
ll cycle_start, cycle_end;
bool dfs(ll v,vector<ll> adj[])
{
    color[v]=1;
    for(auto u:adj[v])
    {
        if(color[u]==0)
        {
            parent[u]=v;
            if(dfs(u,adj))
            return true;
        }
        else
        if(color[u]==1)
        {
            cycle_end=v;
            cycle_start=u;
            return true;
        }
    }
    color[v]=2;
    return false;
}
int main() 
{
	fast_io;
	ll n,m,i,a,b;
	cin>>n>>m;
	vector<ll> adj[n+1];
	for(i=0;i<m;i++)
	{
	    cin>>a>>b;
	    adj[a].push_back(b);
	    //adj[b].push_back(a);
	}
	color.assign(n+1,0);
	parent.assign(n+1,-1);
	cycle_start=-1;
	for(i=1;i<=n;i++)
	{
	    if(color[i]==0 && dfs(i,adj))
	    {
	        break;
	    }
	}
	if(cycle_start==-1)
	cout<<0<<endl;
	else
	{
	    cout<<1<<endl;
	    /*vector<ll> cycle;
	    cycle.push_back(cycle_start);
	    for(i=cycle_end;i!=cycle_start;i=parent[i])
	    {
	        cycle.push_back(i);
	    }
	    cycle.push_back(cycle_start);
	    reverse(cycle.begin(), cycle.end());
	    cout<<"Cycle:"<<endl;
	    for(i=0;i<cycle.size();i++)
	    {
	        cout<<cycle[i]<<" ";
	    }
	    cout<<endl;*/
	}
	return 0;
} 