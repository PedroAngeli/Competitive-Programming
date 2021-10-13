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

struct Circle{
  ll x,y,r;
};

ld PI = acos(-1);
vector <Circle> circles;
vi adj[1000];
ld ans;

ll squared(ll x){
  return x*x;
}

ld area(Circle c){
  return PI*c.r*c.r;
}

bool in(Circle c1,Circle c2){
  if(c1.r >= c2.r)
    return false;
  ld dist = sqrt(squared(c1.x - c2.x) + squared(c1.y - c2.y));
  
  return dist < (ld)(c1.r + c2.r);
}

void solve(int u,int h,int p){
  if(h == 0 || h%2 == 1)
    ans += area(circles[u]);
  else
    ans -= area(circles[u]);
  for(int v:adj[u])
    if(v != p)
      solve(v,h+1,u);
}

int main(){
  fastio;

  int n;
  cin >> n;

  circles.resize(n);
  for(int i=0;i<n;i++)
    cin >> circles[i].x >> circles[i].y >> circles[i].r;
  
  vi roots;

  for(int i=0;i<n;i++){
    ll r = INT_MAX;
    int id = -1;

    for(int j=0;j<n;j++){
      if(i == j)
        continue;
      if(in(circles[i],circles[j])){
        if(circles[j].r < r){
          r = circles[j].r;
          id = j;
        }
      }
    }

    if(id == -1)
      roots.pb(i);
    else
      adj[id].pb(i);
  }
    
  
  for(int u:roots)
    solve(u,0,-1);
  
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}