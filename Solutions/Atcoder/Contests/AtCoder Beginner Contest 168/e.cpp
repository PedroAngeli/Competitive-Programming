#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
typedef long long ll;
const int mod = 1e9 + 7;

ll pot(ll a,ll b){
  ll ans = 1;

  while(b){
    if(b & 1){
      ans = ans * a % mod;
    }
    b = b >> 1;
    a = a*a % mod;
  }

  return ans;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

 
  int n;
  cin >> n;
  map <pair <ll,ll>, pair <ll,ll> > mp;

  int pair_zeros = 0;

  while(n--){
    ll a, b;
    cin >> a >> b;
    if(a == 0 && b == 0)
      pair_zeros++;
    else if(a == 0 && b)
      mp[{0,1}].first++;
    else if(a && b == 0)
      mp[{0,1}].second++;
    else{
      int neg = 0;
      if(a < 0)
        a=-a,neg++;
      if(b < 0)
        b=-b,neg++;

      ll mdc = __gcd(a,b);
      a/=mdc;
      b/=mdc;

      if(neg == 1)
        mp[{a,b}].second++;
      else
        mp[{b,a}].first++;
    }

  }

   ll ans = 1;

    for(auto it=mp.begin();it!=mp.end();it++){
      ll x = it->second.first;
      ll y = it->second.second;
      ll prod = (((pot(2,x) + pot(2,y) - 1)%mod)+mod)%mod;
      ans = (((ans * prod)%mod)+mod)%mod;
    }

    ans = (((ans + pair_zeros -1)%mod)+mod)%mod;

    cout << ans << endl;

  return 0;
}