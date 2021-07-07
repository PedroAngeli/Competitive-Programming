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

const int nax = 1e3;
const int INF = 1e9 + 7;
int n,k;
vector <vi> dp;
vpii adj[20];

bool valid(int i,int j){
  return i >= 0 && i <nax && j>=0 && j<nax;
}

bool valid_2(int i,int j){
  return i >= 0 && i <n && j>=0 && j<n;
}

vector <vi> bfs_pre(pii& source){
  vector <vi> dist(nax, vi(nax, INF));
  dist[source.f][source.s] = 0;
  queue <pii> q;
  q.push(source);

  vpii mov = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
  while(!q.empty()){
    pii u = q.front();
    q.pop();

    for(auto p : mov){
      int x = u.f + p.f;
      int y = u.s + p.s;
      if(!valid(x,y)) continue;
      if(dist[x][y] > dist[u.f][u.s] + 1){
        q.push({x,y});
        dist[x][y] = dist[u.f][u.s] + 1;
      }
    }
  }

  return dist;
}

int bfs(pii source, pii dest){
  vector <vi> dist(nax, vi(nax, INF));
  dist[source.f][source.s] = 0;
  queue <pii> q;
  q.push(source);

  vpii mov = {{2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}};
  while(!q.empty()){
    pii u = q.front();
    q.pop();
    for(auto p : mov){
      int x = u.f + p.f;
      int y = u.s + p.s;
      if(!valid_2(x,y)) continue;
      if(dist[x][y] > dist[u.f][u.s] + 1){
        dist[x][y] = dist[u.f][u.s] + 1;
        if(x == dest.f && y == dest.s) break;
        q.push({x,y});
      }
    }
  }

  return dist[dest.f][dest.s];
}

int solve(int u,int mask,int source){
  if(u == source && mask == ((1 << k) - 1)) return 0;

  int& state = dp[u][mask];
  if(state != -1) return state;
  state = INF;

  for(auto p : adj[u]){
    int v = p.f;
    int w = p.s;

    if(((1 << v) & mask) == 0) state = min(state, w + solve(v, mask | (1 << v), source)); 
  }

  return state;
}

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 1;
  pii source = make_pair(0,0);
  vector <vi> dist = bfs_pre(source);
  
  while(t--){
    cin >> n >> k;
    cout << "Case " << ncase++ << ": ";
    vpii interesting;
    for(int i=0;i<20;i++) adj[i].clear();

    for(int i=0;i<k;i++){
      int x,y;
      cin >> x >> y;
      x--,y--;
      interesting.pb({x,y});
    }

    for(int i=0;i<k;i++)
      for(int j=0;j<i;j++){
        int dr = abs(interesting[i].f - interesting[j].f);
        int dc = abs(interesting[i].s - interesting[j].s);
        int w; 
        if(dr + dc < 20) w = bfs(interesting[i], interesting[j]);
        else w = dist[dr][dc];
        adj[i].pb({j,w});
        adj[j].pb({i,w});
      }

    dp.assign(k, vi((1 << k), -1) );
    int ans = solve(0, 0, 0);

    if(ans == INF) ans = 0;

    cout << ans << endl;
  }
  return 0;
}