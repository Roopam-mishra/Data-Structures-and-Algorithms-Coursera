#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct point  
{  
    ll x, y;  
};  
bool compareX(point a,point b)
{
    return a.x<b.x;
}
bool compareY(point a,point b)
{
    return a.y<b.y;
}
float distance(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float hardcalculate(point p[], int n)  
{  
    float minimum=FLT_MAX;  
    for(ll i=0;i<n;i++)  
        for(ll j=i+1;j<n;j++)  
            if(distance(p[i],p[j])<minimum)  
                minimum=distance(p[i],p[j]);  
    return minimum;  
}
float minimum(float x,float y)  
{  
    return (x<y)?x:y;  
} 
float  finddistance(point strip[], ll n,float d)
{
    float minimum=d;
    sort(strip,strip+n,compareY);
    for(ll i=0;i<n;i++)  
        for(ll j=i+1;j<n && (strip[j].y - strip[i].y)<minimum;j++)  
            if(distance(strip[i],strip[j])<minimum)  
                minimum=distance(strip[i],strip[j]);  
    return minimum; 
    
}
float closestpair(struct point p[],ll n)
{
    if(n<=3)
    return hardcalculate(p,n);
    ll mid=n/2;
    point midpoint=p[mid];
    float ld=closestpair(p,mid);
    float rd=closestpair(p+mid,n-mid);
    float d=min(ld,rd);
    point strip[n];
    ll k=0;
    for(ll i=0;i<n;i++)
    {
        if(abs(p[i].x-midpoint.x)<d)
        {
            strip[k]=p[i];
            k++;
        }
    }
    return min(d,finddistance(strip,k,d));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i;
    cin>>n;
    struct point p[n];
    for(i=0;i<n;i++)
    {
        cin>>p[i].x>>p[i].y;
    }
    sort(p,p+n,compareX);
    cout<<fixed<<setprecision(4)<<closestpair(p,n)<<endl;
    return 0;
}