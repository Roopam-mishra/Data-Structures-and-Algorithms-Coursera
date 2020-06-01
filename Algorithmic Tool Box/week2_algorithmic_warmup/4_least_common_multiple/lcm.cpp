#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll x1,y1,a1,b1,d;
    cin>>a1>>b1;
    x1=a1;
    y1=b1;
    while(1)
    {
        d=b1%a1;
        if(d==0)
        break;
        b1=a1;
        a1=d;
    }
    cout<<(x1*y1)/a1<<endl;
    return 0;
}