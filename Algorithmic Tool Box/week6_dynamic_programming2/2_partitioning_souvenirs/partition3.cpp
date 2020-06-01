#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;
bool Possible(ll a[],ll subsetSum[],bool used[],ll sumofeachsubset,ll n,ll currIndex,ll lastindex) 
{ 
    ll i,temp;
    bool next;
    if(subsetSum[currIndex]==sumofeachsubset) 
    { 
        if(currIndex==1) 
            return true; 
        return Possible(a,subsetSum,used,sumofeachsubset,n,currIndex+1,n-1); 
    } 
    for(i=lastindex;i>=0;i--) 
    { 
        if(used[i]) 
            continue; 
        temp=subsetSum[currIndex]+a[i]; 
        if (temp<=sumofeachsubset) 
        { 
            used[i]=true; 
            subsetSum[currIndex]+=a[i]; 
            next=Possible(a,subsetSum,used,sumofeachsubset,n,currIndex,i-1); 
            used[i]=false; 
            subsetSum[currIndex]-=a[i]; 
            if(next) 
                return true; 
        } 
    } 
    return false; 
} 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,k,sum,sumofeachsubset;
    cin>>n;
    ll a[n],subsetSum[3];
    bool used[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    if (n<3) 
    {
        cout<<"0"<<endl;
        return 0;
    } 
    sum=0; 
    for (i=0;i<n;i++) 
    sum+=a[i]; 
    if (sum%3!=0) 
    {
        cout<<"0"<<endl;
        return 0;
    } 
    sumofeachsubset=sum/3; 
    for(i=0;i<3;i++) 
    subsetSum[i]=0; 
    for(i=0;i<n;i++) 
    used[i]=false; 
    subsetSum[0]=a[n-1]; 
    used[n-1]=true;
    if(Possible(a,subsetSum,used,sumofeachsubset,n,0,n-1)) 
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl; 
} 