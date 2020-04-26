#include <bits/stdc++.h>

using namespace std;

int n,m;
const long long INF = 1000000000000000000LL;
const int nax = 1e5 + 5;
vector <long long> dist;
vector < pair<int,long long> > adj[nax];

void djikstra(){
  dist.assign(n+1,INF);
  set <pair<long long,int> > pq;
  pq.insert({0,1});
  dist[1] = 0;

  while(!pq.empty()){
    int u = pq.begin()->second;
    pq.erase(pq.begin());

    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i].first;
      long long w = adj[u][i].second;

      if(dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        pq.insert({dist[v],v});
      }
    }
  }
}

int main(){

  cin >> n >> m;

  for(int i=0;i<m;i++){
    long long a,b,v;
    cin >> a >> b >> v;
    adj[a].push_back({b,v});
  }

  djikstra();

  for(int i=1;i<=n;i++){
    cout << dist[i] << " ";
  }

  cout << endl;

  return 0;
}