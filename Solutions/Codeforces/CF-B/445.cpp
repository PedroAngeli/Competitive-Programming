#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 55;
vector <int> adj[nax];
bool visitado[nax];
int cnt;

void dfs(int u){
  visitado[u] = true;
  cnt++;

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];
    if(!visitado[v]){
      dfs(v);
    }
  }
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;

  cin >> n >> m;

  long long ans = 1;

  while(m--){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i=1;i<=n;i++){
    cnt = 0;
    if(!visitado[i])
      dfs(i);
    if(cnt)
      ans *= pow(2,cnt-1);
  }

  cout << ans << endl;

  return 0;
}