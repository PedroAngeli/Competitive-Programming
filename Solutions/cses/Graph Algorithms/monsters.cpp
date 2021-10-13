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

const int INF = 1e9 + 7;
const int nax = 1000;
int n,m;
vs grid;
pii parent[nax][nax];

bool valid(int i,int j){
  return i>=0 && i < n && j >=0 && j < m && grid[i][j] != '#';
}

vector <vi> bfs(vpii& sources){
  vector <vi> dist(n,vi(m,INF));
  queue <pii> q;
  for(auto p:sources)
    dist[p.f][p.s] = 0,q.push(p);

  vpii mov = {{0,-1},{0,1},{1,0},{-1,0}};

  while(!q.empty()){
    auto p = q.front();
    q.pop();
    int x = p.f;
    int y = p.s;

    for(auto k : mov){
      int i = x + k.f;
      int j = y + k.s;
      if(valid(i,j) && dist[i][j] > dist[x][y] + 1){
        dist[i][j] = dist[x][y] + 1;
        q.push({i,j});
        parent[i][j] = {x,y};
      }
    }
  }


  return dist;
}

void printPath(int i,int j){
  string ans;
  while(true){
    auto p = parent[i][j];
    if(p.f == -1)
      break;
    if(p.s < j)
      ans += "R";
    if(p.s > j)
      ans += "L";
     if(p.f > i)
      ans += "U";
    if(p.f < i)
      ans += "D";
    i = p.f;
    j = p.s;
  }

  reverse(all(ans));
  cout << sz(ans) << endl;
  cout << ans << endl;
}

int main(){
  fastio;
  
  cin >> n >> m;
  grid.resize(n);

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      parent[i][j] = {-1,-1};

  for(int i=0;i<n;i++)
    cin >> grid[i];
  
  vpii monsters;
  vpii man;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(grid[i][j] == 'M')
        monsters.pb({i,j});
      else if(grid[i][j] == 'A')
        man.pb({i,j});
  
  auto distMonsters = bfs(monsters);
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      parent[i][j] = {-1,-1};
  auto distMan = bfs(man);

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(i == 0 || j == 0 || i == n-1 || j == m-1){
        if(distMonsters[i][j] > distMan[i][j]){
          cout << "YES" << endl;
          printPath(i,j);
          return 0;
        }
      } 
  cout << "NO" << endl;
  return 0;
}