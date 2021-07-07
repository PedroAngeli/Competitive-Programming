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


struct Graph{
  vector <vi> adj; 
  int V;
  vi in_stack;
  vi dfs_num;
  vi dfs_low;
  int dfs_counter;
  stack <int> p;
  int id_comp;
  vi comp;

  Graph(int V): V(V){
    comp.resize(V);
    adj.resize(V);
  }

  void addEdge(int u,int v){
    adj[u].pb(v); 
  }
  
  void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    p.push(u);
    in_stack[u] = 1;

    for(int v : adj[u]){
      if(dfs_num[v] == -1){
        dfs(v);
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
      }else if(in_stack[v])
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_num[u] == dfs_low[u]){
      while(true){
        int v = p.top();
        comp[v] = id_comp;
        in_stack[v] = 0;
        p.pop();
        if(u == v)
          break;
      }
      id_comp++;
    }
  }

  void tarjanSCC(){
    in_stack.assign(V,0);
    dfs_num.assign(V,-1);
    dfs_low.resize(V);
    dfs_counter = 0;
    id_comp = 0;
    for(int i=0;i<V;i++){
      if(dfs_num[i] == -1)
        dfs(i);
    }
  }

  int neg(int u){
    return u ^ 1;
  }

  void add_or(int u,int v){
    addEdge(neg(u), v);
    addEdge(neg(v), u);
  }

  void force_var(int u){
    addEdge(neg(u), u);
  }

  void add_xor(int u,int v){
    add_or(u,v);
    add_or(neg(u), neg(v));
  }
};

struct Point{
  ll x,y;
  Point(ll x=0,ll y=0):x(x),y(y){}
};

struct Vec{
  ll x,y;
  Vec(ll x=0,ll y=0):x(x),y(y){}
  Vec(Point p1,Point p2){x = p2.x - p1.x,y = p2.y - p1.y;}
};

ll crossProduct(Vec v1,Vec v2){
    return (v1.x * v2.y - v1.y * v2.x);
}

bool onSegment(Point p,Point r,Point q){ //Returns true if r lies on segment pq
  return (min(p.x,q.x) <= r.x && r.x <= max(p.x,q.x)) && 
  (min(p.y,q.y) <= r.y && r.y <= max(p.y,q.y));
}

int orientation(Point p1,Point p2,Point p3){ //Returns the orientation (0: colinear, 1: counterclockwise, 2:clockwise)
  Vec v1(p1,p2);
  Vec v2(p2,p3);
  ll cross = crossProduct(v1, v2);
  if(cross == 0) return 0;
  return cross < 0 ? 2 : 1;
}

bool line_seg_intersection(Point p1,Point q1, Point p2,Point q2){ //Se if two line segments intersects
  int o1 = orientation(p1,q1,p2);
  int o2 = orientation(p1,q1,q2);
  int o3 = orientation(p2,q2,p1);
  int o4 = orientation(p2,q2,q1);
  if(o1 != o2 && o3 != o4) return true;

  return (!o1 && onSegment(p1,p2,q1)) || (!o2 && onSegment(p1,q2,q1)) ||
  (!o3 && onSegment(p2,p1,q2)) || (!o4 && onSegment(p2,q1,q2));
}

struct Seg{
  Point p1, p2;
  int idx;
  bool is_neg;
  Seg(Point p1, Point p2, int idx, bool is_neg):p1(p1), p2(p2), idx(idx), is_neg(is_neg){}
};

void read(Point& p){
  cin >> p.x >> p.y;
}

int main(){
  fastio;

  int n;
  while(cin >> n and n){
    vector <Seg> diag;
    for(int i=0;i<n;i++){
      vector <Point> P(4);
      for(int j=0;j<4;j++) read(P[j]);
      sort(all(P),[&](Point p1, Point p2){
        return (p1.x < p2.x) || (p1.x == p2.x && p1.y < p2.y); 
      });
      diag.pb(Seg(P[0],P[3], i, false));
      diag.pb(Seg(P[1],P[2], i, true));
    }

    Graph G(2*sz(diag));

    for(int i=0;i<sz(diag);i++)
      for(int j=i+1;j<sz(diag);j++){
        int i1 = diag[i].idx, i2 = diag[j].idx;
        if(i1 == i2) continue;
        bool is_neg1 = diag[i].is_neg, is_neg2 = diag[j].is_neg;

        int u = is_neg1 ? G.neg(2 * i1) : 2*i1;
        int v = is_neg2 ? G.neg(2 * i2) : 2*i2;

        Point p1 = diag[i].p1, q1 = diag[i].p2;
        Point p2 = diag[j].p1, q2 = diag[j].p2; 
        if(line_seg_intersection(p1, q1, p2, q2)) G.add_or(u,v);
      }

    G.tarjanSCC();

    bool can = true;
    for(int i=0;i<2*sz(diag);i++){
      if(G.comp[i] == G.comp[G.neg(i)]) can = false;
    }
      
    
    cout << (can ? "YES" : "NO") << endl;
  }  

  
  return 0;
}