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

int n;
float dp[20][(1 << 20)];
float adj[20][20];

float squared(float x){
  return x*x;
}

float solve(int u, int mask){
  if((mask == ((1 << n) - 1))) return adj[u][0];
  float& state = dp[u][mask];
  if(state > -0.5) return state;
  state = FLT_MAX;
  
  for(int i=0;i<n;i++){
    if(i == u or (mask & (1 << i))) continue;
    state = min(state, adj[u][i] + solve(i, mask | (1 << i)));
  }

  return state;
}

int main(){
  fastio;
  
  cin >> n;
  vi x(n), y(n);

  memset(dp, -1, sizeof dp);

  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
    for(int j=0;j<i;j++){
      float d = sqrt(squared(x[i]-x[j]) + squared(y[i]-y[j]));
      adj[i][j] = d;
      adj[j][i] = d;
    }
  }

  cout << fixed << setprecision(6) << solve(0, 0) << endl;
  
  return 0;
}