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

struct UnionFind{
  vi parent;
  int n;
  UnionFind(int n):n(n){
    parent.resize(n+1);
    iota(all(parent),0);
  }
  int find(int x){
    if(x == parent[x])
      return x;
    return parent[x] = find(parent[x]);
  }
  void join(int x,int y){
    x = find(x);
    y = find(y);
    if(x == y)
      return;
    parent[x] = y;
  }
};

struct Point{
  int x,y;
};

struct Seg{
  Point p1,p2;
};

struct Line{ 
  int a,b,c;
  Line(Point p1,Point p2){
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    a = dy;
    b = -dx;
    c = -a*p1.x -b*p1.y;
     int gcd = __gcd(a,__gcd(b,c));
    a /= gcd, b /= gcd, c /= gcd;
  }
};

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 0;

  while(t--){
     if(ncase)
      cout << endl;
    ncase++;

    int np;
    cin >> np;

    vector <Seg> segs(np);
    for(int i=0;i<np;i++){
      Point p1,p2;
      cin >> p1.x >> p1.y >> p2.x >> p2.y;
      if(p1.y > p2.y)
        swap(p1,p2);
      segs[i].p1 = p1;
      segs[i].p2 = p2;
    }

    UnionFind dsu(np);

    for(int i=0;i<np;i++){
      int idx = -1;
      double mn = DBL_MAX;

      for(int j=0;j<np;j++){
        if(i == j)
          continue;
        
        int x1 = min(segs[j].p1.x, segs[j].p2.x);
        int x2 = max(segs[j].p1.x, segs[j].p2.x);
        Point p1 = segs[i].p1;

        if(x1 <= p1.x && p1.x <= x2){
          Line l(segs[j].p1,segs[j].p2);
          double y = (double)(-l.a * p1.x - l.c)/l.b;
          if(y < p1.y && (double)p1.y - y < mn){
            mn = (double)p1.y - y;
            idx = j;
          }
        }
      }

      if(idx != -1){
        dsu.join(i,idx);
      }
    }

    int ns;
    cin >> ns;
    while(ns--){
      int x,y;
      cin >> x >> y;
      int idx = -1;
      double mn = DBL_MAX;

      for(int j=0;j<np;j++){
        int x1 = min(segs[j].p1.x, segs[j].p2.x);
        int x2 = max(segs[j].p1.x, segs[j].p2.x);
        Point p1;
        p1.x = x;
        p1.y = y;

        if(x1 <= p1.x && p1.x <= x2){
          Line l(segs[j].p1,segs[j].p2);
          double y = (double)(-l.a * p1.x - l.c)/l.b;
          if(y < p1.y && (double)p1.y - y < mn){
            mn = (double)p1.y - y;
            idx = j;
          }
        }
      }

      if(idx == -1)
        cout << x << endl;
      else{
        idx = dsu.find(idx);
        Seg S = segs[idx];
        int ans = S.p1.x;
        cout << ans << endl;
      }
    }
  }
 

  
  return 0;
}