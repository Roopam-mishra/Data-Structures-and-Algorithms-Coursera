#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j,c,maxheight,height;
    cin>>n;
    ll p[n];
    for(i=0;i<n;i++)
    {
        cin>>p[i];
    }
    ll h[n];
    for(i=0;i<n;i++)
    {
        h[i]=0;
    }
    maxheight=LLONG_MIN;
    for(i=0;i<n;i++)
    {
        height=0;
        if(h[i]!=0)
        {
            continue;
        }
        for(j=i;j!=-1;j=p[j])
        {
            if(h[j]!=0)
            {
                height+=h[j];
                break;
            }
            height++;
        }
        maxheight=max(maxheight,height);
        for(j=i;j!=-1;j=p[j])
        {
            if(h[j]!=0)
            break;
            h[j]=height--;
        }
    }
    cout<<maxheight<<endl;
    return 0;
}