#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct roop
{
    ll v;
    ll w;
    long double p;
};
bool comp (roop a,roop b)
{
    return a.p>b.p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,W,i;
    long double value;
    cin>>n>>W;
    struct roop a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i].v;
        cin>>a[i].w;
        a[i].p=(long double)((1.0*a[i].v)/a[i].w);
    }
    sort(a,a+n,comp);
    value=0;
    for(i=0;i<n;i++)
    {
        if(W<=0)
        {
            break;
        }
        else
        if(a[i].w<=W)
        {
            W=W-a[i].w;
            value+=(1.0*a[i].v);
        }
        else
        if(a[i].w>W)
        {
            value+=(W*1.0*a[i].p);
            W=W-W;
        }
    }
    cout<<fixed<<setprecision(4)<<value<<endl;
    return 0;
}