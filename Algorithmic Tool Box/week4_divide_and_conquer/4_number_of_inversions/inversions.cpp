#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll merge( long long int a[],long long int l,long long int m,long long int r)
{
	long long int i,j,k,cnt=0;
	long long int n1=m-l+1;
	long long int n2=r-m;
	 long long int L[n1],R[n2];
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[m+1+j];
	i=0;j=0;k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
			cnt=cnt+(n1-i);
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
	return cnt;
}
ll mergesort(long long int a[],long long int l,long long int r)
{
    ll cnt=0;
	if(l<r)
	{
		long long int m=l+(r-l)/2;
		cnt=mergesort(a,l,m);
		cnt+=mergesort(a,m+1,r);
		cnt+=merge(a,l,m,r);
	}
	return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<mergesort(a,0,n-1)<<endl;
}