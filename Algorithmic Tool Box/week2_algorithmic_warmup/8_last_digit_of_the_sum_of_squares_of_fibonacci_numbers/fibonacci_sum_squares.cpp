#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,x,y;
    cin>>n;
    ll a[65],s[65];
    a[0]=0;
    a[1]=1;
    s[0]=0;
    s[1]=1;
    for(i=2;i<=60;i++)
    {
        a[i]=(a[i-1]+a[i-2])%10;
        s[i]=(s[i-1]+(((a[i-1]+a[i-2])%10)*((a[i-1]+a[i-2])%10))%10)%10;
    }
    if(n==0)
    cout<<"0"<<endl;
    else
    {
        x=n%60;
        y=n/60;
        cout<<(((y*s[60])%10)+s[x])%10<<endl;
    }
    return 0;
}
