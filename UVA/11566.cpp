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

ll dp[105][1200][25];
vi favour;
vi cost;
const ll INF = 1e9 + 7;
ll k;

ll solve(int i, int amount, int n_el){
  if(amount < 0 || n_el < 0) return -INF; 
  if(i == k || n_el == 0) return 0;
  ll& state = dp[i][amount][n_el];
  if(state != -1) return state;

  return state = max({solve(i+1,amount,n_el), favour[i] + solve(i+1,amount - cost[i], n_el - 1), 2*favour[i] + solve(i+1, amount - 2*cost[i], n_el - 2)});
}

int main(){
  fastio;

  int n,x,T;
  
  while(cin >> n >> x >> T >> k){
    cout << fixed << setprecision(2);
    if(!n and !x and !T and !k) break;
    memset(dp, -1,sizeof dp);
    favour.resize(k);
    cost.resize(k);
    int t = (n+1)*T;
    int budget = floor(double(x * (n + 1)) / 1.1 + 1e-6);
    int total = budget - t;
    for(int i=0;i<k;i++){
      cin >> cost[i];
      int sum = 0;
      for(int j=0;j<=n;j++){
        int x;
        cin >> x;
        sum += x;
      }
      favour[i] = sum;   
    }

    ll ret = solve(0, total, 2 * (n+1));
    ld ans = ret < 0 ? 0 : (ld)ret / (n + 1);
    cout << ans << endl;
  }
  return 0;
}