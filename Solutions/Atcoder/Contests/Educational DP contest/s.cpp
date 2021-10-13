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

ll dp[10005][101];
string K;
int D, n;
const int mod = 1e9 + 7;

ll solve(int i,int j, int x){
  if(i == n) return (j == 0);

  ll& state = dp[i][j];
  if(state != -1 and i != x) return state;
  state = 0;

  int mx = (i == x) ? (K[i]-'0') : 10;

  for(int k=0;k<mx;k++){
    state += (solve(i+1, (k + j)%D, x));
    state %= mod;
  }

  return state;
}

int main(){
  fastio;

  memset(dp, -1, sizeof dp);
  cin >> K >> D;
  n = sz(K);

  ll ans = 0;

  int sum = 0;

  for(int i=0;i<n;i++){
    ans += solve(i, sum%D, i);
    ans %= mod;
    sum += (K[i]-'0');
  }

  ans += (sum%D == 0);
  ans--;
  ans = (ans + mod)%mod;  


  cout << ans << endl;

  return 0;
}