#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

vs grid;
vector <vpii> Left;
vector <vpii> Right;
vector <vpii> up;
vector <vpii> down;
const int INF = 1e9 + 7;
int n,m;
queue <pii> q;
vector <vi> dist;
vector <vpii> parent;
pii neutral;

bool clean(int i,int j){
  return grid[i][j] == 'S' || grid[i][j] == 'E' || grid[i][j] == '.';
}

bool valid(int i,int j){
  return i >= 0 && i < n && j >= 0 && j < m && clean(i,j);
}

void push_queue(pii l,int x,int y){
  if(valid(l.f,l.s) && dist[l.f][l.s] > dist[x][y] + 1){
      dist[l.f][l.s] = dist[x][y] + 1;
      parent[l.f][l.s] = {x,y};
      q.push(l);
    }
}

void printh_path(pii pos){
  string path = "";

  while(true){
    pii p = parent[pos.f][pos.s];
    if(p == neutral)
      break;
    if(p.f == pos.f){
      if(p.s < pos.s)
        path += "R";
      else
        path += "L";
    }else{
      if(p.f < pos.f)
        path += "D";
      else
        path += "U";
    }
    pos = p;
  }
  reverse(all(path));
  cout << path << endl;
}

int main(){
  fastio;
  cin >> n >> m;
  grid.resize(n);

  for(int i=0;i<n;i++)
    cin >> grid[i];

  neutral = {-1,-1};
  
  parent.assign(n,vpii(m,neutral));
  Left.assign(n,vpii(m,neutral));
  Right.assign(n,vpii(m,neutral));
  up.assign(n,vpii(m,neutral));
  down.assign(n,vpii(m,neutral));

  for(int i=0;i<n;i++)
    for(int j=1;j<m;j++)
      if(clean(i,j-1))
        Left[i][j] = {i,j-1};
      else
        Left[i][j] = Left[i][j-1];
  
  for(int i=0;i<n;i++)
    for(int j=m-2;j>=0;j--)
       if(clean(i,j+1))
        Right[i][j] = {i,j+1};
      else
        Right[i][j] = Right[i][j+1];

  for(int i=1;i<n;i++)
    for(int j=0;j<m;j++)
       if(clean(i-1,j))
        up[i][j] = {i-1,j};
      else
        up[i][j] = up[i-1][j];

  for(int i=n-2;i>=0;i--)
    for(int j=0;j<m;j++)
       if(clean(i+1,j))
        down[i][j] = {i+1,j};
      else
        down[i][j] = down[i+1][j];
    
  pii ini;
  pii dest;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(grid[i][j] == 'S')
        ini = {i,j};
      else if(grid[i][j] == 'E')
        dest = {i,j};
  dist.assign(n,vi(m,INF));
  q.push(ini);
  dist[ini.f][ini.s] = 0;

  while(!q.empty()){
    auto p = q.front();
    q.pop();
    int x = p.f;
    int y = p.s;

    pii d  = down[x][y];
    pii l  = Left[x][y];
    pii r  = Right[x][y];
    pii u  = up[x][y];
    push_queue(d,x,y);
    push_queue(l,x,y);
    push_queue(r,x,y);
    push_queue(u,x,y); 
  }
  
  int ans = dist[dest.f][dest.s];

  if(ans == INF){
    cout << -1 << endl;
    return 0;
  }

  cout << ans << endl;
  printh_path(dest);
  return 0;
}