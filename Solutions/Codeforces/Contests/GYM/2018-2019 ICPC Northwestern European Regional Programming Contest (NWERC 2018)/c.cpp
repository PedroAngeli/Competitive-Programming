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

const int nax = 1e3 + 5;
vi adj[nax];
ld x[nax];
ld y[nax];

void solve(int u,int p,int o){
  int child = 0;
  for(int v:adj[u]){
    if(p != v)
      child++;
  }
  ld angle = 180.0/(child);
  ld cur_angle = 0;

  for(int v:adj[u]){
    if(p == v)
      continue;
    if(o == 0){
      x[v] = cosl(cur_angle) + x[u];
      y[v] = sinl(cur_angle) + y[u];
    }else{
      x[v] = sinl(cur_angle) + x[u];
      y[v] = cosl(cur_angle) + y[u];
    }
    
    cur_angle += angle; 
  }

  for(int v:adj[u]){
    if(p == v)
      continue;
    solve(v,u,1-o);
  }
}

int main(){
  fastio;

  int n;
  cin >> n;

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  solve(1,-1,0);
  
  cout << fixed << setprecision(9);

  for(int i=1;i<=n;i++)
    cout << x[i] << " " << y[i] << endl;

  return 0;
}