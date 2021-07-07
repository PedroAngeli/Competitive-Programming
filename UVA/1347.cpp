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

ld dist[1000][1000];
ld dp[1000][1000];
int n;

ld squared(ld x){
  return x*x;
}

ld euc_dist(pii p1,pii p2){
  return sqrt(squared(p1.f - p2.f) + squared(p1.s - p2.s));
}

ld solve(int last_lr, int last_rl){
  int u = 1 + max(last_lr, last_rl); 
  if(u == n-1) return dist[last_lr][u] + dist[u][last_rl];
  ld& state = dp[last_lr][last_rl];
  if(state > -0.5) return state;
  return state = min(dist[u][last_lr] + solve(u, last_rl), dist[u][last_rl] + solve(last_lr, u));
}

int main(){
  fastio;

  while(cin >> n){
    memset(dp, -1, sizeof dp);
    vpii points(n);
    for(int i=0;i<n;i++){
      cin >> points[i].f >> points[i].s;
      for(int j=0;j<i;j++) dist[i][j] = dist[j][i] = euc_dist(points[i], points[j]);
    }

    cout << fixed << setprecision(2) << solve(0,0) << endl;
  }
  
  return 0;
}