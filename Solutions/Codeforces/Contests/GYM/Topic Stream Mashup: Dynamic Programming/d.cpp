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

const int nax = 1e5 + 5;
int a[nax];
int t[nax];
int n, k;
int pref[nax];
int dp[nax][2];

int solve(int i,int j){
  if(i == n+1) return 0;
  int& state = dp[i][j];
  if(state != -1) return state;
  state = 0;

  if(j and i+k <= n+1) state = (pref[i+k-1]-pref[i-1]) + solve(i+k, 0);

  if(t[i]) state = max(state, a[i] + solve(i+1, j));
  else state = max(state, solve(i+1, j));

  return state;
}

int main(){
  fastio;
  memset(dp, -1, sizeof dp);
  cin >>n >> k;
  for(int i=1;i<=n;i++){
    cin >> a[i];
    pref[i] = pref[i-1] + a[i];
  } 
  for(int i=1;i<=n;i++) cin >> t[i];

  cout << solve(1, 1) << endl;
  return 0;
}