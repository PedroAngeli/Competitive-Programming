#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m,k;
vector <string> grid;
pair <int,int> p;
bool vis[505][505];

bool valid(int i,int j){
  return i>=0 && i < n && j >=0 && j < m && !vis[i][j] && grid[i][j] == '.';
}

void solve(){
  vector <pair <int,pair<int,int>> > dist;
  queue < pair <pair<int,int>, int> > q;
  q.push({{p.first,p.second},0});
  vis[p.first][p.second] = true;
  
  while(!q.empty()){
    pair <int,int> curp = q.front().first;
    int curd = q.front().second;
    q.pop();

    vector <pair<int,int>> mov = {{1,0},{0,1},{-1,0},{0,-1}};

    for(int j=0;j<4;j++){
      int x = curp.first + mov[j].first;
      int y = curp.second + mov[j].second;

      if(valid(x,y)){
        vis[x][y] = true;
        q.push({{x,y},curd+1});
        dist.push_back({curd+1,{x,y}});
      }
    }
  }



  sort(dist.begin(),dist.end());
  reverse(dist.begin(),dist.end());

  for(int i =0;i<k;i++){
    int x = dist[i].second.first;
    int y = dist[i].second.second;
    
    grid[x][y] = 'X';
  }

}


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> k;
  grid.resize(n);

  for(int i=0;i<n;i++)
    cin >> grid[i];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      if(grid[i][j] == '.'){
        p = {i,j};
        i = n;
        break;
      }

  solve();

  for(int i=0;i<n;i++)
    cout << grid[i] << endl;

  return 0;
}