#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct roop
{
    ll x;
    ll y;
};
bool comp2(roop a, roop b)
{
    return a.x<b.x;
}
bool comp(roop a ,roop b)
{
    if(a.x==b.x)
    {
        return a.y<b.y;
    }
    else
    return a.x<b.x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k,i,a,b,c,l;
    cin>>n>>k;
    struct roop rup[k+1];
    struct roop r[2*n+k+1];
    ll arr[k+1];
    //cout<<n<<k;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        r[2*i].x=a;
        r[2*i].y=1;
        r[2*i+1].x=b;
        r[2*i+1].y=3;
    }
    for(i=0;i<k;i++)
    {
        cin>>c;
        r[2*n+i].x=c;
        r[2*n+i].y=2;
        rup[i].x=c;
        rup[i].y=i;
    }
    sort(rup,rup+k,comp2);
    sort(r,r+(2*n+k),comp);
    c=0;
    l=0;
    for(i=0;i<(2*n+k);i++)
    {
        if(r[i].y==1)
        c++;
        else
        if(r[i].y==3)
        c--;
        else
        if(r[i].y==2)
        {
            arr[rup[l++].y]=c;
        }
    }
    for(i=0;i<k;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    /*for(i=0;i<(2*n+k);i++)
    cout<<r[i].x<<" "<<r[i].y<<endl;*/
    return 0;
    
}