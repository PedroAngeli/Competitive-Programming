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

int n;
int f[251];
int pref[251];
int dp[251][251];
int opt[251][251];
const int INF = 1e9 + 7;


int w(int l,int r){
  if(l > r) return 0;
  int ret = pref[r] - pref[l-1];
  return ret;
}

int main(){
  fastio;

  while(cin >> n){
    for(int i=1;i<=n;i++){
      cin >> f[i];
      pref[i] = f[i];
      pref[i] += pref[i-1];
    } 

    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        if(i < j) dp[i][j] = INF;
        else opt[i][j] = i;

    for(int i=n;i>=1;i--)
      for(int j=i+1;j<=n;j++)
        for(int k=opt[i][j-1];k<=opt[i+1][j];k++){
          int p = w(i, k-1) + w(k+1, j);
          if(i <= k-1) p += dp[i][k-1];
          if(k+1 <= j) p += dp[k+1][j];
          if(dp[i][j] > p){
            dp[i][j] = p;
            opt[i][j] = k;
          }
        }

    cout << dp[1][n] << endl;
  }

  
  return 0;
}