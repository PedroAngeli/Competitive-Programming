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
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

vi parent;
vi min_el;
vi max_el;
vi set_size;

int find(int x){
  return parent[x] = (x == parent[x] ? x : find(parent[x]));
}

void join(int x,int y){
  x = find(x);
  y = find(y);

  if(x == y)
    return;

  if(set_size[x] > set_size[y]){
    parent[x] = y;
    set_size[y] += set_size[x];
    min_el[y] = min(min_el[y], min_el[x]);
    max_el[y] = max(max_el[y], max_el[x]);
  }else{
    parent[y] = x;
    set_size[x] += set_size[y];
    min_el[x] = min(min_el[x], min_el[y]);
    max_el[x] = max(max_el[x], max_el[y]);
  }
}

int main(){
  fastio;

  int n,m;
  cin >> n >> m;
  parent.resize(n+1);
  min_el.resize(n+1);
  max_el.resize(n+1);
  set_size.assign(n+1,1);
  iota(all(parent),0);
  iota(all(min_el),0);
  iota(all(max_el),0);

  while(m--){
    string op;
    int u,v;
    cin >> op;
    if(op == "union"){
      int u,v;
      cin >> u >> v;
      join(u,v);
    }
    else{
      int u;
      cin >> u;
      u = find(u);
      cout << min_el[u] << " " << max_el[u] << " " << set_size[u] << endl;
    }
  }

  return 0;
}