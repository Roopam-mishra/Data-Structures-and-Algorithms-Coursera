#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,j,k,m,l;
    cin>>n;
    ll arr1[n+1];
    arr1[0]=0;
    for(i=1;i<=n;i++)
    cin>>arr1[i];
    cin>>m;
    ll arr2[m+1];
    arr2[0]=0;
    for(i=1;i<=m;i++)
    cin>>arr2[i];
    cin>>l;
    ll arr3[l+1];
    arr3[0]=0;
    for(i=1;i<=l;i++)
    cin>>arr3[i];
    ll dp[n+1][m+1][l+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            for(k=0;k<=l;k++)
            {
                if(i==0 || j==0 || k==0)
                dp[i][j][k]=0;
                else
                if(arr1[i]==arr2[j] && arr1[i]==arr3[k])
                dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else
                dp[i][j][k]=max(dp[i][j-][k],max(dp[i-1][j][k],dp[i][j][k-1]));
            }
        }
    }
    cout<<dp[n][m][l]<<endl;;
}