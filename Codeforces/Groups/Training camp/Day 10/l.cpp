#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
const int nax = 1e5 + 5;
int hasCat[nax];
bool vis[nax];
int n,m;
vector <int> adj[nax];
int ans;

void solve(int u,int cats){
  vis[u] = true;

  if(hasCat[u])
    cats++;
  else
    cats = 0;
  
  if(cats > m)
    return;

  bool isLeaf = true;
  
  for(int v:adj[u])
    if(!vis[v]){
      isLeaf = false;
      solve(v,cats);
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
  
  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve(1,0);

  cout << ans << endl;
  
  return 0;
}