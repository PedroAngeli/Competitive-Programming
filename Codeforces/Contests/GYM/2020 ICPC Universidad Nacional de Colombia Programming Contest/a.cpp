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


ld squared(ld x){
  return x*x;
}

struct Point{
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
};

struct Vec{
  ld x,y;
  Vec(ld x=0,ld y=0):x(x),y(y){}
  Vec(Point p1,Point p2){x = p2.x - p1.x,y = p2.y - p1.y;}
  Vec operator*(ld const& c){
    return Vec(c * x,c * y);
  }
  ld norm(){
    return sqrt(squared(x) + squared(y));
  }
};

Point translate(Point p, Vec v) {
  return Point(p.x + v.x , p.y + v.y);  
}

Point A, B, C, D;


ld euc_dist(Point p1,Point p2){
  return sqrt(squared(p1.x - p2.x) + squared(p1.y - p2.y));
}

ld check(ld x){
  Vec AB(A, B), CD(C, D);
  AB = AB*x;
  ld t = min((ld)1, AB.norm()/CD.norm());
  CD = CD*t;
  Point p1 = translate(A, AB);
  Point p2 = translate(C, CD);
  return euc_dist(p1, p2);
}
int main(){
  fastio;

  cin >> A.x >> A.y >> B.x >> B.y;
  cin >> C.x >> C.y >> D.x >> D.y;

  if(euc_dist(A, B) < euc_dist(C, D)){
    swap(A, C);
    swap(B, D);
  }

  ld l = 0;
  ld r = 1;
  
  for(int i=0;i<200;i++){
    ld delta = (r-l)/3;
    ld m1 = l + delta;
    ld m2 = r - delta;
    ld f1 = check(m1);
    ld f2 = check(m2);
    if(f1 > f2) l = m1;
    else r = m2;
  }

  ld ans = check(l);

  Vec AB(A, B), CD(C, D);
  
  l = CD.norm()/AB.norm();
  r = 1;

  for(int i=0;i<200;i++){
    ld delta = (r-l)/3;
    ld m1 = l + delta;
    ld m2 = r - delta;
    ld f1 = check(m1);
    ld f2 = check(m2);
    if(f1 > f2) l = m1;
    else r = m2;
  }
  ans = min(ans, check(l));
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}