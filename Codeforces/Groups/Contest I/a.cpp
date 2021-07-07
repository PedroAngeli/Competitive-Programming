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
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << "[" << name << " : " << arg1 << "]" << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr << "[";
cerr.write(names, comma - names) << " : " << arg1<<"] | ";__f(comma+1, args...);
}

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;


int main(){
  fastio;

  int n,k;
  cin >> n >> k;
  vll a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }  
  vll pref(n),mod(n);
  pref[0] = a[0], mod[0] = a[0]%k;
  for(int i=1;i<n;i++){
    pref[i] = a[i] + pref[i-1];
    mod[i] = (pref[i]%k + k)%k;
  }

  map <int,ll> mp;
  ll ans = 0;
  mp[0] = 0;
  for(int i=0;i<n;i++){
    int cur = mod[i];
    if(mp.count(cur)){
      ans = max(ans, pref[i] - mp[cur]);
      mp[cur] = min(mp[cur], pref[i]);
    }else
      mp[cur] = pref[i];
  }

  cout << ans << endl; 
  return 0;
}