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

int mat[18][18];

int main(){
  fastio;

  int n, m;
  cin >> n >> m;
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    u--,v--;
    mat[u][v] = mat[v][u] = 1;
  }

  vector <bool> is_clique((1 << n), false);

  for(int mask=1;mask<(1 << n);mask++){
    vi b;
    for(int j=0;j<n;j++)
      if(mask & (1 << j)) b.pb(j);

    bool clique = true;
    for(int i=0;i<sz(b);i++)
      for(int j=i+1;j<sz(b);j++)
        if(mat[b[i]][b[j]] == 0) clique = false;
    is_clique[mask] = clique;
  }

  vi dp((1<<n), n+1);
  dp[0] = 0;
  for(int mask=1;mask<(1 << n);mask++){
    for(int sub=mask;sub;sub=(sub-1)&mask){
      if(!is_clique[sub]) continue;
      dp[mask] = min(dp[mask], 1 + dp[mask ^ sub]);
    }
  }

  cout << dp[(1<<n)-1] << endl;

  
  return 0;
}