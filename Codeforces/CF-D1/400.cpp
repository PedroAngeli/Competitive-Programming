#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

const int nax = 1e5 + 5;
vi adj[nax];
vector <bool> visited;
const int INF = 1e9 + 7;
vi type;

void solve(int u,int& vis,int t){
  if(t == type[u])
    vis++;
  visited[u]=true;
  for(int v:adj[u])
    if(!visited[v])
      solve(v,vis,t);
  if(type[u] != t)
    visited[u]=false;
}
int main(){
  fastio;

  int n,m,K;
  cin >> n >> m >> K;

  vector <vi> ans(K+1,vi(K+1,INF));
  visited.assign(n+1,false);
  type.resize(n+1); //type of node
  vpii typeRange(K+1); //first node and length of the type
  int pref = 0;

  for(int i=1;i<=K;i++){
    int c;
    cin >> c;
    int l = pref+1;
    int r = pref+c;
    typeRange[i] = {l,r-l+1};
    pref += c;
    while(l <= r)
      type[l] = i,l++; 
  }

  for(int i=0;i<m;i++){
    int u,v,x;
    cin >> u >> v >> x;

    if(type[u] == type[v] && x != 0)
      continue;
    
    if(type[u] == type[v]){
      adj[u].push_back(v);
      adj[v].push_back(u);
      continue;
    }

    if(type[u] != type[v] && x == 0){
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    ans[type[u]][type[v]] = min(ans[type[u]][type[v]],x);
    ans[type[v]][type[u]] = min(ans[type[v]][type[u]],x);
  }

  for(int i=1;i<=K;i++){
    int vis = 0;
    solve(typeRange[i].f,vis,i);
    if(vis != typeRange[i].s){
      cout << "No" << endl;
      return 0;
    }
  }


  for(int i=1;i<=K;i++)
    ans[i][i] = 0;
  
  for(int k=1;k<=K;k++)
    for(int i=1;i<=K;i++)
      for(int j=1;j<=K;j++)
        ans[i][j] = min(ans[i][j],ans[i][k] + ans[k][j]);


  cout << "Yes" << endl;
  for(int i=1;i<=K;i++){
    for(int j=1;j<=K;j++){
      if(ans[i][j] == INF)
        cout << -1 << " ";
      else
        cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}