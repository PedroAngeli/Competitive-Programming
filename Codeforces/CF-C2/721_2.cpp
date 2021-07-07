#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int n,m,T;
const int INF = 1e9 + 7;
vector <vector <pair<int,int> > > adj;
vector <vector <int> > dist;
vector <vector <int> > parent;

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m >> T;
 
  adj.resize(n+1);
  dist.assign(n+1,vector <int>(n+1,INF));
  parent.assign(n+1,vector <int>(n+1));

  for(int i=0;i<m;i++){
    int u,v,t;
    cin >> u >> v >> t;
    adj[u].push_back({v,t});
  }

  dist[1][0] = 0;
  set <pair <pair <int,int>,int > > s;
  s.insert({{0,0},1});

  while(!s.empty()){
    auto it = s.begin();
    int u = it->second;
    int qtd = it->first.second;
    s.erase(s.begin());

    for(auto p : adj[u]){
      int v = p.first;
      int t = p.second;
      if(dist[v][qtd+1] > dist[u][qtd]+t){
        dist[v][qtd+1] = dist[u][qtd]+t;
        parent[v][qtd+1] = u;
        s.insert({{dist[v][qtd+1],qtd+1},v});
      }
    }
  }

  int ans;

  for(int i=n;i>=1;i--){
    if(dist[n][i] <= T){
      ans = i;
      break;
    }
  }
  
  cout << ans+1 << endl;

  vector <int> path;
  int qtd = ans;
  int cur = n;

  while(cur != 1){
    path.push_back(cur);
    cur = parent[cur][qtd--];
  }
  path.push_back(1);

  reverse(path.begin(),path.end());

  for(int i=0;i<path.size();i++)
    cout << path[i] << " ";
  cout << endl;
 
  return 0;
}