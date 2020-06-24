#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long n,a,b,c,d;

  cin >> n >> a >> b >> c >> d;
  long long x1 = a+b+1;
  long long x2 = a+c+1;
  long long x3 = b+d+1;
  long long x4 = d+c+1;
  long long mx = max({x1,x2,x3,x4});
  x1 = mx-x1+1;
  x2 = mx-x2+1;
  x3 = mx-x3+1;
  x4 = mx-x4+1;


  cout << max(0LL,n*(n-max({x1,x2,x3,x4})+1)) << endl; 
  return 0;
}