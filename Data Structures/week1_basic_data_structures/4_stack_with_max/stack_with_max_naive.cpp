#include<bits/stdc++.h>
#include<stack>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n;
    stack <ll> s1;
    stack <ll> s2;
    cin>>t;
    while(t--)
    {
        char s[10];
        cin>>s;
        if(s[0]=='p' && s[1]=='u' && s[2]=='s' && s[3]=='h')
        {
            cin>>n;
            s1.push(n);
            if(s2.empty())
            {
                s2.push(n);
            }
            else
            if(n>=s2.top())
            {
                s2.push(n);
            }
        }
        else
        if(s[0]=='p' && s[1]=='o' && s[2]=='p')
        {
            if(s1.top()==s2.top())
            {
                s1.pop();
                s2.pop();
            }
            else
            {
                s1.pop();
            }
        }
        else
        if(s[0]=='m' && s[1]=='a' && s[2]=='x')
        {
            cout<<s2.top()<<endl;
        }
    }
    return 0;
}