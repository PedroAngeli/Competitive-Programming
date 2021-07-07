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

  int n;
  cin >> n;

  if(n==1){
    cout << 1 << endl;
    return 0;
  }

  if((n%2 && (n-1)%4) || (n%2 == 0 && n%4)){
    cout << -1 << endl;
    return 0;
  }

  vi ans(n+1, -1);

  int i = 1;
  int cur = 2;

  while(i <= n/2){
    ans[i] = cur; 
    int j = i;
    while(ans[ans[j]] == -1){
      ans[ans[j]] = n - j + 1;
      j = ans[j];
    }
    i += 2;
    cur += 2;
  }

  if(n%2)
    ans[(n+1)/2] = (n+1)/2;

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";
  cout << endl;
  
  return 0;
}