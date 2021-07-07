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

const ld EPS = 1e-6;

bool eq(ld x, ld y){ //x == y
  return fabs(x - y) < EPS;
}

struct Coef{
  ld a, b;
};

Coef operator+ (Coef c1, Coef c2){
    return {c1.a + c2 .a, c1.b + c2.b};
}

Coef operator- (Coef c1, Coef c2){
    return {c1.a - c2 .a, c1.b - c2.b};
}

Coef operator/ (Coef c, ld x){
  return {c.a/x, c.b/x};
}

const int nax = 2e5 + 5;
int is[nax];
Coef suf[nax], f[nax];

int main(){
  fastio;

  int n, m, k;
  cin >> n >> m >> k;

  for(int i=0;i<k;i++){
    int a;
    cin >> a;
    is[a] = 1;
  }

  for(int i=n-1;i>=0;i--){
    if(is[i]) f[i] = {1, 0};
    else f[i] = (suf[i+1]-suf[i+m+1])/m + (Coef){0, 1};
    suf[i] = suf[i+1] + f[i];
  }
  
  if(eq(f[0].a, 1)) cout << -1 << endl;
  else cout << fixed << setprecision(10) << f[0].b/(1-f[0].a) << endl;
  return 0;
}