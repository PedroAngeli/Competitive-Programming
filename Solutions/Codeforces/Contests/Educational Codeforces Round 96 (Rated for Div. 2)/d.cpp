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
const int nax = 2e5 + 5;

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    string s;
    cin >> n >> s;
    
    int i = 0;
    int idx = 0;
    vi a;
    vi pos;

    while(i < n){
      int c = 0;
      while(i < n and s[i] == '0') c++, i++;
      if(c) a.pb(c);
      if(c > 1) pos.pb(sz(a)-1);
      c = 0;
      while(i < n and s[i] == '1') c++, i++;
      if(c) a.pb(c);
      if(c > 1) pos.pb(sz(a)-1);
    }
    
    i = 0;
    int j = 0;
    int ans = 0;
    while(i < sz(a)){
      if(a[i] > 1) i++;
      else{
        while(j < sz(pos) and pos[j] < i) j++;
        while(j < sz(pos) and a[pos[j]] == 1) j++;
        if(j < sz(pos)) a[pos[j]]--;
        else a.pop_back();  
        i++;
      }
      ans++;
    }
    cout << ans << endl;
  }
  
  return 0;
}