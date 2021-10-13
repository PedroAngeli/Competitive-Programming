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

int n, m, k;
const int nax = 1e5 + 5;
const ll INF = 1e18 + 7;
vpii adj[nax];

int main(){
  fastio;

  cin >> n >> m >> k;

  for(int i=0;i<m;i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    adj[a].pb({b, c});
  }

  vector <vll> dist(n);

  for(int i=0;i<k;i++)
    dist[0].pb(0);

  for(int i=1;i<n;i++)
    for(int j=0;j<k;j++)
      dist[i].pb(INF);
  
  multiset <pair <ll, int>> pq;
  pq.insert({0, 0});

  while(!pq.empty()){
    auto it = pq.begin();
    int u = it->s;
    ll d = it->f;
    pq.erase(it);
    
    for(auto [v, w]:adj[u]){
      bool rem = dist[v].back() > w + d;    
      if(rem){
        dist[v].pop_back();
        dist[v].pb(d+w);
        sort(all(dist[v]));
        pq.insert({d+w, v});
      }
    }
  }

    for(ll x:dist[n-1])
    cout << x << " ";
  cout << endl;
  
  
  
  return 0;
}