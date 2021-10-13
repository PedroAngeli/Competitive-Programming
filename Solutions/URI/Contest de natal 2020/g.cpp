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

ll pascal[51][51];

void generates_pascal(int n=50){
    for(int i=0;i<=n;i++)
      for(int j=0;j<=i;j++){
        if(j == 0 || j == i) pascal[i][j] = 1;
        else pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
      }
}

int main(){
  fastio;

  int t;
  cin >> t;

  generates_pascal();

  for(int i=1;i<=t;i++){
    int n, k, x;
    cin >> n >> k >> x;
    ld p = 1.0*x/100;
    ld np = 1 - p;
    ld ans = (ld)pascal[n][k]*pow(p, k)*pow(np, n - k)*100;

    cout << "A chance de Basy acertar o numero no dia " << i << " eh ";
    cout << fixed << setprecision(2) << ans << "%" << endl;
  }
  
  return 0;
}