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

const int nax = 505;

ll pascal[nax][nax];
const int mod = 1000007;

void generates_pascal(){
    for(int i=0;i<nax;i++)
      for(int j=0;j<nax;j++){
        if(j == 0 || j == i) pascal[i][j] = 1;
        else pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
        pascal[i][j] %= mod;
      }
  }

ll n_chooses_k(int n,int k){
    if(k > n) return 0;
    return pascal[n][k];
}

int main(){
  fastio;
  
  generates_pascal();

  int T;
  cin >> T;
  for(int tc=1;tc<=T;tc++){
    int n, m, k;
    cin >> n >> m >> k;

    ll ans = 0;

    for(int mask=1;mask<=15;mask++){
      int qtd = __builtin_popcount(mask);
      int lines = n;
      int cols = m;
      if(mask&1) lines--;
      if(mask&2) cols--;
      if(mask&4) lines--;
      if(mask&8) cols--;

      int cells = lines*cols;
      int mult = (qtd%2) ? 1 : -1;

      ans += (mult*n_chooses_k(cells, k));
      ans %= mod;
      if(ans < 0) ans += mod;
      
    }
    ans = (n_chooses_k(n*m, k) - ans)%mod;
    if(ans < 0) ans += mod;
    
    cout << "Case " << tc << ": " << ans << endl;
  }
    
  
  
  return 0;
}