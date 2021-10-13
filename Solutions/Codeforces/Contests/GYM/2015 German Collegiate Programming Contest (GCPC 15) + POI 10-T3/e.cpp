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

const int nax = 1e4 + 5;
const int INF = 1e9 + 7;
vpii adj[nax];
  int n,m,k;

bool solve(int source){
  vi dist(n+1,INF);
  vi paths(n+1,0);
  paths[1] = 1;
  dist[source] = 0;
  set <pii> pq;
  pq.insert({0,source});

  while(!pq.empty()){
    auto it = pq.begin();
    int u = it->second;
    int d = it->first;
    pq.erase(it);

    if(dist[u] < d)
      continue;

    for(auto p : adj[u]){
      int w = p.second;
      int v = p.first;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        pq.insert({dist[v],v});
        paths[v] = paths[u];
      }else if(dist[v] == dist[u] + w){
        paths[v] += paths[u];
        paths[v] = min(2, paths[v]);
      }
    }
  }
  return paths[n] > 1;
}

int main(){
  fastio;

  cin >>n >> m >> k;
  int x;
  for(int i=0;i<k;i++)
    cin >> x;

  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }

  if(solve(1))
    cout << "yes" << endl;
  else
    cout << "no" << endl; 

  
  return 0;
}