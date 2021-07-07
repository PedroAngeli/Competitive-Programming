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

int n;
const int mod = 1e9 + 7;
int dp[501][125251];

int solve(int i,int sum){
  if(i == n+1) return sum == (((n+1)*n)/4);
  int& state = dp[i][sum];
  if(state != -1) return state;
  return state = (solve(i+1, sum) + solve(i+1, sum + i))%mod;
}

int main(){
  fastio;
  memset(dp, -1, sizeof dp);
  cin >> n;
  int pa = (n*(n+1))/2;
  if(pa%2){
    cout << 0 << endl;
    return 0;
  }
  int ans = solve(1, 0);
  ans = (1LL * ans * ((mod+1)/2))%mod;
  cout << ans << endl;

  return 0;
}