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

  int t = 1;
  cin >> t;

  while(t--){
    int h, w;
    cin >> h >> w;

    vector <vi> ans(h, vi(w, 0));

    for(int j=0;j<w;j++){
      ans[0][j] = (j%2 == 0);
      ans[h-1][j] = (j%2 == 0);
    }

    for(int i=1;i<h-1;i++){
      if(ans[i+1][0] == 0 and ans[i-1][0] == 0 and ans[i+1][1] == 0 and ans[i-1][1] == 0)
        ans[i][0] = 1;
      if(ans[i+1][w-1] == 0 and ans[i-1][w-1] == 0 and ans[i+1][w-2] == 0 and ans[i-1][w-2] == 0)
        ans[i][w-1] = 1;
    }

    
    for(vi x:ans){
      for(int y:x)
        cout << y;
      cout << endl;
    }

    cout << endl;
  }
  
  return 0;
}