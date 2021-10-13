#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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
const int mod = 998244353;
const int nax = 1001;
const int INF = 1e9 + 7;
int n, m, k;
vector <int> a;
vector <int> adj[nax];
vector <pair <int,int>> edges;
int cnt_path[nax][nax];
int dp[nax][100*nax];
int total;

int solve(int i, int R){
  if(i == n-1){
    int B = total - R;
    if(R-B == k) return 1;
    return 0;
  }
  int& state = dp[i][R];
  if(state != -1)
    return state;
  
  int u = edges[i].f;
  int v = edges[i].s;
  ll p1 = solve(i+1, cnt_path[u][v] + R);
  ll p2 = solve(i+1, R);
  return state = (p1 + p2)%mod;
}

void bfs(int source, int dest){
  vector <int> dist(n+1, INF);
  vector <int> parent(n+1, -1);
  dist[source] = 0;
  queue <int> q;
  q.push(source);
  
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:adj[u]){
      if(dist[v] > dist[u]+1){
        dist[v] = dist[u]+1;
        parent[v] = u;
        q.push(v);
      }
    }
  }

  int node = dest;
  while(parent[node] != -1){
    int u = parent[node];
    int v = node;
    if(u > v)
      swap(u, v);
    cnt_path[u][v]++;
    node = parent[node];
  }
}

int main(){
  fastio;
  cin >> n >> m >> k;
  a.resize(m);

  for(int i=0;i<m;i++)
    cin >> a[i];
  
  for(int i=0;i<n-1;i++){
    int u, v;
    cin >> u >> v;
    if(u > v)
      swap(u, v);
    edges.push_back({u, v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=0;i<m-1;i++){
    int u = a[i];
    int v = a[i+1];
    bfs(u, v);
  }

  for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      total += cnt_path[i][j];

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0) << endl;

  return 0;
}