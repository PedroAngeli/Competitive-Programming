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

ll a,b,n;
ll l,t,m;

ll pa(ll x){
  ll a1 = a;
  ll an = a + (x-1)*b;
  return ((a1 + an)*x)/2;
}

bool can(ll x){
  ll val = a + (x-1)*b;
  if(val > t)
    return false;

  ll canGet = t*m;
  ll sum = pa(x) - pa(l-1);

  return sum <= canGet;
}

int main(){
  fastio;

  cin >> a >> b >> n;

  while(n--){
    cin >> l >> t >> m;

    ll low = l;
    ll high = 1e9;

    ll ans = -1;
    while(low <= high){
      ll mid = (low + high)/2;
      
      if(can(mid))
        low = mid+1,ans = mid;
      else
        high = mid-1;
    }

    cout << ans << endl;
  }

  return 0;
}