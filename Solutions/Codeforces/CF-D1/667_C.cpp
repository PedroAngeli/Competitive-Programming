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
 
string a;
set <string> S;
const int nax = 1e4 + 5;
int n;
int dp[nax][2][2];

int solve(int i,int j,int k){
  if(i > n)
    return 0;

  if(i == n)
    return 1;
  
  int& state = dp[i][j][k];
  if(state != -1)
    return state;

  if(i > 6 && k == j && a.substr(i - (k + 2),k + 2) == a.substr(i,j + 2))
    return state = 0;
  
  state = solve(i + j + 2, j, j) || solve(i + j + 2, 1 - j , j);

  if(state)
    S.insert(a.substr(i,j+2));

  return state;
}
 
int main(){
  fastio;
 
  cin >> a;
  n = sz(a);

  memset(dp,-1,sizeof dp);

  for(int i=5;i<=n-2;i++)
    for(int j=0;j<2;j++)
      for(int k=0;k<2;k++)
        solve(i,j,k);
  
 
  cout << sz(S) << endl;
  for(string a : S)
    cout << a << endl;
 
  return 0;
}