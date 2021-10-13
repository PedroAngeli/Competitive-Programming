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

int mat[8][8];
vi perm;
int n;
vector <vi> order;

int solve(int i,int mask){
  if(i == n) return 0;
  int p = perm[i];
  for(auto el : order[i])
    if(((1 << el) & mask) == 0)
      return mat[p][el] + solve(i+1, mask | (1 << el));
  
  return 0;
}

int main(){
  fastio;

  int t;
  cin >> t;
  while(t--){
    cin >> n;
    order.clear();
    order.resize(n);
    for(int i=0;i<n;i++){
      vpii tmp;
      for(int j=0;j<n;j++){
        cin >> mat[i][j];
        tmp.pb({mat[i][j],i});
      }
      sort(all(tmp));
      for(auto el : tmp) order[i].pb(el.s); 
    }
    perm.resize(n);
    iota(all(perm),0);
    int ans = INT_MAX;
    do{
      ans = min(ans, solve(0, 0));
    }while(next_permutation(all(perm)));

    cout << ans << endl;
  }
  return 0;
}