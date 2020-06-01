#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void muly(long long int F[2][2], long long int M[2][2],long long int m);
void pow(long long int F[2][2], long long int n,long long int m);
long long int fib(long long int n,long long int m) 
{ 
  long long int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  pow(F, n-1,m); 
  return F[0][0]; 
} 
void muly(long long int F[2][2],long long int M[2][2],long long int m) 
{ 
  long long int x =  (F[0][0]*M[0][0]%m + F[0][1]*M[1][0]%m)%m; 
  long long int y =  (F[0][0]*M[0][1]%m + F[0][1]*M[1][1]%m)%m; 
  long long int z =  (F[1][0]*M[0][0]%m + F[1][1]*M[1][0]%m)%m; 
  long long int w =  (F[1][0]*M[0][1]%m + F[1][1]*M[1][1]%m)%m; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
}
void pow(long long int F[2][2],long long int n,long long int m) 
{ 
  long long int i; 
  if(n == 0 || n == 1) return;
  long long int M[2][2] = {{1,1},{1,0}}; 
  pow(F,n/2, m);
    muly(F, F, m);
    if(n % 2 != 0) muly(F, M, m); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    cout<<fib(n,m)%m<<endl;
    return 0;
}