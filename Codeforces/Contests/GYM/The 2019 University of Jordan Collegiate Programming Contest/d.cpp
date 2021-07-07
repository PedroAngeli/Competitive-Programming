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

int grid[12][12] = 
{{1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,2,1,1,1,1,1,1,2,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,0,0,1,1,1,1,1},
{1,1,1,1,1,0,0,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,1,1,1,1,1,1,0,0,1},
{1,0,2,1,1,1,1,1,1,2,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,1,1,1,1,1,1,1,1,1},};

int dx[4] = {1, 0,-1, 0};
int dy[4] = {0, 1, 0, -1};

bool valid(int i,int j){
  return i >= 0 and j >= 0 and i < 12 and j < 12 and grid[i][j];
}

int main(){
  fastio;

  int L;
  cin >> L;

  while(L--){
    int r, c;
    cin >> r >> c;
    r--, c--;
    queue <pii> q;
    q.push({r, c});
    vector <vi> vis(12, vi(12, 0));
    vector <vpii> parent(12, vpii(12, {-1, -1}));
    vis[r][c] = 1;  

    while(!q.empty()){
      auto p = q.front();
      q.pop();
      for(int k=0;k<4;k++){
        int i = p.f + dx[k];
        int j = p.s + dy[k];
        if(!valid(i, j) or vis[i][j]) continue;
        vis[i][j] = 1;
        parent[i][j] = p;
        q.push({i, j});
      }
    }

    string ans = "";

    int i = 2;
    int j = 2;
    while(true){
      if(i == r and j == c) break;
      auto p = parent[i][j];
      if(p.f > i) ans += "U";
      if(p.f < i) ans += "D";
      if(p.s < j) ans += "R";
      if(p.s > j) ans += "L";
      i = p.f;
      j = p.s;

    }
    reverse(all(ans));
    cout << sz(ans) << endl << ans << endl;
  }

  
  return 0;
}