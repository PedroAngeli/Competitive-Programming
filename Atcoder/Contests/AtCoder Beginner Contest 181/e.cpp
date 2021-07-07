#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define fbo find_by_order 
#define ook order_of_key 
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

  int n,m;
  cin >> n >> m;
  vll h(n);
  for(int i=0;i<n;i++) cin >> h[i];
  vll w(m);
  for(int i=0;i<m;i++) cin >> w[i];

  sort(all(h));
  
  vll pref_even_odd(n,0);
  vll suf_odd_even(n+1,0);

  for(int i=0;i<n-1;i++){
    if(i%2) pref_even_odd[i] = pref_even_odd[i-1];
    else{
      pref_even_odd[i] = (h[i+1] - h[i]);
      if(i > 0) pref_even_odd[i] += pref_even_odd[i-1];
    }
  }

  for(int i=n-1;i>=1;i--){
    if(i%2) suf_odd_even[i] = suf_odd_even[i+1];
    else suf_odd_even[i] = suf_odd_even[i+1] + (h[i] - h[i-1]);
  }

  ll ans = LLONG_MAX;

  for(int i=0;i<m;i++){
    int pos = lb(all(h), w[i]) - h.begin();
    if(pos % 2 == 1) pos--;
    ll sum = 0;
    if(pos + 1 < n) sum += suf_odd_even[pos + 1];
    if(pos -1 >= 0) sum += pref_even_odd[pos - 1];
    sum += abs(w[i] - h[pos]);
    ans = min(ans, sum);
  }

  cout << ans << endl;
  return 0;
}