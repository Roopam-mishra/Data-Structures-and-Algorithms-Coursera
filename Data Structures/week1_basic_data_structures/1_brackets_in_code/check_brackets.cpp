#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,top,i;
    char a[1000000];
    cin>>a;
    n=strlen(a);
    stack<ll> s;
    stack<ll> q;
    for(i=0;i<n;i++)
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
        {
            if(s.empty())
            {
                s.push(a[i]);
                q.push(i+1);
            }
            else
            {
                s.push(a[i]);
            }
        }
        else if(a[i]==')' || a[i]=='}' || a[i]==']')
        {
            if(s.empty())
            {
                cout<<i+1<</*" "<<"a"<<*/endl;
                return 0;
            }
            top=s.top();
            if((top=='(' && a[i]!=')') || (top=='{' && a[i]!='}') || (top=='[' && a[i]!=']'))
            {
                cout<<i+1<</*" "<<"b"<<*/endl;
                return 0;
            }
            else
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        cout<<"Success"<<endl;
    }
    else
    cout<<q.top()<</*" "<<"c"<<*/endl;
    return 0;
}