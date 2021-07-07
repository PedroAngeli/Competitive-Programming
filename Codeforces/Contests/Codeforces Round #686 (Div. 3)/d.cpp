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

  int t = 1;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    vpll fac;
    ll div = 2;
    while(div*div <= n){
      int cnt = 0;
      while(n % div == 0){
        cnt++;
        n /= div;
      }
      if(cnt) fac.pb({cnt, div});
      div++;
    }
    if(n != 1) fac.pb({1, n});

    sort(all(fac),[&](auto p1, auto p2){
      return p1.f > p2.f;
    });

    if(sz(fac) == 1){
      cout << fac[0].f << endl;
      int cnt = fac[0].f;
      while(cnt--) cout << fac[0].s << " ";
    }else{
      ll prod = fac[0].s;
      for(int i=1;i<sz(fac);i++){
        int cnt = fac[i].f;
        while(cnt--) prod *= fac[i].s;
      }
      int c = fac[0].f;
      cout << c << endl;
      c--;
      while(c--){
        cout << fac[0].s << " ";
      }
      cout << prod;
    }

    cout << endl;
  }
  return 0;
}