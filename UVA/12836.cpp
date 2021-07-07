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

const ll INF = 1e18 + 7;

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 1;
  while(t--){
    cout << "Case " << ncase++ << ": ";
    int n;
    cin >> n;
    vi a(n);
    
    for(int i=0;i<n;i++) cin >> a[i];

    vi l1(n, 1);
    for(int i=0;i<n;i++)
      for(int j=0;j<i;j++)
        if(a[i] > a[j])
          l1[i] = max(l1[i], l1[j] + 1);

    vi l2(n, 1);
    for(int i=n-1;i>=0;i--)
      for(int j=i+1;j<n;j++)
        if(a[i] > a[j])
          l2[i] = max(l2[i], l2[j] + 1);

    vi p(n);
    
    for(int i=0;i<n;i++)
      p[i] = l1[i] + l2[i] - 1;

    vll pref(n);
    for(int i=0;i<n;i++){
      pref[i] = p[i];
      if(i) pref[i] += pref[i-1];
    }

    vector <vll> dp(n+1, vll(n+1, INF));
    vector <vi> opt(n+1, vi(n+1));

    for(int i=0;i<n;i++) dp[i][i] = 0, opt[i][i] = i;

    for(int i=n-1;i>=0;i--)
      for(int j=i+1;j<n;j++)
        for(int k=opt[i][j-1];k<=opt[i+1][j];k++){
          ll w = dp[i][k] + dp[k+1][j];
          w += pref[j];
          if(i) w -= pref[i-1];
          if(dp[i][j] > w){
            dp[i][j] = w;
            opt[i][j] = k;
          }
        }


    cout << dp[0][n-1] << endl;
  }

  
  return 0;
}