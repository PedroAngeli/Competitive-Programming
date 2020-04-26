#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e2 + 5;
bool visitado[nax];
vector <int> adj[nax];
vector <int> topo;

void solve(int u){
  visitado[u] = true;

  for(int v : adj[u]){
    if(visitado[v] == false)
      solve(v);
  }

  topo.push_back(u);
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;

  while(cin >> n >> m && n){
    topo.clear();
    memset(visitado,false,sizeof visitado);
    for(int i=1;i<=n;i++)
      adj[i].clear();

      for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
      }

    for(int i=1;i<=n;i++){
      if(visitado[i] == false)
        solve(i);
    }

    reverse(topo.begin(),topo.end());

    for(int i=0;i<topo.size();i++){
      if(i == topo.size()-1)
        cout << topo[i] << endl;
      else
        cout << topo[i] << " ";
    }
  }

 

  return 0; 
}