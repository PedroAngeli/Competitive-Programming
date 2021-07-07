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
int n;
vi adj[nax];
int sub_sz[nax];
ll ans[nax], sub_ans[nax], pa[nax];

void dfs(int u,int p=-1){
  sub_sz[u] = 1;
  for(int v:adj[u])
    if(v != p){
      dfs(v, u);
      sub_sz[u] += sub_sz[v];
      sub_ans[u] += (sub_sz[v] + sub_ans[v]);
    }
}

void dfs2(int u, int p=-1){
  if(p == -1) ans[u] = sub_ans[u];
  else{
    pa[u] = ans[p] - (sub_ans[u] + sub_sz[u]);
    ans[u] = (n - sub_sz[u]) + pa[u] + sub_ans[u];
  }
  for(int v:adj[u])
    if(v != p)
      dfs2(v, u);
}

int main(){
  fastio;

  cin >> n;
  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1);
  dfs2(1);

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}