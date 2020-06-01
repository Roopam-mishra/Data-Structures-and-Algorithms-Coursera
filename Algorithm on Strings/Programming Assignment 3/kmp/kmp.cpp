#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define MOD 1000000007
#define INF 1000000000000000000
#define endll "\n"
#define pb push_back
#define forn(i,n) for(i=0;i<n;i++)
#define forab(i,a,b) for(i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define pll pair<ll,ll>
#define vll vector<ll>
#define ff first
#define ss second
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void createLPS(string pattern,ll m,ll *lps)
{
    ll len=0; //length of the previous longest prefix which is also a suffix 
    lps[0]=0;
    ll i=1;
    while(i<m)
    {
        if(pattern[i]==pattern[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len - 1]; 
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}

void KMP(string pattern,string text,ll n,ll m)
{
    ll i=0,j=0;
    ll lps[m];
    createLPS(pattern,m,lps);
    while(i<n)
    {
        if(pattern[j]==text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<i-j<<" ";
            j=lps[j-1];
        }
        else
        if(i<n && pattern[j]!=text[i])
        {
            if(j!=0)
            j=lps[j-1];
            else
            i++;
        }
    }
}

int main()
{
  fast_io;
  string text,pattern;
  cin>>pattern>>text;
  ll n=text.length();
  ll m=pattern.length();
  if(m>n)
    cout<<endl;
  else
    KMP(pattern,text,n,m);
  return 0;
}