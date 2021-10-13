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

struct Viz{
  ll v, t, k;
};


const int nax = 1e5 +5;
const ll INF = 1e18 + 5;
vector <Viz> adj[nax];
int n,m,x,y;

int main(){
  fastio;

  cin >> n >> m >> x >> y;

  for(int i=0;i<m;i++){
    ll a, b, t, k;
    cin >> a >> b >> t >> k;
    adj[a].pb({b, t, k});
    adj[b].pb({a, t, k});
  }

  vll dist(n+1, INF);
  dist[x] = 0;

  set <pair <ll, int> > pq;
  pq.insert({0, x});

  while(!pq.empty()){
    auto it = pq.begin();
    int u = it->s;
    pq.erase(it);

    for(auto [v, t , k] : adj[u]){
      ll sum = (k - (dist[u]%k))%k;

      if(dist[v] > dist[u] + sum + t){
        dist[v] = dist[u] + sum + t;
        pq.insert({dist[v], v});
      }
    }
  }

  ll ans = dist[y];
  if(ans >= INF) ans = -1;

  cout << ans << endl;
  return 0;
}