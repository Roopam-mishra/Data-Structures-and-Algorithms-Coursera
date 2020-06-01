#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,number;
    cin>>n;
    string s1,name;
    vector<string> a;
    for(i=0;i<10000000;i++)
    {
        a.push_back("not found");
    }
    for(i=0;i<n;i++)
    {
        cin>>s1;
        if(s1[0]=='a' && s1[1]=='d' && s1[2]=='d')
        {
            cin>>number;
            cin>>name;
            a[number]=name;
        }
        else
        if(s1[0]=='d' && s1[1]=='e' && s1[2]=='l')
        {
            cin>>number;
            a[number]="not found";
        }
        else
        if(s1[0]=='f' && s1[1]=='i' && s1[2]=='n' && s1[3]=='d')
        {
            cin>>number;
            cout<<a[number]<<endl;
        }
    }
}