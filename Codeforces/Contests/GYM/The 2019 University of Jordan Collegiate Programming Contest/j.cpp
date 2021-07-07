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

int n, k, m;
const int nax = 2e3 + 5;
ll dp[nax][nax];
const int mod = 1e9 + 7;

ll solve(int len,int sum){
  if(sum < 0 or len > m or sum > k) return 0;
  ll& state = dp[len][sum];
  if(state != -1) return state;
  int val = 0;
  if(len%2 == 0 and len and sum == 0) val = 1;
  return state = (val + solve(len + 1, sum - 1)+ solve(len + 1, sum + 1))%mod;
}

int main(){
  fastio;
  memset(dp,-1,sizeof dp);
  cin >> n >> k >> m;
  k = min(k, m);
  cout << 1LL*2*n*solve(0,0)%mod << endl;
  return 0;
}