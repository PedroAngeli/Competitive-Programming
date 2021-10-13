#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


ll mySqrt(ll x){
  ll l = 0,r=1e9;
  ll ret;

  while(l <= r){
    ll m = (l+r)/2;
    if(m*m == x)
      return m;
    if(m*m > x)
      r = m-1;
    else
      ret=m,l = m+1;
  }

  return ret;
}
int main(){
  fastio;

  int q;
  cin >> q;
  ll nax = 1e18;

  vll nums;

  for(ll i=2;i<=1e6;i++){
    for(ll j=i*i*i;j<=nax;j*=i){
      ll root = mySqrt(j);
      if(root*root != j)
        nums.push_back(j);
      if(j > nax/i)
        break;
    }
  }

  sort( nums.begin(), nums.end() );
  nums.erase( unique( nums.begin(), nums.end() ), nums.end() );

  while(q--){
    ll l,r;
    cin >> l >> r;
    ll ans = (upper_bound(nums.begin(),nums.end(),r) - lower_bound(nums.begin(),nums.end(),l));
    ans += mySqrt(r)-mySqrt(l-1);

    cout << ans << endl;
  }
  return 0;
}