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

struct SuffixTreeNode
{
  SuffixTreeNode* parent{nullptr};
  map<char,SuffixTreeNode*> child;
  ll stringdepth{0};
  ll edgestart{-1};
  ll edgeend{-1};
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
  node->child[startchar]->edgestart=node->child[startchar]->edgestart+offset;
  node->child[startchar]=midnode;
  return midnode;
}

SuffixTreeNode* STFormSA(string& s,vll& order, vll& lcparray)
{
  SuffixTreeNode* root=new SuffixTreeNode(nullptr,0,-1,-1);
  ll lcpprev=0,i,suffix;
  SuffixTreeNode* curnode=root;
  ll N=s.size();
  for(i=0;i<N;i++)
  {
    suffix=order[i];
    while(curnode->stringdepth > lcpprev)
      curnode=curnode->parent;
    if(curnode->stringdepth == lcpprev)
      curnode=CreateNewLeaf(curnode,s,suffix);
    else
    {
      ll edgestart = order[i-1] + curnode->stringdepth;
      ll offset = lcpprev - curnode->stringdepth;
      SuffixTreeNode* midnode=BreakEdge(curnode,s,edgestart,offset);
      curnode = CreateNewLeaf(midnode,s,suffix);
    }
    if(i<N-1)
      lcpprev=lcparray[i];
  }
  return root;
}

void dfs(SuffixTreeNode* root)
{if(root->edgestart!=-1 &&  root->edgeend!=-1)
  cout<<root->edgestart<<" "<<root->edgeend+1<<"\n";
  for(auto j: root->child)
  {
    dfs(j.second);
    // cout<<j.second->edgestart<<" "<<j.second->edgeend+1<<endl;
  }
}

int main()
{
  fast_io;
  string s;
  cin>>s;
  ll i;
  ll N=s.size();
  vll order(N);
  vll lcparray(N-1);
  for(i=0;i<N;i++)
    cin>>order[i];
  for(i=0;i<N-1;i++)
    cin>>lcparray[i];
  SuffixTreeNode* root=STFormSA(s,order,lcparray);
  cout<<s<<"\n";
  dfs(root);
  return 0;
}
