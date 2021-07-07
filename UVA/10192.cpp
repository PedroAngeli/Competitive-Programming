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

string s1, s2;
int dp[105][105];

int solve(int i,int j){
  int n = sz(s1), m = sz(s2);
  if(i == n || j == m) return 0;
  int& state = dp[i][j];
  if(state != -1) return state;
  
  if(s1[i] == s2[j]) state = 1 + solve(i+1,j+1);
  else state = max({solve(i+1, j), solve(i, j+1), solve(i+1,j+1)});

  return state;
}

int main(){
  fastio;

  int ncase = 1;
  while(true){
    getline(cin, s1);
    getline(cin, s2);
    if(s1 == "#") break;
    memset(dp, -1, sizeof dp);
    int ans = solve(0,0);
    cout << "Case #" << ncase++ << ": you can visit at most " << ans << " cities." << endl;
  }
  return 0;
}