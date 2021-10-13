#include <bits/stdc++.h>

using namespace std;

vector <string> grid;
int n,m;
int sx,sy;
int dx, dy;
bool visitado[1001][1001];
int dist[1000005];
int parent[1000005];

bool valid(int i,int j){
  return i>=0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && !visitado[i][j];
}

int idx(int i, int j){
  return i*m + j;
}

int bfs(){
  queue < pair <int, int> > q;
  dist[idx(sx,sy)] = 0;
  q.push({sx,sy});
  visitado[sx][sy] = true;

  while(!q.empty()){
    pair <int, int> p = q.front();
    q.pop();

    vector < pair <int ,int> > mov = {{1,0},{-1,0},{0,1},{0,-1}};

    for(int k=0;k<4;k++){
      int x = p.first;
      int y = p.second;
      int i = x + mov[k].first;
      int j = y + mov[k].second;

      if(valid(i,j)){
        visitado[i][j] = true;
        q.push({i,j});
        dist[idx(i,j)] = dist[idx(x,y)] + 1;
        parent[idx(i,j)] = idx(x,y);
      }
    }
  }

  return dist[idx(dx,dy)];
}

void printPath(int idx){
  
  if(parent[idx] == -1){
    return;
  }

  printPath(parent[idx]);

  if(parent[idx] + 1 == idx){
    cout << "R";
  }else if(parent[idx] - 1 == idx){
    cout << "L";
  }else if(parent[idx] > idx){
    cout << "U";
  }else{
    cout << "D";
  }
}

int main(){

  cin >> n >> m;

  grid = vector <string> (n);

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      grid[i].resize(m);
      cin >> grid[i][j];
      if(grid[i][j] == 'A'){
        sx = i;
        sy = j;
      }

      if(grid[i][j] == 'B'){
        dx = i;
        dy = j;
      }
    }
  }

  memset(dist, -1, sizeof dist);
  memset(parent, -1, sizeof parent);

  int ans = bfs();


  if(ans == -1){
    cout << "NO\n";
  }else{
    cout << "YES\n" << ans << "\n";
    printPath(idx(dx,dy));
    cout << endl;
  }

  return 0;
}