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

ll dp[16][16][8][16][16][16];

int H, W, A, B;

//m1 current mask
//m2 last mask

ll solve(int i,int j, int a, int b, int m1, int m2){
  if(j > W)
    return 0;
    
  if(j == W)
    return solve(i+1, 0, a, b, 0, m1);

  if(i == H){
  // cout << i << " " << j <<" " << a << " " << b << " " << m1 << " " << m2 << endl;
    return (m2 == ((1 << H)-1)) and a == 0 and b == 0;
  } 

  ll& state = dp[i][j][a][b][m1][m2];
  if(state != -1)
    return state;

  state = 0;

  if(i == 0 or (m2 & (1 << j)) ){
    if(b > 0)
      state += solve(i, j + 1, a, b - 1, m1 | (1 << j), m2);
    if(a > 0 and j + 2 <= W){
      int new_mask = m1 | (1 << j);
      new_mask = new_mask | (1 << (j+1));
      state += solve(i, j + 2, a - 1, b,  new_mask , m2);
    }

    state += solve(i, j+1, a, b, m1, m2);

  }else{
    if(a > 0)
      state += solve(i, j + 1, a - 1, b, m1 | (1 << j), m2 | (1 << j));
  }


  return state;
}


int main(){
  fastio;

  cin >> H >> W >> A >> B;

  if(H > W)
    swap(H, W);

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, A, B, 0, 0) << endl;
  return 0;
}