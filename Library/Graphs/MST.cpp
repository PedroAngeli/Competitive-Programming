#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define all(c) (c).begin(), (c).end()
const int INF = 1e9 + 7;
struct UnionFind{
  vector <int> parent;
  vector <int> set_size;
  int V;
  UnionFind(int V):V(V){
    parent.resize(V+1);
    iota(all(parent),0);
    set_size.assign(V+1,1);
  }
  int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
  }
  bool join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(set_size[x] > set_size[y]) swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
    return true;
  }
};
struct Graph{
  vector <pair<int, pair <int,int>>> edges;
  vector <pair<int, pair <int,int>>> edges_in_mst;
  int V;
  Graph(int V): V(V){}
  void addEdge(int u,int v,int w){
    edges.push_back({w,{u,v}});
  }
  //Returns the cost of the MST. O(E LOG E)
  int kruskal(){ 
    sort(all(edges));
    UnionFind dsu(V);
    int cost = 0;
    for(auto e : edges){
      int w = e.f;
      int u = e.s.f;
      int v = e.s.s;
      if(dsu.find(u) == dsu.find(v)) continue;
      edges_in_mst.push_back({w,{u,v}});
      dsu.join(u,v);
      cost += w;
    }
    return cost;
  }
};