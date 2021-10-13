#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

ll ans;

struct UnionFind{
  vector <int> parent;
  vector <int> set_size;
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
  void join(int x,int y,int w){
    x = find(x);
    y = find(y);
    if(x == y)
      return;
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    ans += (1LL*set_size[x]*set_size[y]*w);
    set_size[y] += set_size[x];
  }
};

int main(){
  fastio;

  int n;
  cin >> n;

  UnionFind dsu(n);
  vector <pair <int, pair <int,int> > > edges;
  for(int i=0;i<n-1;i++){
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
  }

  sort(all(edges));
  for(auto e:edges){
    dsu.join(e.s.f, e.s.s, e.f);
  }

  cout << ans << endl;
  return 0;
}