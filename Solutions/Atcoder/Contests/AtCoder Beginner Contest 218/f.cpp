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

const int nax = 405;
bool shortest_path[nax][nax];

int main(){
  fastio;

  int n, m;
  cin >> n >> m;

  vector <int> adj[n+1];
  vector <pair <int,int>> edges;
  
  for(int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    edges.push_back({u, v});
  }

  vector <int> d(n+1, 405);
  d[1] = 0;
  queue <int> q;
  vector <int> parent(n+1, -1);
  q.push(1);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    
    for(int v:adj[u])
      if(d[v] > d[u]+1){
        d[v] = d[u]+1;
        q.push(v);
        parent[v] = u;
      }
  }

  int u = n;
  while(parent[u] != -1){
    shortest_path[parent[u]][u] = true;
    u = parent[u];
  }
  for(auto e:edges){
    int x = e.f, y = e.s;
    if(!shortest_path[x][y]){
      if(d[n] == nax)
        d[n] = -1;
      cout << d[n] << endl;
      continue;
    }
    vector <int> dist(n+1, 405);
    dist[1] = 0;
    queue <int> q;
    q.push(1);
    while(!q.empty()){
      int u = q.front();
      q.pop();
      
      for(int v:adj[u]){
        if(u == x and v == y) continue;
        if(dist[v] > dist[u]+1){
          dist[v] = dist[u]+1;
          q.push(v);
        }
      }
    }
    if(dist[n] == nax)
      dist[n] = -1;
    cout << dist[n] << endl;
  }
  
  
  return 0;
}