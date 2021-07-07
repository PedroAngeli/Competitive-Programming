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

const int nax = 1e5 + 5;
vi adj[nax];
bool vis[nax];
bool rec_stack[nax];
int n, m;

bool dfs(int u, vi&path){
  vis[u] = true;
  rec_stack[u] = true;
  path.pb(u);

  for(int v:adj[u]){
    if(!vis[v] and dfs(v, path)) 
      return true;
    else if(rec_stack[v]){
      vi ans = {v};
      while(path.back() != v){
        ans.pb(path.back());
        path.pop_back();
      }
      ans.pb(v);
      reverse(all(ans));
      cout << sz(ans) << endl;
      for(int x:ans)
        cout << x << " ";
      cout << endl;
      return true;
    }
  }
  path.pop_back();
  rec_stack[u] = false;
  return false;
}

int main(){
  fastio;

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
  }

  bool cycle = false;

  for(int i=1;i<=n;i++){
    vi path;
    if(!vis[i])
      cycle = cycle or dfs(i, path);
  }

  if(!cycle)
    return cout << "IMPOSSIBLE" << endl, 0;

    
  return 0;
}