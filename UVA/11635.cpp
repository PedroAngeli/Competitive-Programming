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

const int nax = 1e4 + 5;
vpii adj[nax];
vi new_adj[nax];
int n;
const int INF = 1e9 + 7;

vi solve(int source){
    vi dist(n+1,INF);
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

int solve2(int source){
  vi dist(n+1,INF);
  dist[source] = 0;
  queue <int> q;
  q.push(source);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int v:new_adj[u])
      if(dist[v] > dist[u] + 1){
        dist[v] = dist[u] + 1;
        q.push(v);
      }
  }

  return dist[n] == INF ? INF : dist[n] - 1;
}

int main(){
  fastio;

  while(cin >> n && n){
    for(int i=1;i<=n;i++) adj[i].clear(), new_adj[i].clear();

    int h;
    cin >> h;
    vi hotels(h+2);
    hotels[0] = 1;
    for(int i=1;i<=h;i++) cin >> hotels[i];
    hotels[h+1] = n;

    int m;
    cin >> m;
    while(m--){
      int u,v,w;
      cin >> u >> v >> w;
      adj[u].pb({v,w});
      adj[v].pb({u,w});
    }
    
    vector<vi>dist(h+2);
    for(int i=0;i<=h+1;i++){
      dist[i] = solve(hotels[i]);
      for(int j=0;j<i;j++){
        int u = hotels[i];
        int v = hotels[j];
        if(dist[i][v] > 600) continue;
        new_adj[u].pb(v);
        new_adj[v].pb(u);
      }
    }
    
    int ans = solve2(1);

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
  }
  
  return 0;
}