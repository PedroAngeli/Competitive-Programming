#include <bits/stdc++.h>

using namespace std;


int n;
const int nax = 2*1e5 + 5;
const int INF = 1e9 + 7;
vector <int> adj[nax];
int dp[nax][2];
bool visitado[nax];

//dp[no][0] - maximo entre não incluir nó atual e algum de seus filhos
//dp[no][1] - maximo entre incluir atual e algum de seus filhos
//Caso base - dp[folha][0] = dp[folha][1] = 0
//dp[no][0] --> dp[no][0] += max(dp[filhos][0],dp[filhos][1])
//dp[no][1] --> dp[no][1] = max(dp[no][1], 1 + dp[no][0] - max(dp[filhos][0],dp[filhos][1]) + dp[filhos][0])

void solve(int u){
  visitado[u] = true;

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];

    if(!visitado[v]){
      solve(v);
      dp[u][0] += max(dp[v][0],dp[v][1]);
    }
  }

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];

    if(!visitado[v])
      dp[u][1] = max(dp[u][1],1 + dp[u][0] - max(dp[v][0],dp[v][1]) + dp[v][0]);
  }

  visitado[u] = false;
}

int main(){

  cin >> n;

  for(int i=0;i<n-1;i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  solve(1);

  cout << max(dp[1][0],dp[1][1]) << endl;

  return 0;
}