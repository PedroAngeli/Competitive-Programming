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

const int nax = 2e4 + 5;
vi adj[nax];
set <int> querys[nax];
vi ans;

struct UnionFind{
  vi parent;
  int n;
  UnionFind(int n):n(n){
    parent.resize(n+1);
    iota(all(parent),0);
  }
  int find(int x){
    if(x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }
  void join(int x,int y,int w){
    x = find(x);
    y = find(y);

    if(x == y)
      return;

    if(sz(querys[x]) > sz(querys[y]))
      swap(x,y);
    
    for(auto q : querys[x])
      if(querys[y].find(q) != querys[y].end()){
        ans[q] = w;
        querys[y].erase(q);
      }else querys[y].insert(q);

    parent[x] = y;
  }
};

int main(){
  fastio;

  int n,m,q;
  while(cin >> n >> m >> q){
    vector <pair <int,pii> > edges;

    for(int i=1;i<=n;i++){
      adj[i].clear();
      querys[i].clear();
    }
    for(int i=0;i<m;i++){
      int u,v,w;
      cin >> u >> v >> w;
      edges.pb({w,{u,v}});
    }

    sort(all(edges));
    reverse(all(edges));

    UnionFind dsu(n);

    for(int i=0;i<q;i++){
      int u,v;
      cin >> u >> v;
      querys[u].insert(i);
      querys[v].insert(i);
    }

    ans.resize(q);

     for(auto e:edges){
        int w = e.f;
        int u = e.s.f;
        int v = e.s.s;
        dsu.join(u,v,w);
      }

    for(int i=0;i<q;i++)
      cout << ans[i] << endl;
  }
  
  
  
  return 0;
}