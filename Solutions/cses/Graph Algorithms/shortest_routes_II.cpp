#include <bits/stdc++.h>

using namespace std;

int n,m,q;
const long long INF = 1000000000000000000LL;
const int nax = 505;
long long dist[nax][nax];

int main(){

  cin >> n >> m >> q;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(i != j)
        dist[i][j] = INF;
    }
  }

  for(int i=0;i<m;i++){
    long long a,b,v;
    cin >> a >> b >> v;
    dist[a][b] = min(dist[a][b],v);
    dist[b][a] = min(dist[b][a],v);
  }

  for(int k = 1; k <= n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }

  for(int i=0;i<q;i++){
    int u,v;
    cin >> u >> v;
    if(dist[u][v] == INF)
      cout << "-1\n";
    else
      cout << dist[u][v] << endl;
  }

  return 0;
}