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

const int nax = 301;
const int INF = 1e9 + 7;
int n;
int a[nax], b[nax];
int dp[nax][nax][nax];

int solve(int i, int j, int k){
  if(j == 0 and k == 0)
    return 0;
  if(i == n)
    return INF;
  int& state = dp[i][j][k];
  if(state != -1)
    return state;
  return state = min(solve(i+1, j, k), 
  1 + solve(i+1, max(0, j-a[i]), max(0, k-b[i])));
}

int main(){
  fastio;

  cin >> n;
  int x, y;
  cin >> x >> y;

  for(int i=0;i<n;i++)
    cin >> a[i] >> b[i];

  memset(dp, -1, sizeof dp);
  int ans = solve(0, x, y);
  
  if(ans == INF)
    ans = -1;

  cout << ans << endl;
  return 0;
}