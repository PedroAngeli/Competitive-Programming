#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

const int INF = 1e9 + 7;

struct Graph{
  vector <vpii> adj; //Vertices are numbered from 1 to V
  int V;
  
  Graph(int V): V(V){
    adj.resize(V+1);
  }

  void addEdge(int u,int v,int w){
    adj[u].pb({v,w});
    adj[v].pb({u,w}); //Comment when graph is direct
  }

  vi dijkstra(int source){ //Returns a vector with distance to all other vertices. O(V log V + E)
    vi dist(V+1,INF);
    dist[source] = 0;

    set <pii> pq;
    pq.insert({0,source});
    
    while(!pq.empty()){
      auto it = pq.begin();
      int d = it->f;
      int u = it->s;
      pq.erase(it);

      if(d > dist[u])
        continue;

      for(auto p : adj[u]){
        int v = p.f;
        int w = p.s;
        if(dist[v] > dist[u] + w){
          dist[v] = dist[u] + w;
          pq.insert({dist[v], v});
        }
      }
    }

    return dist;
  }
};

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 1;
  while(t--){
    cout << "Case #" << ncase++ << ": ";
    int n,m,S,T;
    cin >> n >> m >> S >> T;
    Graph G(n);
    for(int i=0;i<m;i++){
      int u, v , w;
      cin >> u >> v >> w;
      G.addEdge(u,v,w);
    }
    vi dist = G.dijkstra(S);
    int ans = dist[T];
    if(ans == INF) cout << "unreachable";
    else cout << ans;
    cout << endl;
  }
  return 0;
}