#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,i,x,y,k,p,q,r,o;
    cin>>n>>m;
    o=m-n;
    p=o/60;
    q=n%60;
    r=m%60;
    ll a[65],s[65];
    a[0]=0;
    a[1]=1;
    s[0]=0;
    s[1]=1;
    for(i=2;i<=60;i++)
    {
        a[i]=(a[i-1]+a[i-2])%10;
        s[i]=(s[i-1]+a[i])%10;
    }
    /*for(i=0;i<=60;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for(i=0;i<=60;i++)
    cout<<s[i]<<" ";*/
    k=0;
    if(q<=r)
    {
        for(i=q;i<=r;i++)
        {
            k=(k+a[i])%10;
        }
        cout<<k<<endl;
    }
    else
    {
        for(i=0;i<=r;i++)
        {
            k=(k+a[i])%10;
        }
        for(i=q;i<=60;i++)
        {
            k=(k+a[i])%10;
        }
        cout<<k<<endl;
    }
    return 0;
}