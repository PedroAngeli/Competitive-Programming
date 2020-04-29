#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e5 + 5;
vector <int> adj[nax];
int hasCat[nax];
bool vis[nax];
int n,m;
int ans;

void solve(int u,int consecutives){
  vis[u] = true;
  
  if(hasCat[u])
    consecutives++;
  else
    consecutives = 0;
  
  if(consecutives > m)
    return;

  bool isLeaf = true;

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];
    if(!vis[v]){
      isLeaf = false;
      solve(v,consecutives);
    }
  }

  if(isLeaf)
    ans++;
}


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for(int i=1;i<=n;i++)
    cin >> hasCat[i];

  for(int i = 0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  solve(1,0);
  cout << ans << endl;

  return 0;
}