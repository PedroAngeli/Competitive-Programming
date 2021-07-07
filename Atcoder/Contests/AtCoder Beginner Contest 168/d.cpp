#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
const int nax = 1e5 + 5;
vector <int> adj[nax];
int ans[nax];


bool bfs(int s){
  queue <int> q;
  q.push(s);
  vector <bool> vis(n+1,false);

  while(!q.empty()){
    int u = q.front();
    q.pop();

    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];
      if(!vis[v]){
        vis[v] = true;
        q.push(v);
        ans[v] = u;
      }
    }
  }

  for(int i=2;i<=n;i++)
    if(ans[i] == 0)
      return false;

  return true;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  while(m--){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  if(!bfs(1)){
    cout << "No" << endl;
    return 0;
  }
  
  cout << "Yes" << endl;

  for(int i=2;i<=n;i++)
    cout << ans[i] << endl;

  return 0;
}