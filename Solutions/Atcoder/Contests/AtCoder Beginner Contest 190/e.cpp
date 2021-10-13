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
vi adj[nax];
int c[17];
int n, m, k;
int dist[17][17];
int dp[17][(1 << 17)];
const int INF = 1e9 + 7;

int solve(int u, int mask){
  if(mask == ((1 << k)-1)) return 0;
  int& state = dp[u][mask];
  if(state != -1) return state;
  state = INF;
  for(int v=0;v<k;v++){
    if(mask & (1 << v)) continue;
    state = min(state, dist[u][v] + solve(v, (1 << v) | mask));
  }

  return state;
}

vi bfs(int source){
  vi d(n+1, INF);
  queue <int> q;
  q.push(source);
  d[source] = 0;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:adj[u])
      if(d[v] > 1 + d[u]){
        d[v] = 1 + d[u];
        q.push(v);
      }
  }

  return d;
}

int main(){
  fastio;

  for(int i=0;i<17;i++)
    for(int j=0;j<17;j++)
      dist[i][j] = INF;

  memset(dp, -1, sizeof dp);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }


  cin >> k;
  for(int i=0;i<k;i++){
    cin >> c[i];
  }

  for(int i=0;i<k;i++){
    vi d = bfs(c[i]);
    for(int j=0;j<k;j++)
      dist[i][j] = d[c[j]];
  }

  int ans = INF;

  for(int i=0;i<k;i++)
    ans = min(ans, solve(i, 1 << i));

  if(ans == INF) ans = -1;
  else ans++;


  cout << ans << endl;

  return 0;
}