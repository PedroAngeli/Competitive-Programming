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

const int nax = 1e6 + 5;
const int mod = 1e9;

vpii fac[nax]; //{fac, cnt}

int mul(int a,int b){
  return 1LL * a * b % mod;
}

int main(){
  fastio;

  vi is_prime(nax, 1);
  for(int i=2;i<=1e6;i++)
    if(is_prime[i]){
      fac[i].pb({i, 1});
      for(int j=2*i;j<=1e6;j+=i){
        is_prime[j] = 0;
        int num = j;
        int cnt = 0;
        while(num % i == 0) num /= i, cnt++;
        fac[j].pb({i, cnt});
      }
    }

  vi ans(nax), big_fac(nax, 0);
  ans[1] = 1;

  for(int i=2;i<=1e6;i++){
    bool inc = false;
    for(auto el:fac[i])
      if(el.s > big_fac[el.f]){
        ans[i] = mul(ans[i-1], el.f);
        inc = true;
        big_fac[el.f] = el.s;
        break;
      }
    if(!inc) ans[i] = ans[i-1];
  }

  int n;
  while(cin >> n and n){
    string num = to_string(ans[n]);
    int i = sz(num) - 1;
    while(num[i] == '0') i--;
    cout << num[i] << endl;
  }
  return 0;
}