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

const int INF = 1e9 + 7;
const int nax = 3005;
int dp[nax][nax][4];
int n;
int s[nax], c[nax];

int solve(int i,int j, int k){
  if(k == 0) return 0;
  if(i == n+1) return INF;
  int& state = dp[i][j][k];
  if(state != -1) return state;

  state = INF;
  if(s[i] > s[j]) state = min(state, c[i] + solve(i+1, i, k-1));

  state = min(state, solve(i+1, j, k)); 

  return state;
}

int main(){
  fastio;

  memset(dp, -1, sizeof dp);
  cin >> n;
  s[0] = -INF;
  for(int i=1;i<=n;i++) cin >> s[i];
  for(int i=1;i<=n;i++) cin >> c[i];

  int ans = solve(1, 0, 3);
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  
  return 0;
}