#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(), (c).end()
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
