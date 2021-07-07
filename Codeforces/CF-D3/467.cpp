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

map <string,int> mp1;
map <int,string> mp2;
vi qtd_r;
vi word_size;

int count_r(string& a){
  int q = 0;
  for(char c:a)
    if(c == 'r')
      q++;
  return q;
}

bool is_better(int a,int b){
  int qa = qtd_r[a];
  int qb = qtd_r[b];

  return (qa < qb) || (qa == qb && word_size[a] < word_size[b]);
}

void format(string& a){
  for(char& c : a){
    if(isupper(c))
      c = tolower(c);
  }
}

struct Graph{
  vector <vi> adj; 
  int V = 1e5 + 5;
  vi in_stack;
  vi dfs_num;
  vi dfs_low;
  int dfs_counter;
  stack <int> p;
  vector <vi> SCC;
  vi comp;
  vi best_of_comp;
  vector <vi> adj_dag;
  vi visited;

  Graph(){
    adj.resize(V+1);
    adj_dag.resize(V+1);
    comp.resize(V+1);
    best_of_comp.resize(V+1);
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
      vi tmp;
      while(true){
        int v = p.top();
        in_stack[v] = 0;
        p.pop();
        tmp.pb(v);
        if(u == v)
          break;
      }
      SCC.pb(tmp);
    }
  }

  void tarjanSCC(){
    in_stack.assign(V,0);
    dfs_num.assign(V,-1);
    dfs_low.resize(V);
    dfs_counter = 0;

    for(int i=1;i<V;i++){
      if(dfs_num[i] == -1)
        dfs(i);
    }

    for(int i=0;i<sz(SCC);i++){
      int best = -1;
      for(int v:SCC[i]){
        comp[v] = i;
        if(best == -1 || is_better(v,best))
          best = v;
      }
      best_of_comp[i] = best;
    }
  }

  void pick_best(int u){
    if(visited[u])
      return;

    visited[u] = 1;

    for(int v:adj_dag[u]){
      pick_best(v);
      if(is_better(best_of_comp[v],best_of_comp[u]))
        best_of_comp[u] = best_of_comp[v];
    }

    return;
  }

  void find_DAG(){      
    for(int i=0;i<V;i++){
      for(int u:adj[i])
        if(comp[i] != comp[u])
          adj_dag[comp[i]].pb(comp[u]);
    }

    visited.assign(sz(SCC),0);
    for(int i=0;i<sz(SCC);i++)
      if(!visited[i])
        pick_best(i);  
  }
};



int main(){
  fastio;

  int m;
  cin >> m;
  int idx = 1;
  vs essay;
  qtd_r.resize(1e5 + 5);
  word_size.resize(1e5 + 5);

  while(m--){
    string a;
    cin >> a;
    format(a);
    essay.pb(a);

    if(!mp1.count(a)){
      mp1[a] = idx;
      mp2[idx++] = a;
    }
    int u = mp1[a];
    qtd_r[u] = count_r(a);
    word_size[u] = sz(a);
  }

  int n;
  cin >> n;
  Graph G;

  while(n--){
    string a,b;
    cin >> a >> b;
    format(a);
    format(b);

    if(!mp1.count(a)){
      mp1[a] = idx;
      mp2[idx++] = a;
    }
    if(!mp1.count(b)){
      mp1[b] = idx;
      mp2[idx++] = b;
    }

    int u = mp1[a];
    int v = mp1[b];
    qtd_r[u] = count_r(a);
    word_size[u] = sz(a);

    word_size[v] = sz(b);
    qtd_r[v] = count_r(b);

    G.addEdge(u,v);
  }

  G.tarjanSCC();
  G.find_DAG();
  
  ll ans1 = 0, ans2 = 0;

  for(string& S : essay){
    int u = mp1[S];
     int best = G.best_of_comp[G.comp[u]];
     ans1 += qtd_r[best];
     ans2 += word_size[best];
  }

  cout << ans1 << " " << ans2 << endl;

  return 0;
}