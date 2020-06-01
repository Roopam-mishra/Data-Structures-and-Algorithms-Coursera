#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,i,x;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cin>>k;
    ll b[k];
    for(i=0;i<k;i++)
    cin>>b[i];
    for(i=0;i<k;i++)
    {
        if(binary_search(a,a+n,b[i])==1)
        {
            x=lower_bound(a,a+n,b[i])-a;
            cout<<x<<" ";
        }
        else
        cout<<"-1"<<" ";
    }
    return 0;
}