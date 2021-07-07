#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 

  long long k,b,n,t;

  cin >> k >> b >> n >> t;
  long long z = 1;

  while(z <= t){
    z = k*z + b;
    n--;
  }

  cout << max(n+1,0LL) << endl;
  
  
  return 0;
}