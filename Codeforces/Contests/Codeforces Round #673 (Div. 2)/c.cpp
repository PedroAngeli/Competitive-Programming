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

map <int,vi> pos;
int n;

bool can(int m,int x){
  vi cur = pos[x];
  int len = sz(cur);

  for(int i=0;i<len;i++){
    if(i == 0 && m < cur[0])
      return false;
    if(i == len - 1 && m < n - cur[i] + 1)
      return false;
    if(i < len-1 && m < cur[i+1]-cur[i])
      return false;
  }

  return true;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    cin >> n;
    pos.clear();
    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      pos[x].pb(i+1);
    }

    vi ans(n+1,INT_MAX);

    for(int i=1;i<=n;i++){
      int l = 1;
      int r = n;
      int mn = -1;
      if(sz(pos[i]) == 0)
        continue;
      while(l <= r){
        int m = (l+r)/2;
        if(can(m,i))
          mn = m,r = m-1;
        else
          l = m+1;
      }
      
      ans[mn] = min(ans[mn],i);
    }
    
    for(int i=1;i<=n;i++)
      ans[i] = min(ans[i],ans[i-1]);
    for(int i=1;i<=n;i++){
      if(ans[i] == INT_MAX)
        ans[i] = -1;
      cout << ans[i] << " ";

    }
    cout << endl;
  }
  
  return 0;
}