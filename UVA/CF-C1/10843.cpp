#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int mod = 2000000011;

long long binary_pow(long long x, long long n){
  long long ans = 1;

  while(n){
    if(n&1){
      ans = (ans * x)%mod;
    }
    x = (x*x)%mod;
    n = n >> 1;
  }

  return ans;
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  
  int t;
  cin >> t;
  int ncase = 1;
  while(t--){
    int n;
    cin >> n;
    if(n == 1)
      cout << "Case #" << ncase++ << ": " << 1 << endl;
    else
      cout << "Case #" << ncase++ << ": " << binary_pow(n,n-2) << endl;
  }
  
  return 0;
}