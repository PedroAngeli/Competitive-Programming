#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ld = long double;
using ll = long long;

#define endl '\n'
// #define f first
// #define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;
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

const int mod = 998244353;

void add_mod(int& a, int b){
  a += b;
  a %= mod;
  if(a < 0)
    a += mod;
}
int main(){
  fastio;

  int n, m;
  cin >> n >> m;
  vector <int> l(n), r(n);
  for(int i=0;i<n;i++)
    cin >> l[i] >> r[i];
  
  vector <int> ans(m+1, 0);

  for(int g=m;g>=1;g--){
    int mx_sum = m/g;
    vector <vector <int> > dp(n, vector <int>(mx_sum+1, 0));

    for(int s=0;s<=mx_sum;s++){
      int L = (l[n-1]+g-1)/g;
      int R = r[n-1]/g;
      add_mod(dp[n-1][s], (L <= s and s <= R));
      if(s > 0)
          add_mod(dp[n-1][s], dp[n-1][s-1]);
    }

    for(int i=n-2;i>=0;i--)
      for(int s=0;s<=mx_sum;s++){
        int L = (l[i]+g-1)/g;
        int R = r[i]/g;
        int p1 = s-R;
        int p2 = s-L;
        
        dp[i][s] = 0;
        if(p2 >= 0)
          add_mod(dp[i][s], dp[i+1][p2]);
        if(p1 > 0)
          add_mod(dp[i][s], -dp[i+1][p1-1]);

        if(s > 0)
          add_mod(dp[i][s], dp[i][s-1]);
        // for(int x=L;x<=R;x++){
        //     if(s - x >= 0)
        //       add_mod(dp[i][s], dp[i+1][s-x]);
        // }
      }

    ans[g] = dp[0][mx_sum];
    for(int j=2*g;j<=m;j+=g)
      add_mod(ans[g], -ans[j]);
  }


  cout << ans[1] << endl;
  return 0;
}