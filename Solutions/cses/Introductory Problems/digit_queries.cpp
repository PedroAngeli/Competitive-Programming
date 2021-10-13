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

ll my_pow(int a){
  ll res = 1;

  for(int i=0;i<a;i++)
    res *= 10;

  return res;
}

int main(){
  fastio;

  int q;
  cin >>q;

  vll pref(1, 0);
  int n_digs = 1;
  while(true){
    ll nxt = 9*n_digs*my_pow(n_digs-1);
    pref.pb(pref.back() + nxt);
    if(pref.back() >= 1e18)
      break;
    n_digs++;
  }
  
  while(q--){
    ll k;
    cin >> k;
    int qtd_digs = lb(all(pref), k) - pref.begin();
    ll sum = pref[qtd_digs-1];
    ll dif = k - sum - 1;
    string num = to_string(my_pow(qtd_digs-1) + dif/qtd_digs);
    cout << num[dif%qtd_digs] << endl; 
  }
  
  return 0;
}