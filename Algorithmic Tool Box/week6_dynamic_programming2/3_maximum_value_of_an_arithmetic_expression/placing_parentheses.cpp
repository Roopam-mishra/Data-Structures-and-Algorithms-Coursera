#include<bits/stdc++.h>
using namespace std;
long long calculate(long long sha, long long roop, char xyz) 
{
    if (xyz == '*')
    return sha * roop;
    else 
    if (xyz == '+')
    return sha + roop;
    else 
    if (xyz == '-')
    return sha - roop;
    else
    assert(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char a[50];
    cin>>a;
    long long l,n,i,s,j,k,minvalue,maxvalue,p,b,c,d;
    l=strlen(a);
    n=(l+1)/2;
    //cout<<n<<endl;
    for(i=l;i>=1;i--)
    {
        a[i]=a[i-1];
    }
    a[0]='0';
    long long mina[n+1][n+1];
    long long maxa[n+1][n+1];
    memset(mina,0,sizeof(mina));
    memset(maxa,0,sizeof(maxa));
    for(i=1;i<=n;i++)
    {
        mina[i][i]=a[2*i-1]-'0';
        maxa[i][i]=a[2*i-1]-'0';
    }
    for(s=1;s<=n-1;s++)
    {
        for(i=1;i<=n-s;i++)
        {
            j=i+s;
            minvalue=LLONG_MAX;
            maxvalue=LLONG_MIN;
            for(k=i;k<=j-1;k++)
            {
                p=calculate(maxa[i][k],maxa[k+1][j],a[2*k]);
                b=calculate(maxa[i][k],mina[k+1][j],a[2*k]);
                c=calculate(mina[i][k],maxa[k+1][j],a[2*k]);
                d=calculate(mina[i][k],mina[k+1][j],a[2*k]);
                minvalue=min(minvalue,min(p,min(b,min(c,d))));
                maxvalue=max(maxvalue,max(p,max(b,max(c,d))));
            }
            mina[i][j]=minvalue;
            maxa[i][j]=maxvalue;
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<mina[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<maxa[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    cout<<maxa[1][n]<<endl;
}