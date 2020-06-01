#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i;
    cin>>n;
    ll a[n+1];
    a[0]=0;
    a[1]=1;
    for(i=2;i<=n;i++)
    {
        a[i]=(a[i-1]+a[i-2])%10;
    }
    cout<<a[n];
    return 0;
}