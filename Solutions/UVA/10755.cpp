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
  int ncase = 0;
  while(t--){
    if(ncase) cout << endl;
    ncase++;
    int a,b,c;
    cin >> a >> b >> c;
    ll mat[a][b][c];

    for(int i=0;i<a;i++)
      for(int j=0;j<b;j++)
        for(int k=0;k<c;k++){
          cin >> mat[i][j][k];
          if(j > 0) mat[i][j][k] += mat[i][j-1][k];
          if(k > 0) mat[i][j][k] += mat[i][j][k-1];
          if(j > 0 && k > 0) mat[i][j][k] -= mat[i][j-1][k-1];
        }

    ll ans = LLONG_MIN;

    for(int i=0;i<b;i++)
      for(int j=0;j<c;j++)
        for(int k=i;k<b;k++)
          for(int l=j;l<c;l++){
            ll max_sum_3D = LLONG_MIN;
            ll sum_3D = 0;
            for(int m=0;m<a;m++){
              ll sum_2D = mat[m][k][l];
              if(i > 0) sum_2D -= mat[m][i-1][l];
              if(j > 0) sum_2D -= mat[m][k][j-1];
              if(i > 0 && j > 0) sum_2D += mat[m][i-1][j-1];
              sum_3D += sum_2D;
              max_sum_3D = max(max_sum_3D, sum_3D);
              if(sum_3D < 0) sum_3D = 0;
            }
            ans = max(ans, max_sum_3D);
          }
        
    cout << ans << endl;
  }
  
  
  return 0;
}