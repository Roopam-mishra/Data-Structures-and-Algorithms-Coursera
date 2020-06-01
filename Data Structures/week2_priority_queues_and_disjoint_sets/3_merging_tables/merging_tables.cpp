#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll max_table,n,m,parent[100000],ranki[100000],b[100000],a[100000];
void makeset()
{
    for(ll i=0;i<n;i++)
    {
        parent[i]=i;
        ranki[i]=0;
    }
}
ll find(ll i)
{
    while(i!=parent[i])
    i=parent[i];
    return i;
}
void unioni(ll x,ll y)
{
    ll first=find(x);
    ll second=find(y);
    //cout<<first<<" "<<second<<endl;
    if(first!=second)
    {
        if(ranki[first]<ranki[second])
        {
            parent[first]=second;
            b[second]+=b[first];
            b[first]=0;
        }
        else
        {
            parent[second]=first;
            b[first]+=b[second];
            b[second]=0;
            if(ranki[first]==ranki[second])
            {
                ranki[first]++;
            }
        }
        max_table=max(max_table,max(b[first],b[second]));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,to_merge_table_a,to_merge_table_b;
    cin>>n>>m;
    max_table=LLONG_MIN;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        max_table=max(max_table,a[i]);
    }
    makeset();
    for(i=0;i<m;i++)
    {
        cin>>to_merge_table_a>>to_merge_table_b;
        --to_merge_table_a;
        --to_merge_table_b;
        unioni(to_merge_table_a,to_merge_table_b);
        cout<<max_table<<endl;
    }
    return 0;
}