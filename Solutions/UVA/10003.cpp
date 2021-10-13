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

int l, n;
int c[52];
int dp[52][52];
int opt[52][52];
int f[52][52];
const int INF = 1e9 + 7;

int main(){
  fastio;

  while(cin >> l and l){
    cin >> n;
    c[0] = 0;
    c[n+1] = l;
    for(int i=1;i<=n;i++) cin >> c[i];
      
    for(int i=0;i<=n+1;i++)
      for(int j=0;j<=n+1;j++){
        dp[i][j] = INF;
        if(i == j or i+1 == j) 
          dp[i][j] = 0, opt[i][j] = j;
      }


    for(int i=n+1;i>=0;i--)
      for(int j=i+1;j<=n+1;j++){
        for(int k=opt[i][j-1];k<=opt[i+1][j];k++){
          if(dp[i][j] > dp[i][k] + dp[k][j] + (c[j] - c[i])){
            dp[i][j] = dp[i][k] + dp[k][j] + (c[j] - c[i]);
            opt[i][j] = k;
          }
        }
      }
       
    cout << "The minimum cutting is " << dp[0][n+1] << "." << endl;
  }
  
  return 0;
}