#include <bits/stdc++.h>

using namespace std;

const int nax = 1e5 + 5;
const int INF = 1e9 + 7;

vector <int> adj[nax];
vector <int> ans;


bool bipartite(int v){

  queue <int> q;
  q.push(v);
  ans[v] = 1;

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int i=0;i<adj[u].size();i++){
      int w = adj[u][i];

      if(ans[w] == INF){
        q.push(w);
        ans[w] = 1 - ans[u];
      }else if(ans[w] == ans[u]){
        return false;
      }
    }
  }

  return true;
}

int main(){
  int n,m;

  cin >> n >> m;

  ans.assign(n+1,INF);
  
  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i=1;i<=n;i++){
    if(ans[i] == INF){
      if(!bipartite(i)){
        cout << "IMPOSSIBLE\n";
        return 0;
      }
    }
      
  }

  for(int i=1;i<=n;i++){
    cout << ans[i]+1 << " ";
  }

  cout << endl;

  return 0;
}