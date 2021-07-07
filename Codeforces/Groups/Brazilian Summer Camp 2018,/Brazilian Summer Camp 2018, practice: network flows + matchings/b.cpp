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
  int VA, VB;
  vi matchA,matchB;
  vector <bool> visB;

  Graph(int VA,int VB): VA(VA), VB(VB){
    adj.resize(VA+1);
  }

  void addEdge(int u,int v){
    adj[u].pb(v);
  }

  bool dfs(int u){
  for(int v : adj[u]){
    if(visB[v])
      continue;
    visB[v] = true;
    if(matchB[v] == -1 || dfs(matchB[v])){
      matchA[u] = v;
      matchB[v] = u;
      return true;
    }
  }

  return false;
}

  int kuhn(){
    matchA.assign(VA+1,-1);
    matchB.assign(VB+1,-1);
    bool flag = true;
    int matched = 0;

    while(flag){
      flag = false;
      visB.assign(VB+1,false);
      for(int i=1;i<=VA;i++){
        if(matchA[i] != -1)
          continue;
        if(dfs(i)){
          matched++;
          flag = true;
        }
      }
    }

    return matched;
}
};

bool removed[41][41];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, p;

int map_coord(int i,int j){
  return (i-1)*n + j;
}

bool valid(int i,int j){
  return i>=1 and i<=n and j>=1 and j<=n and !removed[i][j];
}

int main(){
  fastio;

  cin >> n >> p;
  
  Graph G(n*n, n*n);

  for(int i=0;i<p;i++){
    int c, l;
    cin >> c >> l;
    l = n-l+1;
    removed[l][c] = true;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(removed[i][j]) continue;
      if((i-1+j-1)%2) continue;
      for(int k=0;k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(!valid(x, y)) continue;
        int u = map_coord(i, j);
        int v = map_coord(x, y);
        G.addEdge(u, v);
      }
    }
  }

  int flow = G.kuhn();
  int rest = n*n - p;
  if(flow*2 != rest){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  int hor = 0, ver = 0;

  vpii ans_hor, ans_ver;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(removed[i][j]) continue;
      if((i-1+j-1)%2) continue;
      int u = map_coord(i, j);
      if(G.matchA[u] == u+1){
        hor++;
        ans_hor.pb({n-i+1, j});
      }else if(G.matchA[u] == u-1){
        hor++;
        ans_hor.pb({n-i+1, j-1});
      }else if(G.matchA[u] == u+n){
        ver++;
        ans_ver.pb({n-i, j});
      }else{
        ver++;
        ans_ver.pb({n-i+1, j});
      }
    }
  }

  cout << hor << endl;
  for(auto el:ans_hor)  
    cout << el.s << " " << el.f << endl;

  cout << ver << endl;
  for(auto el:ans_ver)
    cout << el.s << " " << el.f << endl;
  return 0;
}