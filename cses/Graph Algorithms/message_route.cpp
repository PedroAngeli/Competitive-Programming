#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;
const int INF = 1e9 + 7;
int n,m;

vector <int> adj[nax];
vector <int> dist;
int parent[nax];

void bfs(int s){
  dist.assign(nax, INF);
  dist[s] = 0;
  queue <int> q;
  q.push(s);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int i=0;i<adj[u].size();i++){
      int v= adj[u][i];

      if(dist[v] == INF){
        dist[v] = dist[u] + 1;
        parent[v] = u;
        q.push(v);
      }
    }
  }
}

void printPath(int u){
  if(u == -1){
    return;
  }

  printPath(parent[u]);
  cout << u << " ";
}

int main(){

  cin >> n >> m;
  memset(parent, -1, sizeof(int) * nax);

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1);

  if(dist[n] == INF){
    cout << "IMPOSSIBLE" << endl;
  }else{
    cout << dist[n] + 1 << endl;
    printPath(n);
    cout << endl;
  }


  return 0;
}