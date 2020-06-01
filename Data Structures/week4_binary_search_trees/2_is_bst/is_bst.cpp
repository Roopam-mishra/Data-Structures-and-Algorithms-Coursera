#include <iostream>

#include <algorithm>

#include <vector>

#include <math.h>

#include <cstring>

#include <string>

#include <stack>

#include <queue>

#include <deque>

#include <map>

#include <set>
#include <utility>

#include <iomanip>

#include <climits>

using namespace std;

#define ll long long

#define MOD 1000000007

#define MAX 1000000000000000000

#define ln "\n"

#define pb push_back

#define pll pair<ll,ll>

#define f first
#define s second

#define TEST ll t;cin>>t; while(t--)

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);

struct roop

{

    ll key;

    ll left;

    ll right;

};

ll n;

struct roop r[100001];

ll flag=1;

bool is_binary_search_tree(ll node,ll maxi,ll mini)

{

    if((node<0) || (node>=n))

    return true;

    if((r[node].key<mini) || (r[node].key>maxi))

    return false;

    return is_binary_search_tree(r[node].left,r[node].key-1,mini)  && is_binary_search_tree(r[node].right,maxi,r[node].key+1);

}

int main()

{

	fast_io;

	ll i;

	cin>>n;

	for(i=0;i<n;i++)

	cin>>r[i].key>>r[i].left>>r[i].right;

    if(is_binary_search_tree(0,MAX,-MAX))

    cout<<"CORRECT"<<endl;

	else

	cout<<"INCORRECT"<<endl;

    return 0;

}
