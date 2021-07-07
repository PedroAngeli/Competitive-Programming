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

struct Point{
  ld x, y;  
  Point(ld x=0,ld y=0):x(x),y(y){}
};

ld squared(ld x){
  return x*x;
}

struct Vec{
  ld x,y;
  Vec(ld x=0,ld y=0):x(x),y(y){}
  Vec(Point p1,Point p2){x = p2.x - p1.x,y = p2.y - p1.y;}
  ld norm_sq(){
    return squared(x) + squared(y);
  }
  Vec operator*(ld const& c){
    return Vec(c * x,c * y);
  }
};

Point translate(Point p, Vec v) {
  return Point(p.x + v.x , p.y + v.y);  
}


ld dot_product(Vec v1, Vec v2){
  return (v1.x * v2.x + v1.y * v2.y);
}

ld euc_dist(Point p1,Point p2){
  return sqrt(squared(p1.x - p2.x) + squared(p1.y - p2.y));
}

ld distToLine(Point p,Point a, Point b,Point& c){
  Vec ap = Vec(a,p), ab = Vec(a,b);
  ld u = dot_product(ap,ab) / ab.norm_sq();
  c = translate(a, ab * u);
  return euc_dist(p, c);
}

ld distToLineSegment(Point p,Point a, Point b, Point& c){
  Vec ap = Vec(a,p), ab = Vec(a,b);
  ld u = dot_product(ap,ab) / ab.norm_sq();
  if(u < 0){
    c = Point(a.x, a.y);
    return euc_dist(p, a);
  }
  if(u > 1){
    c = Point(b.x, b.y);
    return euc_dist(p, b);
  }
  return distToLine(p,a,b,c);
}

int main(){
  fastio;

  Point M;
  while(cin >> M.x >> M.y){
    int n;
    cin >> n;
    vector <Point> p(n+1);
    for(int i=0;i<n+1;i++) cin >> p[i].x >> p[i].y;

    ld ans = LDBL_MAX;
    Point resp;

    for(int i=1;i<n+1;i++){
      Point c;
      ld d = distToLineSegment(M, p[i-1], p[i], c);
      if(d < ans){
        ans = d;
        resp = c;
      }
    }
    cout << fixed << setprecision(4) << resp.x << endl << resp.y << endl;
  }


  
  return 0;
}