#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 1000000000000000000
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,nc1,nc2,nc3,z,y;
    cin>>n;
    vector<vector<ll>> vec(n+1);
    ll a[n+1];
    a[0]=0;
    vec[0].push_back(0);
    a[1]=0;
    vec[1].push_back(1);
    for(i=2;i<=n;i++)
    {
        a[i]=MAX;
        nc1=nc2=nc3=MAX;
        if(i%3==0)
        {
            nc1=a[i/3]+1;
        }
        if(i%2==0)
        {
            nc2=a[i/2]+1;
        }
        nc3=a[i-1]+1;
        if(nc1<=nc2 && nc1<=nc3)
        {
            z=nc1;
            y=i/3;
        }
        else
        if(nc2<=nc1 && nc2<=nc3)
        {
            z=nc2;
            y=i/2;
        }
        else
        {
            z=nc3;
            y=i-1;
        }
        copy(vec[y].begin(), vec[y].end(), back_inserter(vec[i]));
        vec[i].push_back(i);
        a[i]=z;
    }
    cout<<a[n]<<endl;
    for(i=0;i<vec[n].size();i++)
    {
        cout<<vec[n][i]<<" ";
    }
    return 0;
}