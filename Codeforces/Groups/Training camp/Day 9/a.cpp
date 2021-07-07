#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
const int nax = 1e5 + 5;
vector <int> adj[nax];
int even[nax];
int odd[nax];
int sufOdd[nax];
int sufEven[nax];
bool vis[nax];
int height[nax];

void solve(int u,int h){
  vis[u] = true;
  if(h % 2 == 0)
    even[h]++;
  else
    odd[h]++;
  height[u] = h;

  for(int v:adj[u]){
    if(!vis[v])
      solve(v,h+1);
  }
}
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n;
  cin >> n;

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve(1,1);

  sufOdd[n] = odd[n];
  for(int i=n-1;i>=1;i--)
    sufOdd[i] = sufOdd[i+1]+odd[i];

  sufEven[n] = even[n];
  for(int i=n-1;i>=1;i--)
    sufEven[i] = sufEven[i+1]+even[i];

  // for(int i=1;i<=n;i++)
  //   cout << sufEven[i] << " ";
  // cout << endl;

  // for(int i=1;i<=n;i++)
  //   cout << sufOdd[i] << " ";
  // cout << endl;

  // for(int i=1;i<=n;i++)
  //   cout << height[i] << " ";
  // cout << endl;

  int ans = 0;

  for(int i=1;i<=n;i++){
    if(i == 1){
      ans += max(0,sufEven[1]-(int)adj[i].size());
      continue;
    }
    if(height[i] % 2 == 0){
      ans += max(0,sufOdd[height[i]]-(int)adj[i].size()+1);
    }else{
      ans += max(0,sufEven[height[i]]-(int)adj[i].size()+1);
    }
  }


  cout << ans << endl;
  
  return 0;
}