#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAX 100000000000000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n1,m1,i,j;
    cin>>n1;
    ll arr1[n1+1];
    arr1[0]=0;
    for(i=1;i<=n1;i++)
    cin>>arr1[i];
    cin>>m1;
    ll arr2[m1+1];
    arr2[0]=0;
    for(i=1;i<=m1;i++)
    cin>>arr2[i];
    ll dp[n1+1][m1+1];
    for(i=0;i<=n1;i++)
    dp[i][0]=0;
    
    for(i=0;i<=m1;i++)
    dp[0][i]=0;
    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=m1;j++)
        {
            if(arr1[i]==arr2[j])
            dp[i][j]=1+dp[i-1][j-1];
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n1][m1]<<endl;
	return 0;
}