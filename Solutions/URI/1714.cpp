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
int n;
vs grid;

bool valid(int i,int j){
  return i>=0 && i < n && j >=0 && j < n;
}

bool validChar(char c,int mask){
  int letter;

  if(isupper(c)){
    letter = c-'A';
    return (mask & (1 << letter)) == 0;
  }
  
    letter = c-'a';
    return (mask & (1 << letter));
}

int solve(int mask){
  if(!validChar(grid[0][0],mask))
    return INF;

  priority_queue <pair<int,pii>,vector<pair<int,pii>>,greater <pair<int,pii>> > pq;
  pq.push({0,{0,0}});
  vector <vi> dist(n,vi(n,INF));
  dist[0][0] = 0;

  while(!pq.empty()){
    auto p = pq.top();
    pq.pop();
    int x = p.s.f;
    int y = p.s.s;

    vpii mov = {{1,0},{-1,0},{0,1},{0,-1}};

    for(int k=0;k<4;k++){
      int i = x + mov[k].f;
      int j = y + mov[k].s;

      if(!valid(i,j))
        continue;
      
      if(!validChar(grid[i][j],mask))
        continue;
      
      if(dist[i][j] > dist[x][y] + 1){
        dist[i][j] = dist[x][y] + 1;
        pq.push({dist[i][j],{i,j}});
      }
    }
  }

  return dist[n-1][n-1];
}

int main(){
  fastio;

  cin >> n;

  grid.resize(n);

  for(int i=0;i<n;i++)
    cin >> grid[i];
  
  int ans = INF;

  for(int mask=0;mask<1024;mask++){
    ans = min(ans,solve(mask));
  }

  if(ans == INF)
    ans = -1;
  else
    ans++;

  cout << ans << endl;
  

  return 0;
}