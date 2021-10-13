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

const int mod = 1e9 + 7;

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
  fastio;

  int t;
  cin >> t;

  while(t--){
    ll n, k;
    cin >> n >> k;
    
    if(n&1){ //n is odd
      //and = 0 and xor = 0 (nC0 + nC2 + ... + nC(n-1) = 2^n-1)
      //and = 1 and xor = 1 (1 case)
      //we do that for every bit i, 0 <= i <= k-1
      cout << binpow(binpow(2, n-1) + 1, k) << endl;
    }else{ //n is even
      //and = 0 and xor = 0 (nC0 + nC2 + ... + nC(n-2) = 2^n-1 - 1)
      ll ways00 = binpow(2, n-1) - 1;

      //and = 1 and xor = 0
      //pow((ways and = 0 and xor = 0), i)*(possible number of combinations for the other bits)
      ll ways10 = 0;
      for(int i=0;i<k;i++){
        ways10 += (binpow(ways00, i)*binpow(binpow(2, n),k-i-1))%mod;
        ways10 %= mod;
      }
      ways00 = binpow(ways00, k);
      ll ans = (ways00 + ways10 + mod)%mod;

      cout << ans << endl;
    }
  }
  
  return 0;
}