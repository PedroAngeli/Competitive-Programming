#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long a,b;
  cin >> a >> b;

  const long long mod = 1e9 + 7;
  long long sum = 0;

  for(int i=1;i<=a;i++){
    long long cur = (i%mod * b%mod)%mod;
    sum = (sum + cur)%mod;
  }
  sum = (sum + a)%mod;

  long long ans = 0;

  for(int i=1;i<=b-1;i++){
    long long cur = (i%mod * sum%mod)%mod;
    ans = (ans + cur)%mod;
  }

  cout << ans << endl;
  
  

  return 0;
}