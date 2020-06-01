#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define x 263
#define modp 1000000007 
struct roop
{
    vector<string> v;
};
ll power(ll xx, unsigned long long int y, ll p) 
{ 
    ll res = 1;
    xx = xx % p;
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*xx) % p; 
        y = y>>1;
        xx = (xx*xx) % p;   
    } 
    return res; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll m,n,i,j,k,number,flag;
    string s1,str;
    cin>>m;
    cin>>n;
    struct roop r[m+1];
    for(i=0;i<n;i++)
    {
        cin>>s1;
        if(s1[0]=='a' && s1[1]=='d' && s1[2]=='d')
        {
            cin>>str;
            k=0;
            for(j=0;j<str.length();j++)
            {
                unsigned long long int jj=j;
                k=((k+(((int(str[j]))*(power(x,jj,modp)))%modp))%modp);
            }
            k=k%m;
            //cout<<k<<endl;
            flag=0;
            for (auto it = r[k].v.begin(); it != r[k].v.end(); it++)
            { 
                if (*it==str) 
                { 
                    flag=1;
                    break; 
                }
            }
            if(flag==0)
            r[k].v.push_back(str);
        }
        else
        if(s1[0]=='d' && s1[1]=='e' && s1[2]=='l')
        {
            cin>>str;
            k=0;
            for(j=0;j<str.length();j++)
            {
                unsigned long long int jj=j;
                k=((k+(((int(str[j]))*(power(x,jj,modp)))%modp))%modp);
            }
            k=k%m;
            //cout<<k<<endl;
            for (auto it = r[k].v.begin(); it != r[k].v.end(); it++)
            { 
                if (*it==str) 
                { 
                    r[k].v.erase(it);
                    break; 
                }
            }
        } 
        else
        if(s1[0]=='f' && s1[1]=='i' && s1[2]=='n' && s1[3]=='d')
        {
            cin>>str;
            k=0;
            for(j=0;j<str.length();j++)
            {
                unsigned long long int jj=j;
                k=((k+(((int(str[j]))*(power(x,jj,modp)))%modp))%modp);
            }
            k=k%m;
            //cout<<k<<endl;
            flag=0;
            for (auto it = r[k].v.begin(); it != r[k].v.end(); it++) 
            { 
                if (*it==str) 
                { 
                    cout<<"yes"<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            cout<<"no"<<endl;
        }
        else
        if(s1[0]=='c' && s1[1]=='h' && s1[2]=='e' && s1[3]=='c' && s1[4]=='k')
        {
            cin>>number;
            for(j=(r[number].v.size())-1;j>=0;j--)
            {
                cout<<r[number].v[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}