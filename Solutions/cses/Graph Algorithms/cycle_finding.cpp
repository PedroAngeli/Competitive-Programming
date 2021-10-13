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

struct Edge{
  int u, v, w;
};

const ll INF = 1e18 + 7;


int main(){
  fastio;

  int n, m;
  cin >> n >> m;

  vector <Edge> edges;

  for(int i=0;i<m;i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    edges.pb({a, b, c});
  }

  vll dist(n, INF);
  dist[0] = 0;

  for(int i=0;i<n-1;i++)
    for(auto [u, v, w]:edges)
      dist[v] = min(dist[v], dist[u] + w);
    
  bool negative = false;

  vi parent(n, -1);

for(int i=0;i<n-1;i++)
  for(auto [u, v, w]:edges)
    if(dist[v] > dist[u] + w){
      negative = true;
      dist[v] = dist[u] + w;
      parent[v] = u;
    }

  if(!negative)
    return cout << "NO" << endl, 0;

  cout << "YES" << endl;

  for(int s=0;s<n;s++){
    vi vis(n, 0);
    vis[s] = 1;
    vi path;
    path.pb(s);
    int u = parent[s];
    while(u != -1 and u != s and !vis[u])
      path.pb(u), vis[u] = 1, u = parent[u];
    if(u == s){
      path.pb(s);
      reverse(all(path));
      for(int x:path)
        cout << x+1 << " ";
      cout << endl;
      return 0;
    }
  }

  return 0;
}