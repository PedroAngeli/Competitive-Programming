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


int main(){
  fastio;

  int n;
  while(cin >> n and n){
    const int INF = 1e9 + 7;
    queue <pii> q;
    vector <vi> dist(2001, vi(2001, INF));
    for(int i=0;i<n;i++){
      int x, y;
      cin >> x >> y;
      q.push({x, y});
      dist[x][y] = 0;
    }
    int m;
    cin >> m;
    vpii s2(m);
    vector <vector <bool>> shop(2001, vector<bool>(2001, false));
    for(int i=0;i<m;i++){
      cin >> s2[i].f >> s2[i].s;
      if(i == 0) continue;
      int xi = s2[i-1].f;
      int xf = s2[i].f;
      int yi = s2[i-1].s;
      int yf = s2[i].s;
      if(xi > xf) swap(xi, xf);
      if(yi > yf) swap(yi, yf);
      if(xi == xf)
        while(yi <= yf) shop[xi][yi] = true, yi++;
      else
        while(xi <= xf) shop[xi][yi] = true, xi++;
    }

    int ans = 0;
    vpii mov = {{0,1}, {0,-1},{1,0},{-1,0}};
    while(!q.empty()){
      auto p = q.front();
      q.pop();
      if(shop[p.f][p.s]){
        ans = dist[p.f][p.s];
        break;
      }
      for(auto el:mov){
        int x = p.f + el.f;
        int y = p.s + el.s;
        if(x < 0 or y < 0 or x > 2000 or y > 2000) continue;
        if(dist[x][y] > dist[p.f][p.s] + 1){
          dist[x][y] = dist[p.f][p.s] + 1;
          q.push({x, y});
        }
      }
    }

    cout << ans << endl;
  }
  
  return 0;
}