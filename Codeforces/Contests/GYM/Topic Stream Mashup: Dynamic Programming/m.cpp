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

const int nax = 5005;
ll dp[nax][nax];
int n, m, T;
vpll adj[nax];
const ll INF = 1e15 + 7;
bool vis[nax];

void solve(int u){
  if(vis[u]) return;
  vis[u] = true;

  for(auto p:adj[u]){
    int v = p.f;
    ll t = p.s;
    solve(v);
    for(int i=1;i<=n;i++)
      dp[u][i] = min(dp[u][i], t + dp[v][i-1]);
  }
}

int main(){
  fastio;

  cin >> n >> m >> T;

  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dp[i][j] = INF;
  
  for(int i=0;i<m;i++){
    int u,v;
    ll t;
    cin >> u >> v >> t;
    adj[u].pb({v, t});
  }

  dp[n][1] = 0;

  solve(1);

  int ans = 0;

  for(int j=n;j>=1;j--)
    if(dp[1][j] <= T){
      ans = j;
      break;
    }

  cout << ans << endl;

  vi path;
  path.pb(1);

  int cur = 1;
  int qtd = ans;

  while(cur != n){
    for(auto p:adj[cur]){
      int v = p.f;
      ll t = p.s;
      if(dp[v][qtd-1] + t == dp[cur][qtd]){
        cur = v;
        qtd--;
        break;
      }
    }
    path.pb(cur);
  }

  for(int x:path) 
    cout << x << " ";

  cout << endl;
  return 0;
}