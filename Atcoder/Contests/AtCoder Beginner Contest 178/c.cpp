#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
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

const ll mod = 1e9 + 7;

int main(){
  fastio;

  ll n;
  cin >> n;

  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  ll total = 1;

  ll w1 = 1;
  ll w2 =1;
  for(int i=0;i<n;i++){
    w1 *= 9, w1 %= mod;
    w2 *= 8, w2 %= mod;
    total *= 10, total %= mod;
  }

  w1 *= 2;
  w1 %= mod;
  ll ans = (total - (w1 - w2) + mod) % mod;  
  cout << ans << endl;

  return 0;
}