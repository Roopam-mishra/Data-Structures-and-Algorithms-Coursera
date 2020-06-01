#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll number_of_elements,i,k;
    cin>>number_of_elements;
    ll a[number_of_elements];
    for(i=0;i<number_of_elements;i++)
    {
        cin>>a[i];
    }
    cin>>k;
    vector<ll> answer;
    deque<ll> q;
    for(i=0;i<number_of_elements;i++)
    {
        if(i>=k)
        {
            answer.push_back(a[q.front()]);
            while((!q.empty()) && (q.front()<=i-k))
            q.pop_front();
        }
        while((!q.empty()) && (a[q.back()]<=a[i]))
        q.pop_back();
        q.push_back(i);
    }
    answer.push_back(a[q.front()]);
    for(i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}