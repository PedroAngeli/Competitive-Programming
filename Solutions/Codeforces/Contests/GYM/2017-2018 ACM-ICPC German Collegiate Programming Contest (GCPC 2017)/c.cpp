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

const int nax = 100;
const int INF = 1e9 + 7;
int n,m,t;
vi adj[nax];
vi cost;
vi time_spend;
ll dp[1000][1001];

ll solve(int u,int x){
  if(x < 0) return INF;

  if(x == 0 && u == 0){
    return 0;
  } 

  ll& state = dp[u][x];
  if(state != -1) return state;

  state = INF;
  state = min(state,cost[u] + solve(u, x-time_spend[u]));

  for(int v:adj[u])
    state = min(state, cost[u] + solve(v, x - time_spend[u] - t));

  return state;
}

int main(){
  fastio;
  int x;
  cin >> x;
  cin >> n >> m >> t;

  cost.resize(n);
  time_spend.resize(n);
  memset(dp,-1,sizeof dp);

  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--,v--;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  for(int i=0;i<n;i++)
    cin >> time_spend[i] >> cost[i];

  ll ans = cost[0] + solve(0,x - time_spend[0]);

  if(ans >= INF) cout << "It is a trap." << endl;
  else cout << ans << endl;
  return 0;
}