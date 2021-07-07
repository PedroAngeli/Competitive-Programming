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

const int nax = 1e5 + 5;
vpll adj[nax];
ll INF = 1e18;

int main(){
  fastio;
  
  int n,m;
  cin >> n >> m;
  vll dist(n+1,INF);

  for(int i=0;i<m;i++){
    int u,v,c;
    cin >> u >> v >> c;
    adj[u].pb({c,v});
  }

  for(int i=1;i<=n;i++)
    sort(all(adj[i]));
  
  dist[1] = 0;
  priority_queue <pll,vpll,greater<pll> > pq;
  pq.push({0,1});

  while(!pq.empty()){
    auto t = pq.top();
    pq.pop();
    int u = t.s;
    ll d = t.f;
    if(d > dist[u])
      continue;

    for(auto p : adj[u]){
      int v = p.s;
      ll w = p.f;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.push({dist[v],v});
      }
    }
  }


  for(int i=1;i<=n;i++)
    cout << dist[i] << " ";
  cout << endl;
  return 0;
}