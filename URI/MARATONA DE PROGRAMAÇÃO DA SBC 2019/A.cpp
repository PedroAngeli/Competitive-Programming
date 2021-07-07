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

const int nax = 1005;
vi adj[nax];

int squared(int x){
  return x*x;
}

struct Point{ //Represents a 2D Point
  int x,y,S;
  Point(int x=0,int y=0):x(x),y(y){}
  int dist(Point& other){ //Returns dist between two points (squared)
    return squared(x - other.x) + squared(y - other.y);
  }
};

vi vis;

bool solve(int u,int t){
  if(u == t)
    return true;
  
  vis[u] = 1;

  bool ret = false;

  for(int v:adj[u])
    if(!vis[v])
      ret = (ret or solve(v,t));

  return ret;
}

int main(){
  fastio;

  int m,n,k;
  cin >> m >> n >> k;

  vector <Point> sensors(k);
  
  for(int i=0;i<k;i++)
    cin >> sensors[i].x >> sensors[i].y >> sensors[i].S;
  
  for(int i=0;i<k;i++){
    int x = sensors[i].x;
    int y = sensors[i].y;
    int S = sensors[i].S;
    if(x <= S) adj[i].pb(k), adj[k].pb(i);
    if(n - y <= S) adj[i].pb(k+1), adj[k+1].pb(i);
    if(m - x <= S) adj[i].pb(k+2), adj[k+2].pb(i);
    if(y <= S) adj[i].pb(k+3), adj[k+3].pb(i);

     for(int j=0;j<k;j++)
      if(i != j and sensors[i].dist(sensors[j]) <= squared(S + sensors[j].S)) adj[i].pb(j);
  }

  vis.assign(k+10,0);
  bool s1 = solve(k, k+2);

  vis.assign(k+10,0);
  bool s2 = solve(k+1,k+3);

  vis.assign(k+10,0);
  bool s3 = solve(k, k+3);

  vis.assign(k+10,0);
  bool s4 = solve(k+1,k+2);

  if(s1 or s2 or s3 or s4)
    cout << "N" << endl;
  else
    cout << "S" << endl;
  return 0;
}