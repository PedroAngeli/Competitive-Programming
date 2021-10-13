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

int n, k;
vi adj[105];
const int INF = 1e9 + 7;

int bfs(int source){
  vi dist(n, INF);
  queue <int> q;
  q.push(source);
  dist[source] = 0;

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:adj[u]){
      if(dist[v] > dist[u] + 1){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }

  int mx = 0;
  for(int i=0;i<n;i++)
    mx = max(mx, dist[i]);

  return mx;
}

int manh(pii p1, pii p2){
  return abs(p1.f - p2.f) + abs(p1.s - p2.s);
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n >> k;
    for(int i=0;i<n;i++) adj[i].clear();
    
    vpii points(n);
    for(int i=0;i<n;i++){
      cin >> points[i].f >> points[i].s;
      for(int j=0;j<i;j++)
        if(manh(points[i], points[j]) <= k){
          adj[i].pb(j);
          adj[j].pb(i);
        }
    }

    int ans = INF;
    for(int i=0;i<n;i++)
      ans = min(ans, bfs(i));

    if(ans > 1) cout << -1 << endl;
    else cout << ans << endl;
  }
  
  return 0;
}