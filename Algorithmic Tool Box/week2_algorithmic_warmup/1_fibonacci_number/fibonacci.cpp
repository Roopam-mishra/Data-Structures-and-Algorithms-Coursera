#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i;
    ll a[55];
    a[0]=0;
    a[1]=1;
    for(i=2;i<=50;i++)
    a[i]=a[i-1]+a[i-2];
    cin>>n;
    cout<<a[n];
    return 0;
}