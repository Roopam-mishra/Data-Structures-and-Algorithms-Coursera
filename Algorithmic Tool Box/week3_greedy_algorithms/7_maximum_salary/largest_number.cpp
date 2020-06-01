#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,k,x,y,j;
    cin>>n;
    string s[n];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s,s+n);
    /*for(i=0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;*/
    k=n-1;
    if(k<0)
    return 0;
    for(i=9;i>=0;i--)
    {
        string ab=to_string(i);
        x=lower_bound(s,s+n,ab)-s;
        y=upper_bound(s,s+n,ab)-s;
        if(binary_search(s,s+n,ab)==1)
        {
            for(j=x;j<y;j++)
            cout<<s[j];
        }
        for(j=k;j>=y;j--)
        cout<<s[j];
        k=x-1;
    }
    return 0;
}
