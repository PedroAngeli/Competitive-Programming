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
  vector <vi> adj; 
  int V;
  vi in_stack;
  vi dfs_num;
  vi dfs_low;
  int dfs_counter;
  stack <int> p;
  int id_comp;
  vi comp;

  Graph(int V): V(V){
    comp.resize(V);
    adj.resize(V);
  }

  void addEdge(int u,int v){
    adj[u].pb(v);
  }
  
  void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    p.push(u);
    in_stack[u] = 1;

    for(int v : adj[u]){
      if(dfs_num[v] == -1){
        dfs(v);
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }else if(in_stack[v])
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){
      while(true){
        int v = p.top();
        comp[v] = id_comp;
        in_stack[v] = 0;
        p.pop();
        if(u == v)
          break;
      }
      id_comp++;
    }
  }

  void tarjanSCC(){
    in_stack.assign(V,0);
    dfs_num.assign(V,-1);
    dfs_low.resize(V);
    dfs_counter = 0;
    id_comp = 0;
    for(int i=0;i<V;i++){
      if(dfs_num[i] == -1)
        dfs(i);
    }
  }
  int neg(int u){
    return u ^ 1;
  }

  void add_or(int u,int v){
    addEdge(neg(u), v);
    addEdge(neg(v), u);
  }

  void force_var(int u){
    addEdge(neg(u), u);
  }
};

int main(){
  fastio;

  int n,m;
  cin >> n >> m;
  vi door(n);
  for(int i=0;i<n;i++) cin >> door[i];

  vector <vi> control(n);

  for(int i=0;i<m;i++){
    int x;
    cin >> x;
    while(x--){
      int d;
      cin >> d;
      d--;
      control[d].pb(i);
    }
  } 
  Graph G(2*m);
  for(int i=0;i<n;i++){
    int u = control[i][0];
    int v = control[i][1];
    u *= 2;
    v *= 2;
    if(door[i]){
      G.add_or(u, G.neg(v));
      G.add_or(v, G.neg(u));
    }else{
      G.add_or(u, v);
      G.add_or(G.neg(u), G.neg(v));
    } 
  }

  G.tarjanSCC();

  bool can = true;
  for(int i=0;i<2*m;i++){
    if(G.comp[i] == G.comp[G.neg(i)]) can = false;
  }

  cout << (can ? "YES" : "NO") << endl;
  return 0;
}