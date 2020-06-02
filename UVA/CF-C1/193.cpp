#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e2 + 5;
vector <int> adj[nax];
vector <int> ans;
int color[nax];
int n,m;
int mx;

void solve(int u){
  if(u > n){
    int cnt = 0;

    for(int i=1;i<=n;i++)
      if(color[i] == 1)
        cnt++;
    
    if(cnt > mx){
      mx = cnt;
      ans.clear();
      for(int i=1;i<=n;i++)
        if(color[i] == 1)
          ans.push_back(i);
    }

    return;
  }

  bool black = true;

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];

    if(color[v] != -1 && color[v] == 1){
      black = false;
      break;
    }
  }

  if(black){
    color[u] = 1;
    solve(u+1);
  }

  color[u] = 0;
  solve(u+1);

  color[u] = -1;
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    cin >> n >> m;

    for(int i=1;i<=n;i++)
      adj[i].clear();
    
    memset(color, -1, sizeof color);
    ans.clear();
    mx = 0;
    
    for(int i=0;i<m;i++){
      int a,b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    solve(1);
    
    cout << mx << endl;

    int len = ans.size();

    for(int i=0;i<len;i++)
      if(i == len-1)
        cout << ans[i] << endl;
      else
        cout << ans[i] << " ";
  }
  
  
  return 0;
}