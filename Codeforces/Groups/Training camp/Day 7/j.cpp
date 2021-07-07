#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int nax = 5005;
vector <pair <int,int> > adj[nax];
int n,m,t;
int dist[nax][nax];
int INF = 1e9 + 7;
int parent[nax][nax];

void solve(){
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dist[i][j] = INF;

  for(int i=0;i<=n;i++)
    dist[1][i] = 0;

  set <pair <int,pair <int,int> > > pq;
  pq.insert({0,{1,0}});

  while(!pq.empty()){
    auto it = pq.begin();
    int u = it->second.first;
    int qtd = it->second.second;
    pq.erase(it);

    for(auto p:adj[u]){
      int v = p.first;
      int w = p.second;

      if(dist[v][qtd+1] > dist[u][qtd] + w){
        dist[v][qtd+1] = dist[u][qtd] + w;
        parent[v][qtd+1] = u;
        pq.insert({dist[v][qtd+1],{v,qtd+1}});
      }
    }
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  cin >> n >> m >> t;
  for(int i=0;i<m;i++){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }

  solve();

  int ans = 0;

  for(int i=n;i>=1;i--){
    if(dist[n][i] <= t){
      ans = i;
      break;
    }
  }
  vector <int> path;
  cout << ans+1 << endl;

  int u = n;
  while(u != 1){
    path.push_back(u);
    u = parent[u][ans--];
  }

  path.push_back(1);
  reverse(path.begin(),path.end());

  for(int i=0;i<path.size();i++)
    cout << path[i] << " ";

  cout << endl; 
  
  return 0;
}