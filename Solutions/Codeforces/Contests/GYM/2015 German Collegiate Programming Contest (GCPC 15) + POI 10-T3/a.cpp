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

const int nax = 2e4 + 5;
const int INF = 1e9 + 7;
int N,P,M,G,T;
int total_visit;
vi sites;
vpii adj[nax];
vpii red_adj[20];
vector <vi> dist;
vector <vi> dp;

void solve(vi& dist,int source){
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
      }
    }
  }
}

int solve2(int u,int mask){
  if(mask == (1 << (P+1)) - 1){
    return dist[u][0];
  }

  int& state = dp[u][mask];
  if(state != -1)
    return state;
  
  state = INF;
  for(auto p:red_adj[u]){
    int w = p.second;
    int v = p.first;
    if(mask & (1 << v))
      continue;
    state = min(state,w + solve2(v, mask | (1 << v)));
  }

  return state;
}

int main(){
  fastio;


  cin >> N >> P >> M >> G >> T;
  sites.resize(P);
  dist.assign(P+1, vi(N,INF));

  for(int i=0;i<P;i++){
    int w;
    cin >> sites[i] >> w;
    total_visit += w;
  }

  sites[P] = 0;

  for(int i=0;i<M;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].pb({v,w});
    adj[v].pb({u,w});
  }

  for(int i=0;i<=P;i++){
    solve(dist[i],sites[i]);
  }

  for(int i=0;i<=P;i++){
    int u = sites[i];
    for(int j=i+1;j<=P;j++){
      int v = sites[j];
      red_adj[i].pb({j,dist[i][v]});
      red_adj[j].pb({i,dist[j][u]});
    }
  }

  

  dp.assign(P+1,vi((1 << (P+1)),-1));
  int ans = solve2(P,(1 << P));
  if(ans + total_visit <= G){
    cout << "possible without taxi" << endl;
    return 0;
  }

  for(int i=0;i<=P;i++){
    for(int j=0;j<sz(red_adj[i]);j++){
      if(red_adj[i][j].s <= T)
        continue;
      int tmp = red_adj[i][j].s;
      red_adj[i][j].s = T;
      dp.assign(P+1,vi((1 << (P+1)),-1));
      int a = solve2(P,(1 << P));
      red_adj[i][j].s = tmp;
      if(a + total_visit <= G){
        cout << "possible with taxi" << endl;
        return 0;
      }
    }
  }

  cout << "impossible" << endl;
  return 0;
}