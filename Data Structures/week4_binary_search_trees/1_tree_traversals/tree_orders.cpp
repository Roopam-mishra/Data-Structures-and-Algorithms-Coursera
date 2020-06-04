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

void in_order(ll vertex)

{

    if(vertex!=-1)

    {

        in_order(r[vertex].left);

        cout<<r[vertex].key<<" ";

        in_order(r[vertex].right);

    }

}

void pre_order(ll vertex)

{

    if(vertex!=-1)

    {

        cout<<r[vertex].key<<" ";
 
        pre_order(r[vertex].left);

        pre_order(r[vertex].right);

    }

}
void post_order(ll vertex)

{
    if(vertex!=-1)

    {

        post_order(r[vertex].left);

        post_order(r[vertex].right);

        cout<<r[vertex].key<<" ";

    }
}

int main() 

{

	fast_io;

	ll i;

	cin>>n;

	for(i=0;i<n;i++)

	{

	    cin>>r[i].key>>r[i].left>>r[i].right;

	}

	in_order(0);

	cout<<endl;

	pre_order(0);

	cout<<endl;

	post_order(0);

	cout<<endl;

	return 0;

}
