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

vs grid;
int h, w;
pii source, dest;
vpii pos[26];
const int INF = 1e9 + 7;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector <vi> dist;

bool valid(int i,int j){
  return i>=0 and i<h and j>=0 and j<w and grid[i][j] != '#';
}

void bfs(){
  dist.assign(h, vi(w, INF)); 
  dist[source.f][source.s] = 0;
  queue <pii> q;
  q.push(source);
  
  while(!q.empty()){
    auto p = q.front();
    q.pop();

    if(grid[p.f][p.s] >= 'a' and grid[p.f][p.s] <= 'z'){
      for(auto x: pos[grid[p.f][p.s] - 'a'])
        if(dist[x.f][x.s] > dist[p.f][p.s] + 1){
          dist[x.f][x.s] = dist[p.f][p.s] + 1;
          q.push(x);
        }
      pos[grid[p.f][p.s] - 'a'].clear();
    }

    for(int i=0;i<4;i++){
      int x = p.f + dx[i];
      int y = p.s + dy[i];
      if(!valid(x, y)) continue;
      if(dist[x][y] > dist[p.f][p.s] + 1){
        dist[x][y] = dist[p.f][p.s] + 1;
        q.push({x, y});
      }
    }
  }
}

int main(){
  fastio;

  cin >> h >> w;

  grid.resize(h);

  for(int i=0;i<h;i++){
    cin >> grid[i];
    for(int j=0;j<w;j++){
      if(grid[i][j] == 'S') source = {i,j};
      else if(grid[i][j] == 'G') dest = {i, j};
      else if(grid[i][j] != '#' and grid[i][j] != '.') pos[grid[i][j] - 'a'].pb({i, j});
    }
  }

  bfs();

  int ans = dist[dest.f][dest.s];

  if(ans == INF) ans =-1;
  cout << ans << endl;

  return 0;
}