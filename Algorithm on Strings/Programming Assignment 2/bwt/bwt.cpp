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

void consructBWT(string s)
{
  vector<string> v;
  ll l=s.length();
  s+=s;
  ll i;
  for(i=0;i<l;i++)
  {
      string s1=s.substr(i,l);
      v.pb(s1);
  }
  sort(v.begin(),v.end());
  for(i=0;i<v.size();i++)
  {
    cout<<v[i][l-1];
  }
}

int main()
{
  fast_io;
  string s;
  cin>>s;
  consructBWT(s);
  return 0;
}

