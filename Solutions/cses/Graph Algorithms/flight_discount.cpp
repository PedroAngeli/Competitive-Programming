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
int n, m;
vpii adj[nax];
const ll inf = 1e18 + 7;

int main(){
  fastio;

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int a,b, c;
    cin >> a >> b >> c;
    adj[a].pb({b, c});
  }

  vector <vector <ll>> dist(n+1, vector <ll>(2, inf));
  //0 - not discount
  //1 - use discount

  set <pair <pair <ll,int>,int>> pq; //(dist, ver), 0 or 1
  dist[1][0] = 0;
  pq.insert({{0, 1}, 0});
  

  while(!pq.empty()){
    auto it = pq.begin();
    int u = it->f.s;
    ll d = it->f.f;
    int bit = it->s;
    pq.erase(it);
    
    if(d > dist[u][bit]) continue;

    for(auto el:adj[u]){
      int v = el.f;
      int w = el.s;
      if(dist[v][bit] > dist[u][bit] + w){
        dist[v][bit] = dist[u][bit] + w;
        pq.insert({{dist[v][bit], v}, bit});
      }

      if(bit == 0 and dist[v][1] > dist[u][bit] + (w/2)){
        dist[v][1] = dist[u][bit] + (w/2);
        pq.insert({{dist[v][1], v}, 1});
      }
    }
  }

  cout << min(dist[n][0], dist[n][1]) << endl;

  return 0;
}