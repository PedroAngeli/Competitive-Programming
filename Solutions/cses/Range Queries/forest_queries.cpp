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


int main(){
  fastio;

  int n,q;
  cin >> n >> q;

  vector <vi> pref(n, vi(n, 0));

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
      char c;
      cin >> c;
      pref[i][j] = (c == '*');
      if(i > 0) pref[i][j] += pref[i-1][j];
      if(j > 0) pref[i][j] += pref[i][j-1];
      if(i > 0 and j > 0) pref[i][j] -= pref[i-1][j-1];
    }

  while(q--){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, y1--, x2--, y2--;
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);

    int ans = pref[x2][y2];
    if(x1 > 0) ans -= pref[x1-1][y2];
    if(y1 > 0) ans -= pref[x2][y1-1];
    if(x1 > 0 and y1 > 0) ans += pref[x1-1][y1-1];

    cout << ans << endl; 
  }
  
  return 0;
}