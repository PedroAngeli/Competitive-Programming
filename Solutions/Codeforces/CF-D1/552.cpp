#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define ub  upper_bound
#define lb  lower_bound
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
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

using Line = pair <pll,ll>;

Line get_line(ll x1,ll y1,ll x2,ll y2){
  ll dx = x2 - x1;
  ll dy = y2 - y1;
  ll a = dy;
  ll b = -dx;
  ll c = a*x1 + b*y1;
  ll gcd = __gcd(__gcd(a,b),c);
  a /= gcd;
  b /= gcd;
  c /= gcd;
  Line l = {{a,b},c};
  return l;
}

ll comb3(ll n){
  if(n < 3) return 0;
  return n * (n - 1) * (n - 2) / 6;
}

int main(){
  fastio;

  int n;
  cin >> n;
  vi x(n);
  vi y(n);
  for(int i=0;i<n;i++)
    cin >> x[i] >> y[i];

  map <Line, ll> cnt;

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      cnt[get_line(x[i],y[i],x[j],y[j])] += 2;

  ll ans = comb3(n);

  for(auto el:cnt){
    for(int i=1;i<=n;i++)
      if(i * (i-1) == el.s){
        ans -= comb3(i);
        break;
      }
  }
  
  cout << ans << endl;
  return 0;
}