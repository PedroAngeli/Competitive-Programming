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

  int n,q;
  cin >> n >> q;
  
  UnionFind dsu(n);

  set <int> emp;
  for(int i=1;i<=n+1;i++) emp.insert(i);

  while(q--){
    int type, x, y;
    cin >> type >> x >> y;
    if(type == 1) dsu.join(x, y);
    else if(type == 2){
      int cur = x;
      while(*emp.lb(cur) < y){
        cur = *emp.lb(cur);
        emp.erase(cur);
        dsu.join(cur, cur + 1);
      }
    }else{
      if(dsu.find(x) == dsu.find(y)) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}