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

const int nax = 1e5 + 5;
vi has_factor[nax];
int n;
int a[nax];
int dp[nax];
bool exists[nax];
int pos[nax];

int solve(int i){
  int& state = dp[i];
  if(state != -1) return state;

  int cur = a[i];
  int div = 2;

  while(1LL*div*div <= cur){
    bool has = false;
    while(cur % div == 0) 
      has = true, cur /= div;
    if(has){
      int j = ub(all(has_factor[div]), a[i]) - has_factor[div].begin();
      if(j < sz(has_factor[div]))
      state = max(state, 1 + solve(pos[has_factor[div][j]]));
    }
    div++;
  }

  if(cur > 1){
     int j = ub(all(has_factor[cur]), a[i]) - has_factor[cur].begin();
      if(j < sz(has_factor[cur]))
      state = max(state, 1 + solve(pos[has_factor[cur][j]]));
  }

  if(state == -1) state = 1;

  return state;
}

int main(){
  fastio;
  
  cin >> n;

  for(int i=0;i<n;i++) {
    cin >> a[i];
    exists[a[i]] = true;
    pos[a[i]] = i;
  }

  vector <bool> is_prime(nax, 1);
  for(int i=2;i<nax;i++)
    if(is_prime[i]){
      if(exists[i]) has_factor[i].pb(i);
      for(int j=2*i;j<nax;j+=i){
        if(exists[j]) has_factor[i].pb(j);
        is_prime[j] = false;
      }
    }


  memset(dp, -1, sizeof dp);

  int ans = 1;

  for(int i=0+(a[0]==1);i<n;i++){
    ans = max(ans, solve(i));
  }

  cout << ans << endl;
  return 0;
}