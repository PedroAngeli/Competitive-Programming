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

ld squared(ld x){
  return x*x;
}

struct Point{ //Represents a 2D Point
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
  ld dist(Point& other){
    return sqrt(squared(x - other.x) + squared(y - other.y));
  }
};

struct Vec{ //Represents a 2D Vector
  ld x,y;
  Vec(Point p1,Point p2 = Point()){x = p2.x - p1.x,y = p2.y - p1.y;}

  ld dot_product(Vec& other){ //Or ||a|| * ||b|| * cos Θ
    return (x * other.x + y * other.y);
  }

  ld norm(){
    return squared(x) + squared(y);
  }
  
  ld angle(Vec& other){
    ld ret = this->dot_product(other) / sqrt(this->norm()*other.norm());
    if(ret < -1) ret = -1;
    if(ret > 1) ret = 1;
    return acos(ret);
  }

  ld crossProduct(Vec& other){
    return (x * other.y - y * other.x);
  }
};

struct Circle{
  Point center;
  ld radius;
};

pair <Point,Point> find_tang(Point p,Circle c){
  pair <Point,Point> ret;

  ld b = sqrt(squared(p.x - c.center.x) + squared(p.y - c.center.y));
  ld th = acos(c.radius / b);
  ld d = atan2(p.y - c.center.y, p.x - c.center.x);
  ld d1 = d + th;
  ld d2 = d - th;

  ret.f.x = c.center.x + c.radius * cos(d1);
  ret.s.x = c.center.x + c.radius * cos(d2);

  ret.f.y = c.center.y + c.radius * sin(d1);
  ret.s.y = c.center.y + c.radius * sin(d2);

  return ret;
}

ld solve(Point p1, Point p2, Circle c){
  ld PI = acos(-1);
  ld comp = 2 * PI * c.radius;
  Vec v1 = Vec(c.center, p1);
  Vec v2 = Vec(c.center, p2);
  ld a = v1.angle(v2);
  a = (a*180)/PI;
  return (a*comp)/360;
}

int main(){
  fastio;

  Point p1, p2;
  cin >> p1.x >> p1.y;
  cin >> p2.x >> p2.y;
  
  Circle blue, red;
  cin >> blue.center.x >> blue.center.y >> blue.radius;
  cin >> red.center.x >> red.center.y >> red.radius;

  pair <Point,Point> t1 = find_tang(p1, red);
  pair <Point,Point> t2 = find_tang(p2, red);

  ld a1 = p1.dist(t1.f) + p2.dist(t2.f) + solve(t1.f, t2.f,red);
  ld a2 = p1.dist(t1.f) + p2.dist(t2.s) + solve(t1.f, t2.s,red);
  ld a3 = p1.dist(t1.s) + p2.dist(t2.f) + solve(t1.s, t2.f,red);
  ld a4 = p1.dist(t1.s) + p2.dist(t2.s) + solve(t1.s, t2.s,red);

  ld ans = min({a1, a2, a3, a4});

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}