#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
vector <int> adj[105];
vector <int> color;
const int UNCOLOR = 1e9 + 7;

int solve(int u){
  color[u] = 1;
  queue <int> q;
  q.push(u);

  while(!q.empty()){
    int v = q.front();
    q.pop();

    for(int w : adj[v]){
      if(color[w] == UNCOLOR){
        q.push(w);
        color[w] = 1 - color[v];
      }else if(color[w] == color[v]){
        return 1;
      }
    }
  }

  return 0;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i=0;i<m;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  color.assign(n+1,UNCOLOR);

  int ans = 0;
  for(int i=1;i<=n;i++){
    if(color[i] == UNCOLOR){
      ans += solve(i);
    }
  }

  if((n - ans) % 2 == 1)
    ans++;

  cout << ans << endl;

  
  return 0;
}