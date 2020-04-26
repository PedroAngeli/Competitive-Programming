#include <bits/stdc++.h>

using namespace std;

int n,m;
const int nax = 1e3 +5;
vector <string> mapa;
bool visitado[nax][nax];
vector <pair <int,int> > bordas; 
vector <int> parent;

bool valid(int i,int j){
  return i >= 0 && i < n && j>=0 && j < m && mapa[i][j] != '#' && !visitado[i][j];
}

void printPath(int u){
  
  if(parent[u] == -1)
    return;

  if(u - parent[u] == 1)
    cout << "L";
  if(u - parent[u] == -1)
    cout << "R";
  if(u - parent[u] == m)
    cout << "U";
  if(u - parent[u] == -m)
    cout << "D";  

  printPath(parent[u]);

}

bool bfs(int si,int sj){
  parent = vector<int> (n*m,-1);
  vector <pair <int,int> > dist;
  queue <pair <int, int> > q;
  vector <int> d(n*m);
  d[si*m + sj] = 0;
  q.push({si,sj});
  int xa,ya;
  bool achou = false;
  bool acheiA = false;

  while(!q.empty() && !acheiA){
    int i = q.front().first;
    int j = q.front().second;
    visitado[i][j] = true;
    vector < pair <int,int> > move({{0,-1},{0,1},{1,0},{-1,0}});
    q.pop();
    
    for(int k=0;k<4;k++){
      int x = i + move[k].first;
      int y = j + move[k].second;

      if(valid(x,y)){
        if(mapa[x][y] == 'A'){
          xa = x;
          ya = y;
          dist.push_back({d[(i*m + j)] + 1,0});
          acheiA = true;
        }else if(mapa[x][y] == 'M' && !achou){
          dist.push_back({d[(i*m + j)] + 1,1});
          achou = true;
          q.push({x,y});
        }else if(mapa[x][y] == '.'){
          q.push({x,y});
        }
        parent[(x*m + y)] = i*m + j;
        d[(x*m + y)] = d[(i*m + j)] + 1; 
      }
    }    
  }

  sort(dist.begin(),dist.end());

  if(dist[0].second == 0){
    cout << "YES" << endl;
    cout << dist[0].first << endl;
    printPath(xa*m + ya);
    cout << endl;

    return true;
  }

  return false;
}

int main(){

  cin >> n >> m;
  mapa.resize(n);
  scanf("%*c");

  for(int i=0;i<n;i++){
    mapa[i].resize(m);
    for(int j=0;j<m;j++){
      scanf("%c",&mapa[i][j]);

      if((i == 0 || j == 0 || j == m-1 || i == n-1) && mapa[i][j]=='.'){
        bordas.push_back({i,j});
      }
    }
  
    scanf("%*c");
  }

  bool ans = false;


  for(int i=0;i<bordas.size();i++){
    
    memset(visitado,false,sizeof(bool)*nax*nax);
    ans = bfs(bordas[i].first,bordas[i].second);

    if(ans)
      break;
  } 

  if(n*m == 1){
    cout << "YES" << endl;
    cout << 0 << endl;
    return 0;
  }

  if(!ans)
    cout << "NO" << endl;

  return 0;
}