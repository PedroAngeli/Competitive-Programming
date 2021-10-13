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
int c[nax], deleted[nax];
vi ans;

void solve(int u){
  int not_respect_child = 0, child = 0;
  for(int v:adj[u]){
    solve(v);
    child++;
    not_respect_child += c[v];
  }
  if(not_respect_child == child and c[u]) deleted[u] = 1;
}

void find_ans(int u){
  if(deleted[u]) ans.pb(u);
  for(int v:adj[u])
    find_ans(v);
}

int main(){
  fastio;

  int n;
  cin >> n;
  int root = 1;
  for(int i=1;i<=n;i++){
    int p;
    cin >> p >> c[i];
    if(p == -1) root = i;
    else adj[p].pb(i);
  }

  solve(root);
  find_ans(root);

  if(sz(ans) == 0) cout << -1;
  
  sort(all(ans));
  for(int x:ans) cout << x << " ";

  cout << endl;
  return 0;
}