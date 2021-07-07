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
  int x,y;
  Point(int x=0,int y=0):x(x),y(y){}
};

struct Line{ //Represents a 2D Line; (ax + by = c)
  int a,b,c;
  Line(Point p1,Point p2){
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    a = dy;
    b = -dx;
    c = a*p1.x + b*p1.y;
    int gcd = __gcd(a,__gcd(b,c));
    a /= gcd, b /= gcd, c /= gcd;
  }
};

int main(){
  fastio;

  int n;
  cin >> n;
  vector <Point> points(n);

  for(int i=0;i<n;i++)
    cin >> points[i].x >> points[i].y;

  bool is = false;

  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++){
      Line L(points[i], points[j]);
      int cnt = 0;
      for(int k=0;k<n;k++){
        if(i == k || j == k) continue;
        int y = L.a * points[k].x + L.b * points[k].y - L.c;
        if(y == 0){
          is = true;
          j = n;
          i = n;
          break;
        }
      }
    }

  cout << (is ? "Yes" : "No") << endl;
  return 0;
}