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
  vi set_size;
  int n;
  UnionFind(int n):n(n){
    parent.resize(n+1);
    iota(all(parent),0);
    set_size.assign(n+1,1);
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
    if(set_size[x] > set_size[y])
      swap(x,y);
    parent[x] = y;
    set_size[y] += set_size[x];
  }
};

struct Point{ //Represents a 2D Point
  ld x,y;
  Point(ld x=0,ld y=0):x(x),y(y){}
};

const ld EPS = 1e-9;
int n;

vector <Point> points;

bool lte(ld x,ld y){ //x <= y
  return x < y + EPS;
}

bool lt(ld x,ld y){ // x < y
  return x + EPS < y; 
}

ld squared(ld x){
  return x*x;
}

ld euc_dist(Point p1,Point p2){
  return sqrt(squared(p1.x - p2.x) + squared(p1.y - p2.y));
}

bool can(ld m){
  UnionFind dsu(n+2);
  for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
      if(lt(euc_dist(points[i],points[j]), 2*m)) dsu.join(i,j);

  for(int i=0;i<n;i++){
    if(lt(points[i].y + 100, 2*m)) dsu.join(i, n);
    if(lt(100 - points[i].y, 2*m)) dsu.join(i, n+1);
  }
  
  return dsu.find(n) != dsu.find(n+1);
}

int main(){
  fastio;

  cin >> n;
  points.resize(n);
  for(int i=0;i<n;i++)
    cin >> points[i].x >> points[i].y;
  
  ld l = 0;
  ld r = 100;

  ld ans = 0;

  for(int i=0;i<100;i++){
    ld m = (l + r)/2;
    if(can(m)) ans = m, l = m;
    else r = m;
  }

  cout << fixed << setprecision(10) << ans << endl;
  
  return 0;
}