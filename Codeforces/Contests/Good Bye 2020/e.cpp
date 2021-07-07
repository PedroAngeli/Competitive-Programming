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

void add_self(ll& a,ll b){
  a += b;
  if(a >= mod) a -= mod;
}

ll mult(ll a, ll b){
  return (a%mod * b%mod)%mod;
}

int main(){
  fastio;

  int t = 1;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vll a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vi cnt(60, 0);

    for(int i=0;i<n;i++){
      for(int j=0;j<60;j++)
        if(a[i] & (1LL << j)) cnt[j]++;
    }

    vll bit_or(n, 0), bit_and(n, 0);

    for(int i=0;i<n;i++){
      for(int j=0;j<60;j++)
        if(a[i] & (1LL << j)) add_self(bit_or[i], mult((1LL << j), n));
        else add_self(bit_or[i], mult((1LL << j), cnt[j]));
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<60;j++)
        if(a[i] & (1LL << j)) add_self(bit_and[i], mult((1LL << j), cnt[j]));
    }

    ll ans = 0;

    for(int i=0;i<n;i++)
      add_self(ans, mult(bit_and[i], bit_or[i]));

    cout << ans << endl;
  }
  
  return 0;
}