#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long mod = 1e9 + 7;

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long ans = 1;
  long long aux = 1;

  for(int i=0;i<n;i++){
    ans = (ans % mod * 27LL % mod)%mod;
    aux = (aux % mod * 7LL % mod)%mod;
  }

  ans = (ans % mod - aux % mod)%mod;

  if(ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}