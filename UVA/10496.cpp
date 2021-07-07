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

int x_size, y_size;
vpii adj[11];
int n;
int dp[11][2048];
const int INF = 1e9 + 7;

int solve(int u,int mask){
  if(u == 0 and mask == ((1 << (n+1)) - 1)) return 0;
  int& state = dp[u][mask];
  if(state != -1) return state;

  state = INF;

  for(auto p:adj[u]){
    int v = p.f;
    int w = p.s;
    if((mask & (1 << v)) == 0)
      state = min(state, w + solve(v, mask | (1 << v)));
  }

  return state;
}

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    cin >> x_size >> y_size;
    memset(dp, -1, sizeof dp);
    int xi, yi;
    cin >> xi >> yi;

    cin >> n;

    for(int i=0;i<=n;i++) adj[i].clear();

    vi x(n+1), y(n+1);
    x[0] = xi;
    y[0] = yi;
    for(int i=1;i<=n;i++) cin >> x[i] >> y[i];


    for(int i=0;i<=n;i++){
      for(int j=0;j<=n;j++)
        if(i != j)
          adj[i].pb({j, abs(x[i] - x[j]) + abs(y[i] - y[j])});
    }
    cout << "The shortest path has length ";
    cout << solve(0, 0) << endl;
  }
  
  return 0;
}