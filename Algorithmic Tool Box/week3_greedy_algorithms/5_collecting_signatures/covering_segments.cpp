#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct roop
{
    ll starting;
    ll ending;
};
bool comp(roop p,roop q)
{
    if(p.ending==q.ending)
    return p.starting<q.starting;
    else
    return p.ending<q.ending;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,k,p,b[1000000];
    cin>>n;
    struct roop r[n];
    for(i=0;i<n;i++)
    {
        cin>>r[i].starting>>r[i].ending;
    }
    sort(r,r+n,comp);
    /*for(i=0;i<n;i++)
    {
        cout<<r[i].starting<<" "<<r[i].ending;
        cout<<endl;
    }
    cout<<endl;*/
    p=r[0].ending;
    k=0;
    b[k++]=p;
    for(i=1;i<n;i++)
    {
        if(p>=r[i].starting && p<=r[i].ending)
        continue;
        else
        if(p<r[i].starting || p>r[i].ending)
        {
            p=r[i].ending;
            b[k++]=p;
        }
    }
    cout<<k<<endl;
    for(i=0;i<k;i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}