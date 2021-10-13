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

  ll n, m, u;
  cin >> n >> m >> u;

  vll a(n);
  
  for(int i=0;i<n;i++) cin >> a[i];

  vll original = a;

  int sqrt_n = sqrt(n) + 1;

  for(int i=0;i<n;i+=sqrt_n) 
    sort(a.begin()+i,min(a.begin()+i+sqrt_n, a.end()));
  
  while(m--){
    int l, r, v, p;
    cin >> l >> r >> v >> p;
    l--, r--, p--;
    int k = 0;

    for(int i=l;i<=r;){
      if((i%sqrt_n == 0) and (i+sqrt_n-1 <= r)){
        k += (lb(a.begin()+i, min(a.begin()+i+sqrt_n, a.end()), v) - (a.begin()+i));
        i += sqrt_n;
      }
      else{
        k += (original[i] < v);
        i++;
      }
    }
    ll new_el = (u*k)/(r-l+1);
    int idx = (p/sqrt_n) * sqrt_n;
    
    for(int i=idx;i<idx+sqrt_n;i++)
        if(a[i] == original[p]){
          a[i] = new_el;
          break;
        }
    sort(a.begin()+idx, min(a.end(), a.begin()+idx+sqrt_n));
    original[p] = new_el;
  }


  for(int x:original) cout << x << endl;

  
  return 0;
}