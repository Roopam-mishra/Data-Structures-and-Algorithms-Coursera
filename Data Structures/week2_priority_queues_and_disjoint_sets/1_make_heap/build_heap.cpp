#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> b;
ll c=0;
void siftdown(ll a[],ll n,ll i)
{
    ll minindex=i;
    ll left=2*i+1;
    ll right=2*i+2;
    if(left<n && a[left]<a[minindex])
    minindex=left;
    if(right<n && a[right]<a[minindex])
    minindex=right;
    if(i!=minindex)
    {
        b.push_back(i);
        b.push_back(minindex);
        swap(a[i],a[minindex]);
        c++;
        siftdown(a,n,minindex);
    }
    
}
void build_heap(ll a[],ll n)
{
    ll start=(n/2)-1;
    for(ll i=start;i>=0;i--)
    {
        siftdown(a,n,i);
    }
}
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
    build_heap(a,n);
    cout<<c<<endl;
    for(i=0;i<b.size();i+=2)
    {
        cout<<b[i]<<" "<<b[i+1]<<endl;
    }
    return 0;
}