#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool compare(ll p, ll q)
{
    return (p<q);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char a[2000];
    char b[2000];
    ll l1,l2,i,j,inserion,deletion,match,mismatch;
    cin>>a>>b;
    l1=strlen(a);
    l2=strlen(b);
    for(i=l1;i>=1;i--)
    {
        a[i]=a[i-1];
    }
    a[0]='0';
    //cout<<a<<endl;
    for(i=l2;i>=1;i--)
    {
        b[i]=b[i-1];
    }
    b[0]='0';
    //cout<<b<<endl;
    ll dp[l1+1][l2+1];
    for(i=0;i<=l1;i++)
    dp[i][0]=i;
    for(i=0;i<=l2;i++)
    dp[0][i]=i;
    /*for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    for(j=1;j<=l2;j++)
    {
        for(i=1;i<=l1;i++)
        {
            inserion=dp[i][j-1]+1;
            deletion=dp[i-1][j]+1;
            match=dp[i-1][j-1];
            mismatch=dp[i-1][j-1]+1;
            if(a[i]==b[j])
            dp[i][j]=min({inserion,deletion,match},compare);
            else
            dp[i][j]=min({inserion,deletion,mismatch},compare);
        }
    }
    /*for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    cout<<dp[l1][l2]<<endl;
}