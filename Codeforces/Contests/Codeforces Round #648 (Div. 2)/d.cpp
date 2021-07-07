#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
bool vis[50][50];
bool reached[50][50];
vector <string> grid;


bool valid(int i,int j){
  return i >=0 && i < n && j >=0 && j < m && !vis[i][j] && grid[i][j] != '#';
}

bool reach(int i, int j){
  memset(vis,false,sizeof vis);
  
  queue <pair <int,int> > q;
  q.push({i,j});
  vis[i][j] = true;
  
  vector <pair <int,int> > mov = {{1,0},{0,1},{-1,0},{0,-1}};

  while(!q.empty()){
    pair <int,int> p = q.front();
    q.pop();

    for(int k=0;k<4;k++){
      int x = p.first + mov[k].first;
      int y = p.second + mov[k].second;

      if(valid(x,y)){
        if(reached[x][y])
          return true;
        vis[x][y] = true;
        q.push({x,y});
      }
    }
  }

  return vis[n-1][m-1];
}

void solve(){
  memset(reached,false,sizeof reached);
  vector <pair <int,int> > posG;
  vector <pair <int, int> > posB;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      if(grid[i][j] == 'G')
        posG.push_back({i,j});
      if(grid[i][j] == 'B')
        posB.push_back({i,j});
    }

    bool can = true;

    for(int i=0;i<posB.size();i++){
      int x = posB[i].first;
      int y = posB[i].second;
      if(x+1 < n){
         if(grid[x+1][y] == '.')
            grid[x+1][y] = '#';
         else if(grid[x+1][y] == 'G'){
           can = false;
           break;
         }
      }
       
      if(y+1 < m){
        if(grid[x][y+1] == '.')
          grid[x][y+1] = '#';
        else if(grid[x][y+1] == 'G'){
          can = false;
          break;
        }
      }

      if(x-1 >= 0){
        if(grid[x-1][y] == '.'){
          grid[x-1][y] = '#';
        }else if(grid[x-1][y] == 'G'){
          can = false;
          break;
        }
      }
      if(y-1 >= 0){
        if(grid[x][y-1] == '.')
          grid[x][y-1] = '#';
        else if(grid[x][y-1] == 'G'){
          can = false;
          break;
        }
      }
    }

    if(can){
        for(int i=0;i<posG.size();i++){
        int x = posG[i].first;
        int y = posG[i].second;
        if(!reach(x,y)){
          can = false;
          break;
        }else{
          reached[x][y] = true;
        }
      }
    }
    

    if(can)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    cin >> n >> m;
    grid.resize(n);
    for(int i=0;i<n;i++)
      cin >> grid[i];

    solve();
  }

  return 0;
}