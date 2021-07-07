#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
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

const int nax = 1e4 + 5;
vpii adj[nax][2];
int n,m,s,t,p;
const ll INF = 1e18;

void solve(int source, vll& dist,int op){
  set <pii> pq;
  dist[source] = 0;
  pq.insert({0,source});

  while(!pq.empty()){
    auto fr = pq.begin();
    int u = fr->s;
    int d = fr->f;
    pq.erase(fr);

    if(dist[u] > d)
      continue;

    for(auto el : adj[u][op]){
      int w = el.s;
      int v = el.f;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.insert({dist[v],v});
      }
    }
  }
}

int main(){
  fastio;

  int T;
  cin >> T;
  while(T--){
    cin >> n >> m >> s >> t >> p;

    for(int i=1;i<=n;i++){
      adj[i][0].clear();
      adj[i][1].clear();
    }

    vector <pair <pii,int> > edges;

    for(int i=0;i<m;i++){
      int u,v,c;
      cin>> u >> v >> c;
      adj[u][0].pb({v,c});
      adj[v][1].pb({u,c});
      edges.pb({{u,v},c});
    }

    vll d1(n+1,INF),d2(n+1,INF);

    solve(s,d1,0);
    solve(t,d2,1);

    ll ans = -1;

    for(auto e:edges){
      ll w = e.s;
      int u = e.f.f;
      int v = e.f.s;
      if(d1[u] + w + d2[v] <= p)
        ans = max(ans,w);
    }

    cout << ans << endl;
  }


  return 0;
}