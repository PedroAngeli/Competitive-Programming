#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005
#define INF -1

vector < pair<int,int> > edges;
vector <int> adj[MAXN];
int color[MAXN];

bool bipartite(int s){
  queue <int> q;
  q.push(s);
  color[s] = 0;
  bool isBipartite = true;

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int j=0;j<adj[u].size();j++){
      int v = adj[u][j];

      if(color[v] == INF){
        color[v] = 1 - color[u];
        q.push(v);
      }
      else if(color[v] == color[u]){
        isBipartite = false;
        break;
      }
    }
  }

  return isBipartite;
}

int main(){
  int n,m;

  scanf("%d %d",&n,&m);

  memset(color, INF,(n+1)*(sizeof (int)));

  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d",&u,&v);

    edges.push_back({u,v});
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(!bipartite(1)){
    printf("NO\n");
  }
  else{
    printf("YES\n");

    for(int i=0;i<m;i++){
      int u = edges[i].first;

      printf("%d",1-color[u]);
    }

    printf("\n");

  }

  return 0;
}