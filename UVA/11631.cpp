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

struct Edge{
  int u,v,w;
};

vector <Edge> edges;
int n,m;

int mst(){
  sort(all(edges),[&](Edge e1, Edge e2){
    return e1.w < e2.w;
  });
  int cost = 0;
  UnionFind dsu(n);

  for(auto e:edges){
    if(dsu.join(e.u, e.v)) cost += e.w;
  } 

  return cost; 
}

int main(){
  fastio;

  while(cin >> n >> m){
    if(n == 0 and m == 0) break;
    edges.resize(m);
    int cost = 0;
    for(int i=0;i<m;i++){
      cin >> edges[i].u >> edges[i].v >> edges[i].w;
      cost += edges[i].w;
    }

    cout << cost - mst() << endl;
  }
  return 0;
}