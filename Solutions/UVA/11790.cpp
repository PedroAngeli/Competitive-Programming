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

  int t;
  cin >> t;
  for(int i=1;i<=t;i++){
    cout << "Case " << i << ". ";
    int n;
    cin >> n;
    vi h(n), w(n);
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> w[i];

    vi lis(n, 0);
    for(int i=0;i<n;i++) lis[i] = w[i];
    int inc = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<i;j++)
        if(h[i] > h[j]) lis[i] = max(lis[i], lis[j] + w[i]);
      inc = max(inc, lis[i]);
    }
      
    vi lds(n, 0);
    for(int i=0;i<n;i++) lds[i] = w[i];
    int dec = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<i;j++)
        if(h[i] < h[j])
          lds[i] = max(lds[i], lds[j] + w[i]);
      dec = max(dec, lds[i]);
    }
    if(inc >= dec) cout << "Increasing (" << inc << "). Decreasing (" << dec << ")." << endl;
    else cout << "Decreasing (" << dec << "). Increasing (" << inc << ")." << endl;
  }
  return 0;
}