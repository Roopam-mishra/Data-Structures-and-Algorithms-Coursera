#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 1000000
long long int id[MAX],n,edges;
pair<long double, pair<long long int, long long int> > p[MAX];
void initialize()
{
    for(ll i=0;i<MAX;++i)
    {
        id[i]=i;
    }
}
ll root(ll x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}
void union1(ll x, ll y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}
vector<long double> kruskal(pair<long double, pair<ll, ll> > p[])
{
    ll x, y;
    vector<long double> vect;
    long double cost;
    for(ll i=0;i<edges;i++)
    {
        x=p[i].second.first;
        y=p[i].second.second;
        cost=p[i].first;
        if(root(x)!=root(y))
        {
            vect.push_back(cost);
            union1(x,y);
        }    
    }
    return vect;
}
int main()
{
    ll n,kk,i,j,k;
    ll weight, cost, minimumCost;
    long double dist;
    initialize();
    cin>>n;
    ll a[n],b[n];
    edges=(n*(n-1))/2;
    for(i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    cin>>kk;
    k=0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            dist=sqrt(((a[i]-a[j])*(a[i]-a[j]))+((b[i]-b[j])*(b[i]-b[j])));
            p[k]=make_pair(dist,make_pair(i,j));
            k++;
        }
    }
    sort(p,p+edges);
    vector<long double> vect=kruskal(p);
    cout<<fixed<<setprecision(12)<<vect[n-kk];
    return 0;
}