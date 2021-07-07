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

const ll INF = 1e18;

int main(){
  fastio;

  int tc = 1;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    vll t(n+1, INF), x(n);

    for(int i=0;i<n;i++) cin >> t[i] >> x[i];
    
    ll pos = 0, dest = 0;
    int ans = 0;

    for(int i=0;i<n;i++){
      if(pos == dest) dest = x[i];
      ll d = min(t[i+1] - t[i], abs(pos - dest));
      ll m = 1;
      if(dest < pos) m = -1;
      ll p1 = pos;
      ll p2 = pos + m*d;
      if(p1 > p2) swap(p1, p2);
      if(p1 <= x[i] and x[i] <= p2) ans++;
      pos += m*d;
    }

    cout << ans << endl;
  }
  
  return 0;
}