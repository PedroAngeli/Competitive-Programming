#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int nax = 2e4;
const int INF = 1e9 + 7;
vector <pair <int,int> > adj[nax];
vector <int> dist;
int n,m,s,t;

void solve(){
  set <pair <int,int> > q;
  dist[s] = 0;
  q.insert({0,s});

  while(!q.empty()){
    auto it = q.begin();
    int u = it->second;
    q.erase(q.begin());

    for(pair<int,int> p : adj[u]){
      int v = p.first;
      int w = p.second;
      if(dist[v] > dist[u] + w){
        dist[v] = dist[u] + w;
        q.insert({dist[v],v});
      }
    }
  }
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int T;
  cin >> T;
  int ncase = 1;
  while(T--){
    cout << "Case #" << ncase++ << ": ";
    cin >> n >> m >> s >> t;
    for(int i=0;i<n;i++)
      adj[i].clear();
    
    dist.assign(n,INF);

    int u,v,w;
    for(int i=0;i<m;i++){
      cin >> u >> v >> w;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
    }

    solve();

    if(dist[t] == INF)
      cout << "unreachable" << endl;
    else
      cout << dist[t] << endl;
  }
  
  return 0;
}