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
ll k=0;
vll v;
struct node
{
    char ch;
    ll val;
    struct node* child[26];
    bool last;
    node()
    {
        last=false;
        ll i;
        forn(i,26)
        {
            child[i]=NULL;
        }
    }
};

void trieconstruct(node* root,string &s)
{
    ll i;
    node* temp=root;
    forn(i,s.length())
    {
        ll x=s[i]-'A';
        if(temp->child[x]==NULL)
        {
            node* newnode=new node();
            newnode->ch=s[i];
            newnode->val=k++;
            temp->child[x]=newnode;
        }
        temp=temp->child[x];
    }
    temp->last=true;
}

bool prefixtriematch(node* root,string s)
{
    node* temp=root;
    ll i;
    forn(i,s.length())
    {
        ll x=s[i]-'A';
        if(temp->child[x]==NULL)
            return false;
        temp=temp->child[x];
    }
    return true;
}

bool searchaword(node* root,string s,ll i)
{
    node* temp=root;
    for(;i<s.length();i++)
    {
        ll x=s[i]-'A';
        if(temp->last==true)
            return true;
        else
        if(temp->child[x]==NULL)
            return false;
        else
        temp=temp->child[x];
    }
    return temp->last;
}

void dfs(node* root)
{
    ll i;
    for(i=0;i<26;i++)
    {
        if(root->child[i]!=NULL)
        {
            cout<<root->val<<"->"<<root->child[i]->val<<":"<<root->child[i]->ch<<endll;
            dfs(root->child[i]);
        }
    }
}

int main()
{
    fast_io;
    node* root;
    root=new node();
    root->val=k++;
    ll i,n;
    string s,a;
    cin>>s;
    cin>>n;
    forn(i,n)
    {
        cin>>a;
        trieconstruct(root,a);
    }
    for(i=0;i<s.length();i++)
    {
        if(searchaword(root,s,i))
            cout<<i<<" ";
    }
    return 0;
}

