#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
long long solve(long long x){
  long long l = 1;
  long long r = 1e6;

  while(l <= r){
    long long m = (l+r)/2;

    if(m*m*m == x)
      return m;
    else if(m*m*m < x)
      l = m+1;
    else
      r = m-1;
  }

  return -1;
}
 
int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;
  while(n--){
    long long a,b;
    cin >> a >> b;

    long long cr = solve(a*b);

    if(cr*cr*cr != a*b)
      cout << "No" << endl;
    else if(a % cr == 0 && b % cr == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  } 
   
  return 0;
}