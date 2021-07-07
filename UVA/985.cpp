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

const int nax = 500;
int R,C;
string new_state[26];
pii coord[26];
string grid[nax][nax];
const int INF = 1e9 + 7;

bool valid(int i,int j){
  return i >= 0 && i < R && j >=0 && j < C;
}

int solve(){
  int dist[R][C][4];
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      for(int k=0;k<4;k++)
        dist[i][j][k] = INF;
  dist[0][0][0] = 0;
  queue <pair <pii,pii> > pq;
  pq.push({{0,0},{0,0}});

  while(!pq.empty()){
    auto it = pq.front();
    auto p = it.s;
    int d = it.f.f;
    int rot = it.f.s;
    pq.pop();
    if(dist[p.f][p.s][rot] < d) continue;

    for(char c : grid[p.f][p.s]){
      c = new_state[c-'A'][rot];
      int x = p.f + coord[c-'A'].f;
      int y = p.s + coord[c-'A'].s;
      if(!valid(x,y)) continue;
      if(dist[x][y][(rot + 1)%4] > dist[p.f][p.s][rot] + 1){
        dist[x][y][(rot + 1)%4] = dist[p.f][p.s][rot] + 1;
        pq.push({{dist[x][y][(rot + 1)%4], (rot+1)%4},{x,y}});
      }
    }
  }

  int ret = INF;
  for(int i=0;i<4;i++) ret = min(ret, dist[R-1][C-1][i]);

  return ret;
}

int main(){
  fastio;
  new_state['N' - 'A'] = "NESW";
  coord['N' - 'A'] = make_pair(-1,0);

  new_state['E' - 'A'] = "ESWN";
  coord['E' - 'A'] = make_pair(0,1);

  new_state['S' - 'A'] = "SWNE";
  coord['S' - 'A'] = make_pair(1,0);

  new_state['W' - 'A'] = "WNES";
  coord['W' - 'A'] = make_pair(0,-1);

  while(cin >> R >> C){
    for(int i=0;i<R;i++)
      for(int j=0;j<C;j++){
        if(i == R-1 && j == C-1) break;
        cin >> grid[i][j];
      }

    int ans = solve();
    if(ans == INF) cout << "no path to exit" << endl;
    else cout << ans << endl;
  }

  return 0;
}