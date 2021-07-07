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

int n,k;
ld ff1,ff2,ff3;
ld fat[501];

void init(int n){
  ld f1 = 0;
  for(int i=1;i<=n;i++){
    fat[i] = log(i) + fat[i-1];
  }
}

ld n_chooses_k(int n,int k){
  ld f1 = fat[n];
  ld f2 = fat[k];
  ld f3 = fat[n-k];

  ld ans = expl(f1 + ff2 + ff3 - (ff1 + f2 + f3));

  return ans;
}

int main(){
  fastio;

  cout << fixed << setprecision(9);

  cin >> n >> k;
  
  init(n);
  ff1 = fat[n];
  ff2 = fat[k];
  ff3 = fat[n-k];
  
  vector <ld> p(n);
  for(int i=0;i<n;i++)
    cin >> p[i];
  
  
  vector <ld> ans(n);

  for(int i=0;i<n;i++){
    for(int j=0;j<=n-1;j++){
      int idx = ((i-j)%n + n)%n;
      if(k-1 > n-j-1)
        continue;
      ans[i] += p[idx]*n_chooses_k(n-j-1,k-1); 
    }
  }

  for(int i=0;i<n;i++)
    cout << ans[i] << " ";
  cout << endl;
  
  return 0;
}