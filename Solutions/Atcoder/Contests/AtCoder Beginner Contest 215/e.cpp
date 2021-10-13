#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

const int mod = 998244353;
int n;
string s;
int dp[1000][1024][10];

bool already_participate(int mask, int contest){
  return mask & (1 << contest);
}

int solve(int i, int j, int k){
  if(i == n)
    return __builtin_popcount(j) > 0;
    
  int& state = dp[i][j][k];
  if(state != -1)
    return state;

  state = 0;
  int contest = s[i] - 'A';

  if(!already_participate(j, contest)){
    state += solve(i+1, j | (1 << contest), contest);
    state %= mod;
  }
  else if(k == contest){
      state += solve(i+1, j, k); 
      state %= mod;
  }
  

  state += solve(i+1, j, k);
  state %= mod;

  return state;
}

int main(){
  fastio;

  cin >> n >> s;
  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, 0) << endl;
  return 0;
}