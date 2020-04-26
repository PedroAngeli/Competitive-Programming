#include <bits/stdc++.h>

using namespace std;


int n;
const int nax = 2*1e5 + 5;
const int INF = 1e9 + 7;
vector <int> adj[nax];
vector <int> dist;
int maiorDist;
int vertice;

void bfs(int u){
  dist.assign(n+1,INF);
  queue <int> q;
  q.push(u);
  dist[u] = 0;

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int i=0;i<adj[v].size();i++){
      int w = adj[v][i];

      if(dist[w] == INF){
        q.push(w);
        dist[w] = dist[v] + 1;

        if(dist[w] > maiorDist){
          maiorDist = dist[w];
          vertice = w;
        }
      }
    }
  }
}

int main(){

  cin >> n;

  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1);
  bfs(vertice);

  cout << maiorDist << endl;

  return 0;
}