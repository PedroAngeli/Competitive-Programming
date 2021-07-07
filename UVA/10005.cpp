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

ld squared(ld x){
  return x*x;
}

struct Point{
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
  ld dist(Point& other){ 
    return sqrt(squared(x - other.x) + squared(y - other.y));
  }
};

struct Circle{
  Point center;
  ld radius;
  Circle(){}
  Circle(Point center, int radius):center(center),radius(radius){}

  bool is_inside(Point p){
    ld d = p.dist(center);
    return d < radius + EPS; 
  }
};

bool circle2PtsRad(Point p1,Point p2, ld radius, Circle& c){ //returns if circle exits and store in c.
  ld d = squared(p1.dist(p2));  //dist squared
  ld det = radius * radius / d - 0.25;
  if(det < 0) return false;
  ld h = sqrt(det);
  c.center.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.center.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  c.radius = radius;
  return true; //to get the other center, reverse p1 and p2
} 

bool solve(vector <Point>& points,Circle& c){
  for(int i=0;i<sz(points);i++)
    if(!c.is_inside(points[i])) return false;

  return true;
}

int main(){
  fastio;

  int n;
  while(cin >> n && n){
    vector <Point> points(n);
    for(int i=0;i<n;i++)
      cin >> points[i].x >> points[i].y;

    ld radius;
    cin >> radius;

    if(n == 1){
      cout << "The polygon can be packed in the circle." << endl;
      continue;
    }

    bool can = false;

    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++){
        Circle c1;
        if(!circle2PtsRad(points[i],points[j],radius,c1)) continue;
        Circle c2;
        circle2PtsRad(points[j],points[i],radius,c2);
        bool ans = solve(points, c1) || solve(points, c2);
        if(ans){
          can = true;
          i = n;
          break;
        }
      }

      if(can) cout << "The polygon can be packed in the circle." << endl;
      else cout << "There is no way of packing that polygon." << endl;
  }
  return 0;
}