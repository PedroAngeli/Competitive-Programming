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
    int n;
    cin >> n;
    vll a(n), b(n);
    ll pont1 = 0;
    ll pont2 = 0;

    for(int i=0;i<n;i++){
      cin >> a[i];
      pont1 += a[i];
    }
    for(int i=0;i<n;i++){
      cin >> b[i];
      pont2 += b[i];
    }
    
    sort(all(a));
    int it = 0;
    while(it < n/4)
      pont1 -= a[it++];

    sort(all(b));
    reverse(all(b));
    int it2 = n-1;
    while(it2 > n - n/4 - 1)
      pont2 -= b[it2--];

    // debug(pont1, pont2);

    while(pont1 < pont2){
      a.pb(100);
      pont1 += 100;
      if(it < (sz(a)/4))
        pont1 -= a[it++];

      b.pb(0);
      if(it2 < sz(b)-(sz(b)/4)-1)
        pont2 += b[++it2];

      // debug(pont1, pont2, it, it2);
    }

    cout << sz(a) - n << endl;
  }
  return 0;
}