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

ll dp[105][100005];
ll pref[105][100005];
const int mod = 1e9 + 7;


int query(int i,int l,int r){
  if(l == 0) return pref[i][r];
  return pref[i][r] - pref[i][l-1];
}

int main(){
  fastio;

  int n,k;
  cin >> n >> k;
  vi a(n);

  for(int i=1;i<=n;i++) cin >> a[i];

  dp[0][0] = 1;
  pref[0][0] = 1;

  for(int i=1;i<=n;i++)
    for(int j=0;j<=k;j++){
      int l = max(0, j - a[i]);
      int r = j;
      dp[i][j] += query(i-1, l, r);
      dp[i][j] %= mod, dp[i][j] += mod, dp[i][j] %= mod;
      pref[i][j] = dp[i][j];
      if(j >= 0) pref[i][j] += pref[i][j-1];
      pref[i][j] %= mod, pref[i][j] += mod, pref[i][j] %= mod;
    }



      // for(int x=0;x<=a[i];x++)
      //   if(j >= x){
      //     dp[i][j] += dp[i-1][j - x];
      //     dp[i][j] %= mod;
      //   }

  
  ll ans = pref[n][k];

  cout << ans << endl;
  return 0;
}