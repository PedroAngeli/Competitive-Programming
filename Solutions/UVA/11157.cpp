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

vi rocks;
vector <bool> is_big;
int n,d;
int dp[101][101][101];

int solve(int i, int lgo, int lback){
  if(i == n+1) return max(d - rocks[lgo], d - rocks[lback]);
  int& state = dp[i][lgo][lback];
  if(state != -1) return state;
  if(is_big[i]) return state = max({rocks[i] - rocks[lgo], rocks[i] - rocks[lback], solve(i+1, i, i)});
  return state = min(max(rocks[i] - rocks[lgo], solve(i+1, i, lback)), max(rocks[i] - rocks[lback], solve(i+1, lgo, i)));
}

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 1;
  while(t--){
    cout << "Case " << ncase++ << ": ";
    memset(dp, -1, sizeof dp);
    cin >> n >> d;
    is_big.resize(n+1);
    rocks.clear();
    rocks.pb(0);
    for(int i=1;i<=n;i++){
      char c, hifen;
      int x;
      cin >> c >> hifen >> x;
      is_big[i] = (c == 'B');
      rocks.pb(x);
    }
    cout << solve(1, 0, 0) << endl;
  }
  return 0;
}