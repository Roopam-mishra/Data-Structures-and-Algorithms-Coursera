k#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll W,n,i,n1,W1,val,j;
    cin>>W>>n;
    ll wt[n+1],value[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>wt[i];
        value[i]=wt[i];
    }
    ll w; 
    n1=n+1;
    W1=W+1;
    vector<ll> K(n1 * W1); 
    for(i=0;i<W1;i++) 
    K[0*W1+i]=0;
    for(i=0;i<n;i++) 
    K[i*W1+0]=0;
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<K[i*W1+j]<<" ";
        } 
        cout<<endl;
    }
    cout<<endl;*/
    for(i=1;i<=n;i++) 
    { 
        for(w=1;w<=W;w++) 
        {
            K[i*W1+w] = K[(i-1)*W1+w];
            if(wt[i]<=w)
            {
                val=K[(i-1)*W1+(w-wt[i])]+value[i];
                if(K[i*W1+w]<val)
                K[i*W1+w]=val;
            }
        } 
    }
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            cout<<K[i*W1+j]<<" ";
        } 
        cout<<endl;
    }
    cout<<endl;*/
    cout<<K[n*W1+W]<<endl;
    return 0;
}