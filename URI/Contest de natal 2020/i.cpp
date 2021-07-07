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

struct Graph{
  vector <vi> adj; //Vertices are numbered from 1 to V
  int V;
  const int INF = 1e9 + 7;
  vi parent;

  Graph(int V): V(V){
    adj.resize(V+1, vi(V+1,0));
  }

  void addEdge(int u,int v,int w){
    adj[u][v] = w;
    // adj[v][u] = w;
  }

  bool augment_path(int source,int sink){
    vector <bool> vis(sink+1,false);
    queue <int> q;
    vis[source] = true;
    q.push(source);

      while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0;v<=sink;v++){
          if(adj[u][v] == 0 || vis[v])
            continue;
          vis[v] = true;
          q.push(v);
          parent[v] = u;
        }
    }

    return vis[sink];
  }

  int edmonds_karp(int source,int sink){ //O(VE²) no geral e O(VE) em grafo bipartido
    int max_flow = 0;
    parent.resize(V+1);

    while(augment_path(source,sink)){
      int path_flow = INF;
      int v = sink;

      while(v != source){
        int u = parent[v];
        path_flow = min(path_flow, adj[u][v]);
        v = u;
      }

      v = sink;

      while(v != source){
        int u = parent[v];
        adj[u][v] -= path_flow;
        adj[v][u] += path_flow;
        v = u;
      }

      max_flow += path_flow;
    }

    return max_flow;
  }
};

int main(){
  fastio;

  int n, m;
  while(cin >> n >> m){
    Graph G(n);
    for(int i=0;i<m;i++){
      int u, v, w;
      cin >> u >> v >> w;
      G.addEdge(u, v, w);
    }
    int ans = G.edmonds_karp(1, n);
    if(ans == 0) cout << "Nao eh possivel produzir nenhum brinquedo" << endl;
    else cout << ans << endl;
  }
  
  return 0;
}