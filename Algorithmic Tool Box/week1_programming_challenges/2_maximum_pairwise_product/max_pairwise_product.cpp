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
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    cout<<a[n-1]*a[n-2]<<endl;
    return 0;
}