#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,k,x,y,i;
    cin>>n;
    if(n==1)
    {
        cout<<"1"<<endl;
        cout<<"1"<<" ";
        return 0;
    }
    else
    if(n==2)
    {
        cout<<"1"<<endl;
        cout<<"2"<<" ";
        return 0;
    }
    k=(-1+(ll)sqrt(n*8+1))/2;
    cout<<k<<endl;
    for(i=1;i<k;i++)
    cout<<i<<" ";
    x=((k-1)*k)/2;
    y=n-x;
    cout<<y<<" ";
    cout<<endl;
    return 0;
}