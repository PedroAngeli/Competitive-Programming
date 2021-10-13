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
const int nax = 3005;
const int mod = 998244353;
int n;
vector <int> a, b;
int dp[nax][nax];
int pref[nax][nax];

int sum_range(int i, int l, int r){
  if(l == 0)
    return pref[i][r];
  return pref[i][r] - pref[i][l-1];
}

int sum_mod(int a, int b){
  int sum = a + b;
  sum %= mod;
  sum += mod;
  sum %= mod;
  return sum;
}

int main(){
  fastio;

  cin >> n;
  a.resize(n+1);
  b.resize(n+1);
  for(int i=1;i<=n;i++)
    cin >> a[i];
  for(int i=1;i<=n;i++)
    cin >> b[i];

  for(int j=a[1];j<=b[1];j++){
    int i = 1;
    dp[i][j] = 1;
    pref[i][j] = dp[i][j];
      if(j > 0)
        pref[i][j] = sum_mod(pref[i][j], pref[i][j-1]);
  }

  for(int i=1, j=b[i]+1;j<nax;j++)
      pref[i][j] = sum_mod(pref[i][j], pref[i][j-1]);

  for(int i=2;i<=n;i++){
    for(int j=a[i];j<=b[i];j++){
      dp[i][j] = sum_mod(dp[i][j], sum_range(i-1, a[i-1], j));
      pref[i][j] = dp[i][j];
      if(j > 0)
        pref[i][j] = sum_mod(pref[i][j], pref[i][j-1]);
    }
    for(int j=b[i]+1;j<nax;j++)
      pref[i][j] = sum_mod(pref[i][j], pref[i][j-1]);
      // for(int k=a[i-1];k<=j;k++){
      //   dp[i][j] += dp[i-1][k];
      //   dp[i][j] %= mod;
      // }
  }

  int ans = 0;

  for(int i=a[n];i<=b[n];i++){
    ans += dp[n][i];
    ans %= mod;
  }

  cout << ans << endl;
  return 0;
}