#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n;
const int nax = 1e5 + 5;
vector <int> adj[nax];
bool vis[nax];
int init[nax];
int goal[nax];
int ans;
vector <int> nodes;

void solve(int u, int h,int e, int o){
  vis[u] = true;

  int cur = init[u];

  if(h % 2 == 0){
    cur = (cur + e)%2;
    if(cur != goal[u])
      ans++,e++,nodes.push_back(u);
  }else{
    cur = (cur + o)%2;
    if(cur != goal[u])
      ans++,o++,nodes.push_back(u);
  }

  for(int v : adj[u]){
    if(!vis[v]){
      solve(v,h+1,e,o);
    }
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  for(int i=1;i<=n;i++)
    cin >> init[i];

   for(int i=1;i<=n;i++)
    cin >> goal[i];

  solve(1,0,0,0);

  cout << ans << endl;

  for(int i=0;i<ans;i++)
    cout << nodes[i] << endl;

  return 0;
}