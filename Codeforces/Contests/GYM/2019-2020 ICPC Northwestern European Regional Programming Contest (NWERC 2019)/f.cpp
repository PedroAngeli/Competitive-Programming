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
vpii adj[nax];
int V;
bool vis[nax];

struct UnionFind{
  vi parent;
  vi set_size;
  int n;
  UnionFind(int n):n(n){
    parent.resize(n+1);
    iota(all(parent),0);
    set_size.assign(n+1,1);
  }
  int find(int x){
    if(x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }
  bool join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return false;
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
    return true;
  }
};

void solve(int u){
  vis[u] = true;
  V++;
  for(auto p : adj[u]){
    int v = p.f;
    if(!vis[v])
      solve(v);
  }
}

int main(){
  fastio;

  int n;
  cin >> n;
  map <int,vi> mp;

  for(int i=1;i<=n;i++){
    int m;
    cin >> m;
    while(m--){
      int x;
      cin >> x;
      if(sz(mp[x])){
        adj[i].pb({mp[x].back(),x});
        adj[mp[x].back()].pb({i,x});
      }else
        mp[x].pb(i);
    }
  }

  solve(1);

  if(V < n){
    cout << "impossible" << endl;
    return 0;
  }

  vector <pair<pii,int>> ans;

  UnionFind dsu(n);

  for(int i=1;i<=n;i++){
    for(auto p:adj[i]){
      int v = p.f;
      if(dsu.join(i,v)){
        ans.pb({{i,v},p.s});
      }
    }
  }

  for(auto p:ans)
    cout << p.f.f << " " << p.f.s << " " << p.s << endl;
  

  
  return 0;
}