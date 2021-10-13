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

vs grid;
vi cost;
const int INF = 1e9 + 7;
int n,m,c;


bool valid(int i,int j){
  return i>=0 && i < n && j >=0 && j < m;
}

bool letter(char c){
  return c>='a' && c<='z';
}

struct Graph{
  vector <vll> adj; 
  int V;
  vi parent;

  Graph(int V): V(V){
    adj.resize(V+1, vll(V+1,0));
  }

  void addEdge(int u,int v,int w){
    adj[u][v] = w;
  }

  bool augment_path(int source,int sink){
    vector <bool> vis(V+1,false);
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

  ll edmonds_karp(int source,int sink){ 
    ll max_flow = 0;
    parent.resize(V+1);
    while(augment_path(source,sink)){
      ll path_flow = INF;
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

  bool can(int i,int j){
    queue <pii> q;
    q.push({i,j});
    vector <vi> vis(V+1,vi(V+1,0));
    vis[i][j] = 1;

    while(!q.empty()){
      int x = q.front().f;
      int y = q.front().s;
      if(x == 0 || x == n-1 || y == 0 || y==m-1)
        return true;
      q.pop();
      vpii mov = {{0,-1},{0,1},{1,0},{-1,0}};
      
      for(auto p:mov){
        int x2 = x + p.f;
        int y2 = y + p.s;
        if(!valid(x2,y2) || vis[x2][y2] || letter(grid[x2][y2]))
          continue;
        vis[x2][y2] = 1;
        q.push({x2,y2});
      }
    }

    return false;
  }
};

int id(int i,int j){
  return i*m + j;
}

int main(){
  fastio;

  cin >> n >> m >> c;
  swap(n,m);
  
  grid.resize(n);
  for(int i=0;i<n;i++)
    cin >> grid[i];
  
  cost.resize(c);

  for(int i=0;i<c;i++)
    cin >> cost[i];
  
  Graph G(2*n*m);
  
  int source,sink;
  sink = 2*n*m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(grid[i][j] == 'B'){
        source = id(i,j);
        if(G.can(i,j)){
          cout << -1 << endl;
          return 0;
        }
      }

  vpii mov = {{0,-1},{0,1},{1,0},{-1,0}};

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        if(grid[i][j] == '.' || grid[i][j] == 'B')
          G.addEdge(id(i,j),id(i,j)+n*m, INF);
        else
          G.addEdge(id(i,j),id(i,j)+n*m, cost[grid[i][j] - 'a']);
      
      for(auto p:mov){
        int x = i+p.f;
        int y = j+p.s;
        if(!valid(x,y))
          continue;
        int my_out = id(i,j) + n*m;
        G.addEdge(my_out, id(x,y), INF);
      }

      if(i == 0 || j == 0 || i == n-1 || j==m-1)
        G.addEdge(id(i,j)+n*m, sink,INF);
    }
      
  cout << G.edmonds_karp(source,sink) << endl;
  return 0;
}