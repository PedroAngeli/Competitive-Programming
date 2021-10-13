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

ld dp[105][10005];
int n;
vi a;
ll r;
ld b,v,e,F;
ld T[10005];

ld solve(int i,int j){
  if(i == n) return T[j-1];

  ld& state = dp[i][j];
  if(state > -0.5) return state;

  return state = min(solve(i+1, j + a[i+1] - a[i]), b + T[j-1] + solve(i+1, a[i+1] - a[i]));
}

int main(){
  fastio;
  
  while(cin >> n and n){
      a.resize(n+1);
      a[0] = 0;
      for(int i=1;i<=n;i++) cin >> a[i];

      cin >> b >> r >> v >> e >> F;

      for(ll i=0;i<=10000;i++){
        if(i >= r) T[i] = (1.0 / (v - e * (i - r)));
        else T[i] = (1.0 / (v - F * (r - i)));
        if(i > 0) T[i] += T[i-1];
    }

    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(4) << solve(0,0) << endl;
  }
  return 0;
}