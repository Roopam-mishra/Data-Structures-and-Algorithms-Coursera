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

 vll SortCharacters(string& s)
 {
  vll order(s.length());
  ll count[27]={0},i;
  for(i=0;i<s.length()-1;i++)
  {
    count[s[i]-'A'+1]++;
  }
  count[0]++;
  for(i=1;i<27;i++)
  {
    count[i]=count[i]+count[i-1];
  }
  
  order[0]=s.length()-1;
  for(i=s.length()-2;i>=0;i--)
  {
    ll x=s[i]-'A'+1;
    count[x]-=1;
    order[count[x]]=i;
  }
  return order;
 }

 vll ComputeCharClasses(string& s, vll& order)
 {
  vll clss(s.length());
  ll i;
  clss[order[0]]=0;
  for(i=1;i<s.length();i++)
  {
    if(s[order[i]]!=s[order[i-1]])
      clss[order[i]]=clss[order[i-1]]+1;
    else
      clss[order[i]]=clss[order[i-1]];
  }
  return clss;
 }

 vll SortDoubled(string& s,ll len,vll& order,vll& clss)
 {
  ll count[s.length()]={0};
  ll i,start,cl;
  vll newOrder(s.length());
  for(i=0;i<s.length();i++)
  {
    count[clss[i]]++;
  }
  for(i=1;i<s.length();i++)
  {
    count[i]=count[i]+count[i-1];
  }
  for(i=s.length()-1;i>=0;i--)
  {
    start=(order[i]-len+s.length())%s.length();
    cl=clss[start];
    count[cl]-=1;
    newOrder[count[cl]]=start;
  }
  return newOrder;
 }

 vll UpdateClasses(vll& newOrder,vll& clss,ll len)
 {
  ll n=newOrder.size(),i,cur,prev,midprev,mid;
  vll newClass(n);
  newClass[newOrder[0]]=0;
  for(i=1;i<n;i++)
  {
    cur=newOrder[i];
    prev=newOrder[i-1];
    mid=(cur+len)%n;
    midprev=(prev+len)%n;
    if(clss[cur]!=clss[prev] || clss[mid]!=clss[midprev])
      newClass[cur]=newClass[prev]+1;
    else
      newClass[cur]=newClass[prev];
  }
  return newClass;
 }

 vll InvertSuffixArray(vll& order)
 {
  vll pos(order.size());
  ll i;
  for(i=0;i<pos.size();i++)
  {
    pos[order[i]]=i;
  }
  return pos;
 }

 ll LCPOfSuffixes(string& s,ll i,ll j,ll equal)
 {
  ll lcp=max(0LL,equal);
  while(((i+lcp)<s.length()) && ((j+lcp)<s.length()))
  {
    if(s[i+lcp]==s[j+lcp])
      lcp++;
    else
      break;
  }
  return lcp;
 }

 vll ComputeLCPArray(string& s,vll& order)
 {
  ll lcp,suffix,nextsuffix,i,orderIndex;
  vll lcparray(s.length()-1);
  lcp=0;
  vll posinorder=InvertSuffixArray(order);
  suffix=order[0];
  for(i=0;i<s.length();i++)
  {
    orderIndex=posinorder[suffix];
    if(orderIndex==(s.length()-1))
    {
      lcp=0;
      suffix=(suffix+1)%s.length();
      continue;
    }
    nextsuffix=order[orderIndex+1];
    lcp=LCPOfSuffixes(s,suffix,nextsuffix,lcp-1);
    lcparray[orderIndex]=lcp;
    suffix=(suffix+1)%s.length();
  }
  return lcparray;
 }

struct SuffixTreeNode
{
  SuffixTreeNode* parent;
  map<char,SuffixTreeNode*> child;
  ll stringdepth,edgestart,edgeend;
  SuffixTreeNode(SuffixTreeNode* w,ll x,ll y,ll z)
  {
    parent=w;
    stringdepth=x;
    edgestart=y;
    edgeend=z;
  }
};

SuffixTreeNode* CreateNewLeaf(SuffixTreeNode* node,string& s,ll suffix)
{
  SuffixTreeNode* leaf=new SuffixTreeNode(node,s.length()-suffix,suffix+node->stringdepth,s.length()-1);
  node->child[s[leaf->edgestart]]=leaf;
  return leaf;
}

SuffixTreeNode* BreakEdge(SuffixTreeNode* node,string& s,ll start,ll offset)
{
  char startchar=s[start];
  char midchar=s[start+offset];
  SuffixTreeNode* midnode=new SuffixTreeNode(node,node->stringdepth+offset,start,start+offset-1);
  midnode->child[midchar]=node->child[startchar];
  node->child[startchar]->parent=midnode;
  node->child[startchar]->edgestart+=offset;
  node->child[startchar]=midnode;
  return midnode;
}

SuffixTreeNode* STFormSA(string& s,vll& order, vll& lcparray)
{
  SuffixTreeNode* root=new SuffixTreeNode(NULL,0,-1,-1);
  ll lcpprev=0,i,suffix;
  SuffixTreeNode* curnode=root;
  for(i=0;i<s.length();i++)
  {
    suffix=order[i];
    while(curnode->stringdepth>lcpprev)
      curnode=curnode->parent;
    if(curnode->stringdepth==lcpprev)
      curnode=CreateNewLeaf(curnode,s,suffix);
    else
    {
      ll edgestart=order[i-1]+curnode->stringdepth;
      ll offset=lcpprev-curnode->stringdepth;
      SuffixTreeNode* midnode=BreakEdge(curnode,s,edgestart,offset);
      curnode=CreateNewLeaf(midnode,s,suffix);
    }
    if(i<s.length()-1)
      lcpprev=lcparray[i];
  }
  return root;
}

void dfs(SuffixTreeNode* root,string& s)
{
  
  for(auto j: root->child)
  {
    cout<<s.substr(j.second->edgestart,j.second->edgeend+1-j.second->edgestart)<<endl;
    dfs(j.second,s);
    // cout<<j.second->edgestart<<" "<<j.second->edgeend+1<<endl;
  }
}

int main()
{
  fast_io;
  string s;
  cin>>s;
  ll i;
  vll order=SortCharacters(s);
  vll clss=ComputeCharClasses(s,order);
  ll len=1;
  while(len<s.length())
  {
    order=SortDoubled(s,len,order,clss);
    clss=UpdateClasses(order,clss,len);
    len=2*len;
  }
  vll lcparray=ComputeLCPArray(s,order);
  SuffixTreeNode* root=STFormSA(s,order,lcparray);
  dfs(root,s);
  return 0;
}
