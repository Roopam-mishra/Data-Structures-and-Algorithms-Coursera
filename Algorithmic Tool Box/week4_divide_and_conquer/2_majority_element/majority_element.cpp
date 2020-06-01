#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x,s,i;
    vector<ll> v;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    s=1;
    for(i=1;i<n;i++)
    {
        if(a[i]==a[i-1])
        {
            s++;
        }
        else
        {
            v.push_back(s);
            s=1;
        }
    }
    v.push_back(s);
    /*for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;*/
    for(i=0;i<v.size();i++)
    {
        if(v[i]>(n/2))
        {
            cout<<"1"<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl;
    return 0;
}