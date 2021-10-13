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

ld dp[100][100][100];

ld solve(int a,int b,int c){
  if(a >= 100 or b >= 100 or c >= 100) return 0;

  ld& state = dp[a][b][c];
  if(state > -0.5) return state;

  ld pa = (ld)a/(a+b+c);
  ld pb = (ld)b/(a+b+c);
  ld pc = (ld)c/(a+b+c);
  return state = 1 + (pa*solve(a+1, b, c) + pb*solve(a, b+1, c) + pc*solve(a, b, c+1));
}

int main(){
  fastio;

  int a,b,c;
  cin >> a >> b >> c;

  memset(dp, -1,sizeof dp);
  cout << fixed << setprecision(10) << solve(a, b, c) << endl;

  
  return 0;
}