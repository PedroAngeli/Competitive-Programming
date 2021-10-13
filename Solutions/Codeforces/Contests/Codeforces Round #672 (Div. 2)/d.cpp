#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl
 
using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;
 
const int mod = 998244353;
 
int main(){
  fastio;
 
  int n,k;
  cin >> n >> k;
   
  vll f1(n+1);
  vll f2(n+1);
  vll inv(n+1);
  inv[1] = 1;
  for(ll i=2;i<=n;i++)
    inv[i] = mod - (mod/i) * inv[mod%i] % mod;
 
  f1[0] = f2[0] = 1;
  for(ll i=1;i<=n;i++){
    f1[i] = (i*f1[i-1])%mod;
    f2[i] = (f2[i-1]*inv[i])%mod;
  }

  vpii events;
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    events.pb({l,1});
    events.pb({r,2});
  }

  sort(all(events));

  int on = 0;
  ll ans = 0;

  for(int i=0;i<sz(events);i++){
    int type = events[i].s;
    if(type == 1)
      on++;
    else{
      on--;
      if(on < k-1)
        continue;
      ans += f1[on]*f2[k-1]%mod*f2[on-(k-1)]%mod;
      ans %= mod;
    }
  }
  
  cout << ans << endl;
  return 0;
}
