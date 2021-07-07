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

vi adj[21];
int dp[(1 << 21)];
int n;
const int mod = 1e9 + 7;

int solve(int j){
  int i = __builtin_popcount(j);
  if(i == n and j == ((1 << n) - 1)) return 1;
  if(i == n) return 0;
  int& state = dp[j];
  if(state != -1) return state;
  state = 0;
  for(int v:adj[i]){
    if((j & (1 << v)) == 0)
    state += solve((j | (1 << v)));
    state %= mod;
  } 

  return state;
}

int main(){
  fastio;

  cin >> n;
  memset(dp, -1, sizeof dp);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int x;
      cin >> x;
      if(x) adj[i].pb(j);
    }
  }

  cout << solve(0) << endl;
  return 0;
}