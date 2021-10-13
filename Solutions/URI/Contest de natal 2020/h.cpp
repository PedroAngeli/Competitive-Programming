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

int dist[10][10];
vs grid;
const int INF = 1e9 + 7;
int dp[(1 << 10)];
int n, p;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool valid(int i,int j){
  return i>=0 and i<n and j>=0 and j < n and grid[i][j] != '#';
}

int solve(int mask){
  if(mask == ((1 << p)-1)) return 0;
  int j = __builtin_popcount(mask);
  int& state = dp[mask];
  if(state != -1) return state;

  state = INF;
  for(int i=0;i<p;i++){
    if(mask & (1 << i)) continue;
    state = min(state, max(dist[i][j], solve(mask | (1 << i))));
  }

  return state;
}

vector <vi> bfs(pii source){
  vector <vi> d(n, vi(n, INF));
  d[source.f][source.s] = 0;
  queue <pii> q;
  q.push(source);

  while(!q.empty()){
    auto el = q.front();
    q.pop();
    for(int k=0;k<4;k++){
      int x = el.f + dx[k];
      int y = el.s + dy[k];
      if(!valid(x, y)) continue;
      if(d[x][y] > d[el.f][el.s] + 1){
          d[x][y] = d[el.f][el.s] + 1;
          q.push({x, y});
      }
    }
  }

  return d;
}

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    cin >> n >> p;
    grid.resize(n);
    vpii portal_coord;
    vpii player_coord;

    for(int i=0;i<n;i++){
      cin >> grid[i];
      for(int j=0;j<n;j++){
        char c = grid[i][j];
        if(c == 'G') player_coord.pb({i, j});
        if(c == 'X') portal_coord.pb({i, j});
      }
    }

    for(int i=0;i<p;i++){
      vector <vi> d = bfs(player_coord[i]);
      for(int j=0;j<p;j++){
        int x = portal_coord[j].f;
        int y = portal_coord[j].s;
        dist[i][j] = d[x][y];
      }
    }
    memset(dp, -1, sizeof dp);
    int ans = solve(0);
    if(ans == INF) ans = -1;
    cout << ans << endl;
  }
  
  return 0;
}