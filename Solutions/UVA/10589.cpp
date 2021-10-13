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

const ld EPS = 1e-15;

ld squared(ld x){
  return x*x;
}

bool lte(ld x,ld y){ //x <= y
  return x < y + EPS;
}

struct Point{
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
};

ld euc_dist_sq(Point p1,Point p2){
  return squared(p1.x - p2.x) + squared(p1.y - p2.y);
}

struct Circle{
  Point center;
  ld radius; 
  Circle(){}
  Circle(Point center, ld radius):center(center),radius(radius){}

  bool is_inside(Point p){
    ld d = euc_dist_sq(p, center);
    return lte(d, radius*radius);
  }
};

int main(){
  fastio;

  int n, a;
  while(cin >> n >> a){
    if(n == 0 and a == 0) break;
    Circle c1(Point(0,0), a);
    Circle c2(Point(0,a), a);
    Circle c3(Point(a,0), a);
    Circle c4(Point(a,a), a);

    int m = 0;

    for(int i=0;i<n;i++){
      Point p;
      cin >> p.x >> p.y;
      if(c1.is_inside(p) and c2.is_inside(p) and c3.is_inside(p) and c4.is_inside(p)) 
        m++;
    } 

    cout << fixed << setprecision(5);
    ld ans = (ld) m * a * a / n;
    cout << ans << endl;
  }
  
  return 0;
}