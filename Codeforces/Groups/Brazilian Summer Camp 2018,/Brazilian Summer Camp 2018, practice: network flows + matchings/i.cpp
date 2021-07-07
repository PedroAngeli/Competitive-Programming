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

const ll flow_inf = 1e15;

struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Graph {
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi level, ptr;
    queue<int> q;

    Graph(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
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
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
 
int id(int i,int j){
  return i*m + j;
}

bool valid(int i,int j){
  return i>=0 and i < n and j >=0 and j<m;
}

int main(){
  fastio;

  cin >> n >> m;

  vs grid(n);
  for(int i=0;i<n;i++) cin >> grid[i];
  
  int s = n*m;
  int t = n*m + 1;

  Graph G(2*(n+1)*(m+1), s, t);
  int sum = 0;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      for(int k=0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(!valid(x, y)) continue;
        int u = id(i, j);
        int v = id(x, y);
        if((i+j)%2 == 0) G.add_edge(id(i,j), id(x,y), 1);
      }
      ll w = 0;
      if(grid[i][j] == 'H') w = 1;
      if(grid[i][j] == 'O') w = 2;
      if(grid[i][j] == 'N') w = 3;
      if(grid[i][j] == 'C') w = 4;
      sum += w;
      if((i+j)%2 == 0) G.add_edge(s, id(i,j), w);
      else G.add_edge(id(i, j), t, w);
    }
  ll flow = G.flow();
  if(2*flow == sum and sum) cout << "Valid" << endl;
  else cout << "Invalid" << endl;
  return 0;
}