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

const int nax = 2e5 + 5;
vi adj[nax];
int n, m;
int a[nax];
int mx[nax];
int degree[nax];
const int INF = 1e9 + 7;

int main(){
  fastio;

  cin >> n >> m;

  for(int i=0;i<n;i++){
    cin >> a[i];
    mx[i] = -INF;
  }

  for(int i=0;i<m;i++){
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[v].pb(u);
    degree[u]++;
  }

  queue <int> q;
  for(int i=0;i<n;i++)
    if(degree[i] == 0)
      q.push(i);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v:adj[u]){
      degree[v]--;
      mx[v] = max({mx[v], a[u], mx[u]});
      if(degree[v] == 0) q.push(v);
    }
  }

  int ans = -INF;

  for(int i=0;i<n;i++)
    ans = max(ans, mx[i] - a[i]);
  
  cout << ans << endl;
  return 0;
}