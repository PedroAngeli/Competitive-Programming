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

const int m = 1e9 + 7;

ll pa(ll n){
  return n%m*((n-1)%m)%m * ((m+1)/2)%m;
}
int main(){
  fastio;

  ll n;
  cin >> n;

  ll ans = 0;
  int cnt = 0;

  for(ll i=1;i<=n;i++){
    ll j = n/(n/i);
    ans += ((n/i)%m * (pa(j+1) - pa(i) + m)%m) % m;
    i = j;
  }
  
  cout << ans%m << endl;

  return 0;
}