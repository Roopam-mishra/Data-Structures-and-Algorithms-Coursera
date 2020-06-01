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
//#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
vector<ll> ans;
vector<bool> visited;
void dfs(vector<ll> adj[],ll s)
{
    visited[s]=true;
    for (auto i:adj[s])
    {
        if(!visited[i])
        dfs(adj,i);
    }
    ans.pb(s);
}
void topological_sorting(vector<ll> adj[],ll n)
{
    visited.assign(n+1,false);
    ans.clear();
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(adj,i);
        }
    }
    reverse(ans.begin(),ans.end());
}
int main() 
{
	fast_io;
	ll n,m,i,s,a,b;
	cin>>n>>m;
	vector<ll> adj[n+1];
	visited.assign(n+1,false);
	for(i=0;i<m;i++)
	{
	    cin>>a>>b;
	    adj[a].push_back(b);
	    //adj[b].push_back(a);
	}
	topological_sorting(adj,n);
	for(auto i:ans)
	{
	    cout<<i<<" ";
	}
	cout<<endl;
	return 0;
} 