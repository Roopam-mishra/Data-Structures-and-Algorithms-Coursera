#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,size_of_buffer;
struct entry
{
    ll arrival_time;
    ll process_time;
};
queue<ll> end_time;
ll calculating(ll arrival,ll process)
{
    while(!end_time.empty())
    {
        if(end_time.front()<=arrival)
        end_time.pop();
        else
        break;
    }
    if(end_time.empty())    
    {
        end_time.push(arrival+process);
        return(arrival);
    }
    if(end_time.size()==size_of_buffer)    
    {
        return(-1);
    }    
    ll last=end_time.back();    
    end_time.push(last+process);
    return(last);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i;
    cin>>size_of_buffer;
    cin>>n;
    ll ans[n];
    struct entry e[n];
    for(i=0;i<n;i++)
    {
        cin>>e[i].arrival_time>>e[i].process_time;
    }
    for(i=0;i<n;i++)
    {
        ans[i]=calculating(e[i].arrival_time,e[i].process_time);
        cout<<ans[i]<<endl;
    }
    return 0;
}