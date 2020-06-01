#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
void make_set(ll n,ll parent[])
{
    for(ll i=0;i<=n;i++)
    {
        parent[i]=i;
    }
}
ll find(ll x,ll parent[])
{
    if(x==parent[x])return x;
    return find(parent[x],parent);
}
void unioni(ll x,ll y,ll parent[])
{
    ll first=find(x,parent);
    ll second=find(y,parent);
    parent[first]=parent[second];
}
long double kruskal(vector<pair<ld,pair<ll,ll>>> adj,ll parent[])
{
    ll x,y,i;
    long double cost=0;
    long double minimum_cost=0;
    for(i=0;i<adj.size();i++)
    {
        x=adj[i].second.first;
        y=adj[i].second.second;
        cost=1.0*adj[i].first;
        if(find(x,parent)!=find(y,parent))
        {
            minimum_cost+=cost;
            unioni(x,y,parent);
        }
    }
    return minimum_cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,a[20000],b[20000],i,j;
    ld w;
    cin>>n;
    ll parent[n+1];
    make_set(n,parent);
    vector<pair<ld,pair<ll,ll>>> adj;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            w=1.0*sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j])));
            adj.push_back({w,{i,j}});
            //cout<<adj[i].first<<" "<<adj[i].second.first<<" "<<adj[i].second.second<<endl;
        }
    }
    sort(adj.begin(),adj.end());
    cout<<fixed<<setprecision(9)<<kruskal(adj,parent)<<endl;
}