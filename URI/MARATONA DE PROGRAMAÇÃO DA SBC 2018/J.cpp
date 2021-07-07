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

int n,k;
const int INF = 1e9 + 7;
vector <pair <ld, pii> > edges;
ld dp[5000][1 << 10];

int squared(int x){
  return x*x;
}

ld dist(pii p1, pii p2){
  return sqrt(squared(p1.f - p2.f) + squared(p1.s - p2.s));
}


ld solve(int i,int j){
    int len = sz(edges);
    if(i == len){
      if(j == (1 << k) - 1) return 0;
      return INF;
    }

  ld& state = dp[i][j];
  // if(state >= 0) return state;

  ld d = edges[i].f;
  int u = edges[i].s.f;
  int v = edges[i].s.s;

  state = solve(i+1,j);
  
  if(u >= k && v >= k)
    state = min(state, d + solve(i+1, j));
  else if(u >= k && v < k){
    if(((1 << v) & j) == 0) state = min(state, d + solve(i+1, j | (1 << v)));
  }else if(u < k && v >= k){
    if(((1 << u) & j) == 0) state = min(state, d + solve(i+1, j | (1 << u)));
  }

  return state;
}

int main(){
  fastio;

  cin >> n >> k;
  
  vpii cities(n);

  for(int i=0;i<n;i++){
    cin >> cities[i].f >> cities[i].s;
    for(int j=0;j<i;j++)
      edges.pb({dist(cities[i],cities[j]), {i,j}});
  }

  cout << solve(0,0) << endl;

  return 0;
}