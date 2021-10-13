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
  bool can_join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return false;
    return true;
  }
  void join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return;
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
  }
};

int main(){
  fastio;

  int n, m1, m2;
  cin >> n >> m1 >> m2;

  UnionFind dsu1(n), dsu2(n);
  for(int i=0;i<m1;i++){
    int u, v;
    cin >> u >> v;
    dsu1.join(u, v);
  }
  for(int i=0;i<m2;i++){
    int u, v;
    cin >> u >> v;
    dsu2.join(u, v);
  }

  vector <pair <int,int> > ans;

  for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
      if(dsu1.can_join(i, j) and dsu2.can_join(i, j)){
        ans.push_back({i, j});
        dsu1.join(i, j);
        dsu2.join(i, j);
      }

  cout << ans.size() << endl;
  for(auto p:ans)
    cout << p.f << " " << p.s << endl;

  return 0;
}