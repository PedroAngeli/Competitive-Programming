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

const ll flow_inf = 1e15;
vector <vi> mat;
int n, m;

struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Graph {
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, M = 0;
    int s, t;
    vi level, ptr, vis;
    queue<int> q;

    Graph(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(M);
        adj[v].push_back(M + 1);
        M += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].v] != -1)
                    continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[t] != -1;
    }

    ll dfs(int u, ll pushed) {
        if (pushed == 0)
            return 0;
        if (u == t)
            return pushed;

        for (int& cid = ptr[u]; cid < sz(adj[u]); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1)
                continue;
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }

        return 0;
    }

    ll flow() {
        ll f = 0;
        while (true) {
            fill(all(level), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(all(ptr), 0);
            while (ll pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
    void path(int u){
      vis[u] = 1;
      for(int id:adj[u]){
        int v = edges[id].v;
        if(vis[v] or edges[id].cap == edges[id].flow) continue;
        path(v);
      }
    }
    vi recover(){
      vi ret;
      vis.assign(n, 0);
      path(s);
      for(int i=0;i<sz(edges);i+=2){
        int u = edges[i].u;
        int v = edges[i].v;
        if(vis[u] and !vis[v]){
          ret.pb(min(u,v));
          assert(u < v);
        }
      }
      return ret;
    }
};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int vin(int i,int j){
  return i*m + j;
}

int vout(int i,int j){
  return i*m + j + n*m;
}

bool valid(int i,int j){
  return i>=0 and i < n and j >=0 and j<m;
}

int main(){
  fastio;

  cin >> n >> m;
  int k, l;
  cin >> k >> l;

  mat.assign(n, vi(m, 1));

  for(int i=0;i<k;i++){
    int x, y;
    cin >> x >> y;
    x--, y--;
    mat[x][y] = 0;
  }

  for(int i=0;i<l;i++){
    int x, y;
    cin >> x >> y;
    x--, y--;
    mat[x][y] = 2;
  }
  
  int xa, ya;
  cin >> xa >> ya;
  xa--, ya--;
  int s = vin(xa, ya);
  int xb, yb;
  cin >> xb >> yb;
  xb--,yb--;
  int t = vout(xb, yb);

  Graph G(2*n*m, s, t);

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      if(mat[i][j] == 0) continue;
      for(int k=0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(!valid(x, y) or mat[x][y] == 0) continue;
        int u = vout(i, j);
        int v = vin(x, y);
        G.add_edge(u, v, flow_inf);
      }
      ll w = flow_inf;
      if(mat[i][j] == 2) w = 1;
      G.add_edge(vin(i,j), vout(i,j), w);
    }

  ll ans = G.flow();
  if(ans >= flow_inf)
    return cout << -1 << endl, 0;
  
  cout << ans << endl;
  vi built = G.recover();
  assert(sz(built)==ans);
  for(int x:built)
    cout << (x/m)+1 << " " << (x%m)+1 << endl; 
  return 0;
}