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

int n;
ld A;
ld B;
const ld EPS = 1e-9;

bool can(ld m){
  ld f1 = m;
  ld f2 = A;
  ld p; 

  for(int i=3;i<=n;i++){
    p = 2*f1 - f2 + 2;
    if(p < EPS)
      return false;
    f2 = f1;
    f1 = p;
  }
  
  B = p;
  return true;
}

int main(){
  fastio;

  while(cin >> n >> A){
    ld l = 0;
    ld r = A;

    for(int i=0;i<50;i++){
      ld m = (l+r)/2;
      if(can(m))
        r = m;
      else
        l = m;
    }
    cout << fixed << setprecision(2) << B << endl;
  }
  return 0;
}