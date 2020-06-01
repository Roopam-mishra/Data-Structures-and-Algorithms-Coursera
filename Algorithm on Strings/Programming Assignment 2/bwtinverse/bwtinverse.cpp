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

void inverseBWT(string s)
{
  ll l=s.length();
  ll i,j;
  vector<pair<char,ll>> v;
  for(i=0;i<l;i++)
    v.pb({s[i],i});
  sort(v.begin(),v.end());
  pair<char,ll> x;
  x=v[0];
  for(i=0;i<l;i++)
  {
    x=v[x.ss];
    cout<<x.ff;
  }
}

int main()
{
  fast_io;
  string s;
  cin>>s;
  inverseBWT(s);
  return 0;
}

