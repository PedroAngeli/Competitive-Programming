#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e2 + 5;
vector <pair <int,int> > adj[nax];
bool visitado[nax];


bool dfs(int u, int v,int c){
  if(u == v){
    return true;
  }

  visitado[u] = true;

  for(int i=0;i<adj[u].size();i++){
    int w = adj[u][i].first;
    int color = adj[u][i].second;

    if(!visitado[w] && color == c){
      if(dfs(w,v,c))
        return true;
    }
  }

  return false;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;

  cin >> n >> m;
  
  while(m--){
    int a,b,c;
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }

  int q;

  cin >> q;

  while(q--){
    int u,v;
    cin >> u >> v;
    int ans = 0;
   
    for(int i=1;i<=100;i++){
      memset(visitado,false, sizeof visitado);
      if(dfs(u,v,i))
        ans++;
    }

    cout << ans << endl;
  }
  

  return 0;
}