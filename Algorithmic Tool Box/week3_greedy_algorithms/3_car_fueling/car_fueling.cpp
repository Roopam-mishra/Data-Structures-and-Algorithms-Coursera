#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,n,d,numrefill,currrefill,lastrefill,i;
    cin>>d>>m>>n;
    ll a[n+2];
    a[0]=0;
    for(i=1;i<=n;i++)
    cin>>a[i];
    a[n+1]=d;
    numrefill=0;
    currrefill=0;
    while(currrefill<=n)
    {
        lastrefill=currrefill;
        while(currrefill<=n && (a[currrefill+1]-a[lastrefill]<=m))
        {
            currrefill=currrefill+1;
        }
        if(currrefill==lastrefill)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        else 
        if(currrefill<=n)
        {
            numrefill=numrefill+1;
        }
    }
    cout<<numrefill<<endl;
    return 0;
}