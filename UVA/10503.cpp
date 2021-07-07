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

int n,m;
pii L, R;
vpii pieces;
int dp[(1 << 14)][7];

int solve(int i,int j){
  int cnt = __builtin_popcount(i);
  if(cnt == n-1){
    for(int k=0;k<m;k++){
      if((1 << k) & i) continue;
      if(pieces[k].f == j && R.f == pieces[k].s) return 1;
      if(pieces[k].s == j && R.f == pieces[k].f) return 1;
    }
    return 0;
  }
  int& state = dp[i][j];
  if(state != -1) return state;
  state = 0;

  for(int k=0;k<m;k++){
      if((1 << k) & i) continue;
    if(pieces[k].f == j) state = (state or solve(i | (1 << k), pieces[k].s));
    if(pieces[k].s == j) state = (state or solve(i | (1 << k), pieces[k].f));
  }

  return state;  
}

int main(){
  fastio;

  while(cin >> n and n){
    cin >> m;
    cin >> L.f >> L.s;
    cin >> R.f >> R.s;
    pieces.resize(m);
    for(int i=0;i<m;i++) cin >> pieces[i].f >> pieces[i].s;
    memset(dp, -1, sizeof dp);
    int can = solve(0, L.s);
    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}