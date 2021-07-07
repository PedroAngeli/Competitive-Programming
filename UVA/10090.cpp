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

//Gives answer to equation a*x_0 + b*y_0 = d
//where d = gcd(a, b)
ll x_0, y_0, d;
void extendedEuclid(ll a, ll b) {
  if (b == 0) {
    x_0 = 1;
    y_0 = 0; 
    d = a; 
    return; 
  }
  extendedEuclid(b, a % b);
  ll xt = y_0;
  ll yt = x_0 - (a / b) * y_0;
  x_0 = xt;
  y_0 = yt;
}

int main(){
  fastio;

  int n;
  while(cin >> n and n){
    ll c1, n1, c2, n2;
    cin >> c1 >> n1 >> c2 >> n2;
    extendedEuclid(n1, n2);

    if(n%d){
      cout << "failed" << endl;
      continue;
    }

    x_0 *= n/d;
    y_0 *= n/d;
    n2 /= d;
    n1 /= d;

    ll mn = ceil(-(ld)x_0/n2);
    ll mx = floor((ld)y_0/n1);

    if(mn > mx){
      cout << "failed" << endl;
      continue;
    }

    ll cost1 = mn*(c1*n2 - c2*n1);
    ll cost2 = mx*(c1*n2 - c2*n1);

    ll x_ans, y_ans;

    if(cost1 < cost2)
      x_ans = x_0 + n2*mn, y_ans = y_0 - n1*mn;
    else 
      x_ans = x_0 + n2*mx, y_ans = y_0 - n1*mx;

    cout << x_ans << " " << y_ans << endl;
  }
  
  return 0;
}