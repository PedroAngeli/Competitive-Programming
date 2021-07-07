#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define debug(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " << endl

using ld = long double;
using ll = long long;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vpii = vector <pii>;
using vpll = vector<pll>;
using vs = vector <string>;

int n,m,k;
vi adj[205];
vi matchA,matchB;
vector <bool> visB;

bool dfs(int u){
  for(int v : adj[u]){
    if(visB[v])
      continue;
    visB[v] = true;
    if(matchB[v] == -1 || dfs(matchB[v])){
      matchA[u] = v;
      matchB[v] = u;
      return true;
    }
  }

  return false;
}

int kuhn(){
  matchA.assign(n,-1);
  matchB.assign(m,-1);
  bool flag = true;
  int matched = 0;

  while(flag){
    flag = false;
    visB.assign(m,false);
    for(int i=0;i<n;i++){
      if(matchA[i] != -1)
        continue;
      if(dfs(i)){
        matched++;
        flag = true;
      }
    }
  }

  return matched;
}

int main(){
  fastio;

  while(cin >> n >> m >> k){
    if(n == 0)
      break;
    for(int i=0;i<n;i++)
      adj[i].clear();

    for(int i=0;i<k;i++){
      int id,u,v;
      cin >> id >> u >> v;
      if(u == 0 || v == 0)
        continue;
      adj[u].pb(v);
    }

    cout << kuhn() << endl;
  }

  return 0;
}