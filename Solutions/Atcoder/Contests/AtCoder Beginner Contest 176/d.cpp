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
vector <vi> magics;
int H,W;
const int INF = 1e9 + 7;

bool valid(int i,int j){
  return i >= 0 && i < H && j >= 0 && j < W  && grid[i][j] == '.';
}
 
int main(){
  fastio;
 
  cin >> H >> W;
 
  int Ch,Cw;
  cin >> Ch >> Cw;
  int Dh, Dw;
  cin >> Dh >> Dw;
  Ch--, Cw--, Dh--, Dw--;
 
  grid.resize(H);
  magics.assign(H,vi(W,INF));
 
  for(int i=0;i<H;i++)
    cin >> grid[i];
 
  queue <pii> q;
  magics[Ch][Cw] = 0;
  q.push({Ch,Cw});

  int ans = INF;

  while(true){
    vpii vis;

     while(!q.empty()){
      int x = q.front().f;
      int y = q.front().s;
      vis.pb({x,y});
      q.pop();
  
      vpii mov = {{0,1},{0,-1},{1,0},{-1,0}};
  
      for(int k=0;k<4;k++){
        int i = x + mov[k].f;
        int j = y + mov[k].s;
  
        if(valid(i,j) && magics[i][j] > magics[x][y]){
          magics[i][j] = magics[x][y];
          q.push({i,j});
        }
      } 
    }

    ans = magics[Dh][Dw];
 
    if(ans == INF)
      ans = -1;

    if(ans != -1)
      break;

    bool can = false;

    for(auto p:vis){
      int x = p.f;
      int y = p.s;
      for(int k=-2;k<=2;k++)
      for(int l=-2;l<=2;l++){
        int i = x + k;
        int j = y + l;
        if(valid(i,j) && magics[i][j] > magics[x][y] + 1){
          magics[i][j] = magics[x][y] + 1;
          q.push({i,j});
          can = true;
        }
      }
    }

    if(!can)
      break;
  }
 
  
  cout << ans << endl;
  
  return 0;
}