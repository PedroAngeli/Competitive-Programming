#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;
vector <pair <int,int> > adj[nax];
vector <int> dist;
const int INF = 1e9 + 7;

int bfs(int s){
  dist.assign(nax,INF);
  dist[s] = 0;
  queue <int> q;
  q.push(s);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(pair <int,int> p : adj[u]){
      int v = p.first;
      int w = p.second;
      if(dist[v] == INF){
        dist[v] = w + dist[u];
        q.push(v);
      }
    }
  }

  int mxD = 0;
  int mxV;
  
  for(int i=1;i<nax;i++)
    if(mxD < dist[i] && dist[i] != INF){
      mxD = dist[i];
      mxV = i;
    }

  return mxV;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  string line;

  while(getline(cin,line)){
    if(line.size() == 0){
      int v = bfs(bfs(1));
      cout << dist[v] << endl;

      for(int i=0;i<nax;i++)
        adj[i].clear();
      continue;
    }

    istringstream s(line);
    int u,v,w;

    while(s >> u >> v >> w){
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }
  }

  int v = bfs(bfs(1));
  cout << dist[v] << endl;

  return 0;
}