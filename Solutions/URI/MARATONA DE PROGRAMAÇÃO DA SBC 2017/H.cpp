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

const int nax = 105;
vi adj[nax];
vi vis;
int ans;

struct Point{ //Represents a 2D Point
  int x,y;
  Point(int x=0,int y=0):x(x),y(y){}
  bool operator<(Point const other){
    return (x < other.x) || (x == other.x == y < other.y);
  }
};

struct Vec{ //Represents a 2D Vector
  int x,y;
  Vec(Point p1,Point p2 = Point()){x = p2.x - p1.x,y = p2.y - p1.y;}
  Vec operator+(Vec const& other){
    return Vec(x + other.x, y + other.y);
  }
  Vec operator-(Vec const& other){
    return Vec(x - other.x, y - other.y);
  }
  Vec operator*(int const& c){
    return Vec(c * x,c * y);
  }
  int crossProduct(Vec& other){
    return (x * other.y - y * other.x);
  }
};

void dfs(int u,int qtd){
  vis[u] = 1;
  for(int v : adj[u])
    if(!vis[v])
      dfs(v,qtd + 1);
  ans = max(ans, qtd);
  vis[u] = 0;
}

Point a,b;

int orientation(Point p1,Point p2,Point p3){ //Returns the orientation (0: colinear, 1: counterclockwise, 2:clockwise)
  Vec v1(p1,p2);
  Vec v2(p2,p3);
  int cross = v1.crossProduct(v2);
  if(cross == 0) return 0;
  return cross > 0 ? 1 : 2;
}

bool can(Point p1,Point p2){
  int o1 = orientation(p1,p2,a);
  int o2 = orientation(p1,p2,b);

  return o1 != o2;
}
int main(){
  fastio;

  int n;
  cin >> n;
  cin >> a.x >> b.x;

  vector <Point> points(n);

  for(int i=0;i<n;i++)
    cin >> points[i].x >> points[i].y;
  
  for(int i=0;i<n;i++){
    int idx = -1;
    int y = 0;
    for(int j=0;j<n;j++){
      if(i == j || points[i].y <= points[j].y) continue;
      if(can(points[i],points[j]))
        adj[i].pb(j);
    }
  }
    
  for(int i=0;i<n;i++){
    vi dist(n,0);
    for(int j=0;j<n-1;j++)
      for(int k=0;k<n;k++){
        for(int v:adj[k])
          dist[v] = max(dist[v],1 + dist[k]);
      }
    for(int k=0;k<n;k++)
      ans = max(ans, dist[k]);
  }

  cout << ans+1 << endl;
  return 0;
}