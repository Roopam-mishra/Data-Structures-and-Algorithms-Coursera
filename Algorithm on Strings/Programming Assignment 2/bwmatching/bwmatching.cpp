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

void PreprocessBWT(string& bwt,map<char,ll>& starts,map<char,vector<ll>>& occ_count_before)
{
  string bwt2=bwt;
  ll i;
  sort(bwt2.begin(),bwt2.end());
  for(i=0;i<bwt2.size();i++)
  {
    if(starts.count(bwt2[i])==0)
    {
      starts[bwt2[i]]=i;
    }
  }
  for(i=0;i<bwt.length();i++)
  {
    if(occ_count_before.find(bwt[i])==occ_count_before.end())
      occ_count_before[bwt[i]].resize(bwt.size()+1,0);
    occ_count_before[bwt[i]][i+1]++;
    for(auto& it:occ_count_before)
    {
      if(i<bwt.length())
      {
        it.second[i+1]+=it.second[i];
      }
    }
  }
}

ll CountOccurrences(string& pattern,string& bwt,map<char,ll>& starts,map<char,vector<ll>>& occ_count_before)
{
  ll top,bottom;
  char symbol;
  top=0;
  bottom=bwt.length()-1;
  while(top<=bottom)
  {
    if(pattern.size()!=0)
    {
      symbol=pattern.back();
      pattern.pop_back();
      if(starts.find(symbol)!=starts.end())
      {
      top=starts.find(symbol)->second+occ_count_before.find(symbol)->second[top];
      bottom=starts.find(symbol)->second+occ_count_before.find(symbol)->second[bottom+1]-1;
      }
      else
        return 0;
    }
    else
      return bottom-top+1;
  }
  return 0;
}

int main()
{
  fast_io;
  string bwt,pattern;
  cin>>bwt;
  ll pattern_count,i,occ_count;
  cin>>pattern_count;
  map<char,ll> starts;
  map<char,vector<ll>> occ_count_before;
  PreprocessBWT(bwt, starts, occ_count_before);
  for(i=0;i<pattern_count;i++)
  {
    cin>>pattern;
    occ_count=CountOccurrences(pattern,bwt,starts,occ_count_before);
    cout<<occ_count<<" ";
  }
  return 0;
}
