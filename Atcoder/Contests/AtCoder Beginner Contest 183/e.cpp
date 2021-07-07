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

const int mod = 1e9 + 7;
const int nax = 2000;
int dp[nax][nax];
int Left[nax][nax];
int up[nax][nax];
int diag[nax][nax];

int h, w;

void add_self(int& a,int b){
  a += b;
  if(a > mod)
    a -= mod;
}

int main(){
  fastio;

  cin >> h >> w;

  vs grid(h);
  for(int i=0;i<h;i++) cin >> grid[i];

  dp[0][0] = 1;

  for(int i=0;i<h;i++)
    for(int j=0;j<w;j++){
      if(grid[i][j] == '#') continue;
      int& state = dp[i][j];
      if(i-1 >= 0) add_self(state, up[i-1][j]), up[i][j] = up[i-1][j];
      if(j-1 >= 0) add_self(state, Left[i][j-1]), Left[i][j] = Left[i][j-1];
      if(i-1 >=0 and j-1 >= 0) add_self(state, diag[i-1][j-1]), diag[i][j] = diag[i-1][j-1];
      add_self(up[i][j], state);
      add_self(Left[i][j], state);
      add_self(diag[i][j], state);
    }
  
  cout << dp[h-1][w-1] << endl;
  return 0;
}