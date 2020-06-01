#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,x;
    cin>>n;
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
    if(n==0)
    cout<<"0"<<endl;
    else
    {
        x=n%60;
        cout<<(s[x])%10<<endl;
    }
    
    return 0;
}