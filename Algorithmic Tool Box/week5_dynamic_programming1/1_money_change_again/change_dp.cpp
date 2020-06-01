#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000000000000000
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j,numcoins,a[3];
    a[0]=1;
    a[1]=3;
    a[2]=4;
    cin>>n;
    ll minnumcoins[n+1];
    minnumcoins[0]=0;
    for(i=1;i<=n;i++)
    {
        minnumcoins[i]=MAX;
        for(j=0;j<3;j++)
        {
            if(i>=a[j])
            {
                numcoins=minnumcoins[i-a[j]]+1;
                if(numcoins<minnumcoins[i])
                minnumcoins[i]=numcoins;
            }
        }
        
    }
    cout<<minnumcoins[n]<<endl;
    return 0;
}