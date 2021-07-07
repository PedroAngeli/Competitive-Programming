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

struct Point{ //Represents a 2D Point
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
};

struct Vec{ //Represents a 2D Vector
  ld x,y;
  Vec(ld x=0,ld y=0):x(x),y(y){}
  Vec(Point p1,Point p2){x = p2.x - p1.x,y = p2.y - p1.y;}
};

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
  ld perimeter(){
    ld res = 0;
    for(int i=0;i<sz(P)-1;i++) res += euc_dist(P[i], P[i+1]);
    return res;
  }
};

Polygon convex_hull(vector <Point>& P){
  int n = sz(P);

  int pivot_index = 0;
  for(int i=1;i<n;i++)
    if(lt(P[i].y, P[pivot_index].y) || (eq(P[i].y, P[pivot_index].y) && !lte(P[i].x, P[pivot_index].x)))
      pivot_index = i;

  swap(P[0], P[pivot_index]);

  sort(P.begin() + 1, P.end(),[&](Point p1, Point p2){
    int o = orientation(P[0], p1, p2);
    if(o == 0) return lt(euc_dist(P[0],p1), euc_dist(P[0],p2));
    return (o == 1);
  });

  if(n <= 3) return Polygon(P);

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

int main(){
  fastio;

  int n;
  int region = 1;
  while(cin >> n && n){
    if(region > 1) cout << endl;
    cout << "Region #" << region++ << ":" << endl;
    vector <Point> P(n);
    for(int i=0;i<n;i++) cin >> P[i].x >> P[i].y;
    Polygon pol = convex_hull(P);
    vector <Point> ans = pol.P;
    reverse(all(ans));
    cout << fixed << setprecision(1) << "(" << ans[0].x << "," << ans[0].y << ")";
    for(int i=1;i<sz(ans);i++) cout << "-(" << ans[i].x << "," << ans[i].y << ")";
    cout << endl;
    cout << fixed << setprecision(2) << "Perimeter length = " << pol.perimeter() << endl;
  }
  return 0;
}