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


const ld EPS = 1e-9;

bool lte(ld x,ld y){ //x <= y
  return x < y + EPS;
}

int main(){
  fastio;

  ld l,w,h,a;
  const ld PI = acos(-1);
  while(cin >> l >> w >> h >> a){
    ld hl = tan(a*PI/180) * l;
    ld hl2 = tan((90 - a)*PI/180) * h;
    ld ans;
    if(lte(hl, h)) ans = l*w*h - (hl* l)/2 * w; 
    else ans = (hl2 * h)/2 * w; 
    cout << fixed << setprecision(3) << ans << " mL" << endl;
  }
  
  return 0;
}