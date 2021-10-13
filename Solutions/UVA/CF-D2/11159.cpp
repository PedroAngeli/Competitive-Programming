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

int n,m;
vi adj[100];
vi matchA,matchB;
vector <bool> visB;

bool dfs(int u){
  for(int v:adj[u]){
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
  int max_match = 0;
  matchA.assign(n,-1);
  matchB.assign(m,-1);
  bool flag = true;

  while(flag){
    flag = false;
    visB.assign(m,false);
    for(int i=0;i<n;i++){
      if(matchA[i] != -1)
        continue;
      if(dfs(i)){
        max_match++;
        flag = true;
      }
    }
  }
  return max_match;
}

int main(){
  fastio;

  int t;
  cin >> t;
  int ncase = 0;
  while(t--){
    cin >> n;
    cout << "Case " << ++ncase << ": ";
    vi a(n);

    for(int i=0;i<n;i++)
      adj[i].clear();

    for(int i=0;i<n;i++)
      cin >> a[i];

    cin >> m;
    vi b(m);

    for(int i=0;i<m;i++)
      cin >> b[i];
    
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++){
        if(a[i] == 0){
          if(b[j] == 0)
            adj[i].pb(j);
        }else{
          if(b[j]%a[i] == 0)
            adj[i].pb(j);
        }
      }

      cout << kuhn() << endl;
  }

  return 0;
}