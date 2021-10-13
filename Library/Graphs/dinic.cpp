#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
const ll INF = 1e18;
struct FlowEdge {
    int u, v;
    ll cap, flow = 0;
    FlowEdge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};
struct Dinic {
    vector<FlowEdge> edges;
    vector<vector <int>> adj;
    int V, E = 0;
    int source, sink;
    vector <int> level, ptr;
    queue<int> q;
    Dinic(int V, int source, int sink) : V(V), source(source), sink(sink) {
        adj.resize(V+1);
        level.resize(V+1);
        ptr.resize(V+1);
    }
    void add_edge(int u, int v, ll cap) {
        edges.emplace_back(u, v, cap);
        edges.emplace_back(v, u, 0);
        adj[u].push_back(E);
        adj[v].push_back(E + 1);
        E += 2;
    }
    bool bfs() {
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int id : adj[u]) {
                if (edges[id].cap - edges[id].flow < 1) continue;
                if (level[edges[id].v] != -1) continue;
                level[edges[id].v] = level[u] + 1;
                q.push(edges[id].v);
            }
        }
        return level[sink] != -1;
    }
    ll dfs(int u, ll pushed) {
        if (pushed == 0) return 0;
        if (u == sink) return pushed;
        for (int& cid = ptr[u]; cid < sz(adj[u]); cid++) {
            int id = adj[u][cid];
            int v = edges[id].v;
            if (level[u] + 1 != level[v] || edges[id].cap - edges[id].flow < 1) continue;
            ll tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0) continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    //Retorna o fluxo em O(V²E) no caso geral ou em O(sqrt(V)E) para grafo bipartido
    ll flow() {
        ll mf = 0;
        while (true) {
            fill(all(level), -1);
            level[source] = 0;
            q.push(source);
            if (!bfs()) break;
            fill(all(ptr), 0);
            while (ll pushed = dfs(source, INF)) mf += pushed;
        }
        return mf;
    }
};