#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,f;
    cin>>n;
    ll a[n],b[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    cin>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    f=0;
    for(i=0;i<n;i++)
    {
        f=f+(a[i]*b[i]);
    }
    cout<<f<<endl;
    return 0;
}