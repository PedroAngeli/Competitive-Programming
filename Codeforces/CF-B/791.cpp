#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n,m;
const int nax = 15*1e4 + 5;
vector <int> adj[nax];
bool visitado[nax];
long long numV, numA;

void dfs(int u){
  visitado[u] = true;
  numV++;

  for(int i =0;i<adj[u].size();i++){
    int v = adj[u][i];
    numA++;
    if(!visitado[v]){
      dfs(v);
    }
  }
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

  bool yes = true;

  for(int i=1;i<=n;i++){
    numV = 0;
    numA = 0;

    if(!visitado[i]){
        dfs(i);
        numA /= 2;
        if((numV*(numV-1))/2 > numA){
        yes = false;
        break;
      }
    }
  }

  if(yes)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}