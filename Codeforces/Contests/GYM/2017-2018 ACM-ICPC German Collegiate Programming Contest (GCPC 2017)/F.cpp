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

struct FlowEdge {
    int u, v;
    ll cap, flow = 0, sflow;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
    const ll flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n+10);
        level.resize(n+10);
        ptr.resize(n+10);
    }

    void add_edge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(m);
        adj[v].push_back(m + 1);
        m += 2;
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

    void save_flow(){
        for(auto& e:edges) e.sflow = e.flow;
    }

    void restore_flow(){
        for(auto& e:edges) e.flow = e.sflow;
    }
};

int main(){
  fastio;

  int n,m,k;
  cin >> m >> n >> k;
  
   int source = 0;
  int sink = n+m+1;

  Dinic din(n+m+1, source, sink);

  for(int i=0;i<k;i++){
      int u,v;
      cin >> u >> v;
      din.add_edge(u, v + m, 1);
  }

  for(int u=1;u<=m;u++) din.add_edge(source, u, 1);
  for(int u=1;u<=n;u++) din.add_edge(u + m, sink, 1);

  int base = din.flow();
  din.save_flow();
  int ans = base;

  for(int u=1;u<=m;u++){
    din.restore_flow();
    din.add_edge(source, u, 2);
    int fl = din.flow();
    din.edges.pop_back();
    din.edges.pop_back();
    din.adj[source].pop_back();
    din.adj[u].pop_back();
    din.m -= 2;
    ans = max(ans, base + fl);
    if(ans == n || ans == base + 2) break;
  } 
 

  cout << ans << endl;
  
  return 0;
}