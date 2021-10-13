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

const int nax = 2e5 + 5;
const int max_log = 20;
int anc[max_log][nax]; //anc[k][u] is ancestral of u after jump 2^k
int n,q;
vi adj[nax];
int height[nax];

void dfs(int u = 1, int h = 0,int p = -1){
    height[u] = h;
    for(int v:adj[u])
      if(p != v){
        anc[0][v] = u;
        dfs(v, h+1, u);
      }
}
  
void build(int n){
    memset(anc, -1, sizeof anc);
    dfs();
    for(int p=1;p<max_log;p++) //for every 2^p jump
      for(int u=1;u<=n;u++){
        int mid = anc[p-1][u];
        if(mid != -1) anc[p][u] = anc[p-1][mid];
      }
}

int walk(int u,int k){ //jump u k times
  for(int i=max_log-1;i>=0;i--) //if the i-th bit is set, jump 2^i times.
      if((1 << i) & k){
        u = anc[i][u];  //u can be -1, be careful
        if(u == -1) return u;
      } 
  
  return u;
}

int lca(int u,int v){
    if(height[u] < height[v]) swap(u,v);
    u = walk(u, height[u] - height[v]);

    if(u == v) return u;

    for(int p=max_log-1;p>=0;p--)
      if(anc[p][u] != anc[p][v]){
         u = anc[p][u];
         v = anc[p][v];
      }

    return anc[0][u];
  }

int dist(int u,int v){
    return height[u] + height[v] - 2*height[lca(u,v)];
}

int main(){
  fastio;

  cin >>n >> q;

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }

  build(n);

  while(q--){
    int a, b;
    cin >> a >> b;
    cout << dist(a, b) << endl;
  }
  return 0;
}