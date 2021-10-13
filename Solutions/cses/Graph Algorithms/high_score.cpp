#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 2505;
const ll INF = 1e18;
vpii adj[nax];
vi reverse_adj[nax];
int n,m;
vector <bool> vis;

bool findCycle(int u){
  vis[u] = true;
  if(u == 1)
    return true;
  for(int v:reverse_adj[u])
    if(!vis[v]){
      if(findCycle(v))
        return true;
    }
  vis[u] = false;
  return false;
}
int main(){
  fastio;

  cin >> n >> m;

  while(m--){
    int u,v,p;
    cin >> u >> v >> p;
    adj[u].pb({v,p});
    reverse_adj[v].pb(u);
  }

  vll dist(n+1,-INF);
  dist[1] = 0; 
  vector <bool> change(n+1,false);
  
  for(int i=1;i<=n+1;i++)
    for(int u=1;u<=n;u++)
      for(auto p:adj[u]){
        int v = p.f;
        int w = p.s;
        if(dist[v] < dist[u] + w){
          if(i >= n)
            change[v] = true;
          dist[v] = dist[u] + w;
        }
      }
  
  vis.assign(n+1,false);

  findCycle(n);

  for(int i=1;i<=n;i++){
    if(change[i] && vis[i]){
      cout << -1 << endl;
      return 0;
    }
  }
    

  cout << dist[n] << endl;

  return 0;
}