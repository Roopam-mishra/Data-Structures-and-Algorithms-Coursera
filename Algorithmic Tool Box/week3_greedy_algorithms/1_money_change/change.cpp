#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,x,s=0;
    cin>>n;
    x=n/10;
    s+=x;
    n=n-(10*x);
    x=n/5;
    s+=x;
    n=n-(5*x);
    s+=n;
    cout<<s<<endl;
    return 0;
}