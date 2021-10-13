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
int av[nax], sv[nax];
vi adj[nax];
bool possible;
const int INF = 1e9 + 7;

void solve(int u=1,int h=1,int sum_path=0){
  if(h%2){
    if(sum_path > sv[u]) possible = false;
    else av[u] = sv[u] - sum_path;
  }else{
    av[u] = INF;
    for(int v:adj[u])
      av[u] = min(av[u], sv[v] - sum_path);
    if(av[u] < 0) possible = false;
    if(av[u] == INF) av[u] = 0;
  }

  for(int v:adj[u])
    solve(v, h+1, sum_path+av[u]);

}

int main(){
  fastio;

  int n;
  cin >> n;

  for(int i=2;i<=n;i++){
    int p;
    cin >> p;
    adj[p].pb(i);
  }

  for(int i=1;i<=n;i++) cin >> sv[i];
  
  possible = true;
  solve();

  if(!possible) cout << -1 << endl;
  else{
    ll ans = 0;
    for(int i=1;i<=n;i++) ans += av[i];
    cout << ans << endl;
  }

  return 0;
}