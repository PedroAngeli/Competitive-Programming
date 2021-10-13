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
const ld PI = acos(-1);

bool eq(ld x, ld y){ //x == y
  return fabs(x - y) < EPS;
}

bool lte(ld x,ld y){ //x <= y
  return x < y + EPS;
}

bool lt(ld x,ld y){ // x < y
  return x + EPS < y; 
}

ld squared(ld x){
  return x*x;
}

ld deg_to_rad(ld theta){
  return (theta * PI)/180.0; 
}

ld rad_to_deg(ld theta){
  return (theta * 180)/PI;
}

struct Point{ //Represents a 2D Point
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
    bool operator<(Point const other){
    return lt(x, other.x) or (eq(x, other.x) and lt(y, other.y));
  }
};

struct Vec{ //Represents a 2D Vector
  ld x,y;
  Vec(ld x=0,ld y=0):x(x),y(y){}
  Vec(Point p1,Point p2){x = p2.x - p1.x,y = p2.y - p1.y;}
  Vec operator*(ld const& c){
    return Vec(c * x,c * y);
  }
  ld norm_sq(){ //Returns the norm of the vector (squared)
    return squared(x) + squared(y);
  }
};

Point translate(Point p, Vec v) { // translate p according to v
  return Point(p.x + v.x , p.y + v.y);  
}

ld euc_dist(Point p1,Point p2){
  return sqrt(squared(p1.x - p2.x) + squared(p1.y - p2.y));
}

ld crossProduct(Vec v1,Vec v2){
    return (v1.x * v2.y - v1.y * v2.x);
}

int orientation(Point p1,Point p2,Point p3){ //Returns the orientation (0: colinear, 1: counterclockwise, 2:clockwise)
  Vec v1(p1,p2);
  Vec v2(p2,p3);
  ld cross = crossProduct(v1, v2);
  if(eq(cross, 0)) return 0;
  return lt(cross, 0) ? 2 : 1;
}

bool ccw(Point p1, Point p2, Point p3){ //return true if points are collinear or counterclockwise
  return (orientation(p1, p2, p3) != 2);
}

struct Polygon{
  vector <Point> P; //P[0] == P[n-1]. Points are sorted cw or ccw (standard)
  Polygon(){}
  Polygon(vector <Point>& _P){P=_P; P.pb(P[0]);}
};

Polygon convex_hull(vector <Point>& P){
  int n = sz(P);
  if(n <= 3) return Polygon(P);

  int pivot_index = 0;
  for(int i=1;i<n;i++)
    if(lt(P[i].y, P[pivot_index].y) || eq(P[i].y, P[pivot_index].y) && !lte(P[i].x, P[pivot_index].x))
      pivot_index = i;

  swap(P[0], P[pivot_index]);

  sort(P.begin() + 1, P.end(),[&](Point p1, Point p2){
    int o = orientation(P[0], p1, p2);
    if(o == 0) return lt(euc_dist(P[0],p1), euc_dist(P[0],p2));
    return (o == 1);
  });

  vector <Point> S;
  S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
  int i = 2;
  while(i < n){
    int j = sz(S) - 1;
    if(ccw(S[j-1], S[j], P[i])) S.pb(P[i++]);
    else S.pop_back();
  }
  S.pop_back();
  return Polygon(S);
}

ld dot_product(Vec v1, Vec v2){ //Or ||a|| * ||b|| * cos Θ
  return (v1.x * v2.x + v1.y * v2.y);
}

ld distToLine(Point p,Point a, Point b,Point& c){
  Vec ap = Vec(a,p), ab = Vec(a,b);
  ld u = dot_product(ap,ab) / ab.norm_sq();
  c = translate(a, ab * u);
  return euc_dist(p, c);
}

int n;


int main(){
  fastio;
  int ncase = 1;

  while(cin >> n and n){
    cout << fixed << setprecision(2) << "Case " << ncase++ << ": ";
    vector <Point> P(n);
    for(int i=0;i<n;i++) cin >> P[i].x >> P[i].y;
    ld ans = DBL_MAX;
    vector <Point> ch = convex_hull(P).P;
    for(int i=0;i<sz(ch)-1;i++){
      Point a = ch[i];
      Point b = ch[i+1];
      Point c;
      ld mx = 0;
      for(int j=1;j<sz(ch)-1;j++){
        Point p = ch[(i+1+j)%sz(ch)];
        mx = max(mx, distToLine(p, a, b, c));
      }
      ans = min(ans, mx);
    }
    cout << ans << endl;
  }  
  return 0;
}