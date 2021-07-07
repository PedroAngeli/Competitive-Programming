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

const int nax = 4e5 + 5;
vi adj[nax];
vi topo;
int in_degree[nax];
int vis[nax];
int e[nax];
int n;

void solve(){
  priority_queue <pii, vector <pii>, greater<pii> > pq;
  for(int i=1;i<=n;i++)
    if(in_degree[i] == 0)
      pq.push({e[i],i});

  while(!pq.empty()){
    auto p = pq.top();
    pq.pop();
    int u = p.s;
    topo.pb(u);
    for(int v:adj[u]){
      in_degree[v]--;
      if(in_degree[v] == 0){
        pq.push({e[v],v});
      }
    }
  }
}

int main(){
  fastio;

  cin >> n;

  for(int i=1;i<=n;i++){
    cin >> e[i];
    int d;
    cin >> d;
    while(d--){
      int u;
      cin >> u;
      adj[i].pb(u);
      in_degree[u]++;
    }
  }

  solve();

  int ans = 0;
  reverse(all(topo));

  for(int i=0;i<n;i++)
    ans = max(ans, e[topo[i]] + i);

  cout << ans << endl;

  return 0;
}