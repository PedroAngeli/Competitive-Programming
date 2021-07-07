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
  int u, v, c, p, day;
};

const ll flow_inf = 1e18;

int n, m, d, total_participants;
vector <Edge> flights;
int participants[31];
int id[31][11];

struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {
    vector<FlowEdge> edges;
    vector<vi> adj;
    int n, m = 0;
    int s, t;
    vi level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
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

int get_id(int city, int day){
  return id[city][day];
}

bool can(int x){
  Dinic din(331, 0, get_id(n, d));

  for(int i=1;i<=n;i++)
    din.add_edge(0, get_id(i, 0), participants[i]);
  
  for(auto e:flights){
    if(e.p <= x)
      din.add_edge(get_id(e.u, e.day), get_id(e.v, e.day+1), e.c);
  }

  for(int i=1;i<=n;i++)
    for(int j=0;j<d;j++)
      din.add_edge(get_id(i, j), get_id(i, j+1), flow_inf);

  return din.flow() == total_participants;
}

int main(){
  fastio;

  int t;
  cin >> t;
  int idx = 1;
  for(int i=1;i<=30;i++)
    for(int j=0;j<=10;j++)
      id[i][j] = idx++;

  for(int tt=1;tt<=t;tt++){
    total_participants = 0;
    cout << "Case #" << tt << ": ";
    cin >> n >> d >> m;
    flights.resize(m);
    for(int i=0;i<m;i++) 
      cin >> flights[i].u >> flights[i].v >> flights[i].c >> flights[i].p >> flights[i].day;

    for(int i=1;i<=n;i++){
      cin >> participants[i];
      total_participants += participants[i];
    } 

    int l = 0;
    int r = 1e5;
    int ans = -1;
    while(l <= r){
      int mid= (l+r)/2;
      if(can(mid)) ans = mid, r = mid-1;
      else l = mid+1;
    }
    if(ans == -1) cout << "Impossible" << endl;
    else cout << ans << endl;
  }
    
  return 0;
}