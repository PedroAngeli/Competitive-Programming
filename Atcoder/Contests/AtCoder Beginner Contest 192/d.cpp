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

string x;
ll m;

bool overflow(ll a, ll b){
  return a > LLONG_MAX - b;
}

bool f(ll base){
  ll num = 0;

  for(int i=0;i<sz(x);i++){
    //di * base^i
    int di = x[i]-'0';
    if((ld)(log(m)/log(base))-(log(di)/log(base)) < (ld)i) return false;
    if(overflow(num, di*powl(base,i))) return false;
    num += di*powl(base,i);
    if(num > m) return false;
  }
  return true;
}

int main(){
  fastio;

  
  cin >> x >> m;
  reverse(all(x));

  if(sz(x) == 1){
    int X = stoi(x);
    cout << (X <= m) << endl;
    return 0;
  }

  ll mx = 0;
  for(char di : x)
    mx = max(mx, (ll)di-'0');

  ll l = mx + 1;
  ll r = m;

  ll ans = 0;

  while(l <= r){
    ll mid = (l+r)/2;
    if(f(mid)) ans = mid, l = mid+1;
    else r = mid-1;
  }
  cout << max(ans-mx, 0LL) << endl;  
  return 0;
}