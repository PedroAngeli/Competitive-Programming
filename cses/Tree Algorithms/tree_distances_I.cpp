#include <bits/stdc++.h>

using namespace std;

const int nax = 2*1e5 + 5;
vector <int> adj[nax];
int n;
int maxlength[nax][2][2];
int maxlengthpai[nax];
int ans[nax];
bool visitado[nax];

void solve(int u){
  visitado[u] = true;

  int firstL = 0;
  int secondL = 0;
  int firstV = -1;
  int secondV = -1;

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];

    if(!visitado[v]){
      solve(v);
      int maior = 1 + max(maxlength[v][0][0],maxlength[v][1][0]);

      if(maior > firstL){
        secondL = firstL;
        secondV = firstV;
        firstL = maior;
        firstV = v;
        continue;
      }

      if(maior > secondL && maior <= firstL){
        secondL = maior;
        secondV = v;
      }
    }
  }

  maxlength[u][0][0] = firstL;
  maxlength[u][0][1] = firstV;
  maxlength[u][1][0] = secondL;
  maxlength[u][1][1] = secondV;
}

void solve2(int u,int p){
  visitado[u] = true;
  
  if(p != -1){
    if(u != maxlength[p][0][1] && maxlength[p][0][1] != -1){
      maxlengthpai[u] = 1 + maxlength[p][0][0];
    }else if(u != maxlength[p][1][1] && maxlength[p][1][0] != -1){
      maxlengthpai[u] = 1 + maxlength[p][1][0];
    }

    maxlengthpai[u] = max(maxlengthpai[u], 1 + maxlengthpai[p]);
  }

  ans[u] = max(max(maxlength[u][0][0],maxlength[u][1][0]),maxlengthpai[u]);

  for(int i=0;i<adj[u].size();i++){
    int v = adj[u][i];

    if(!visitado[v]){
      solve2(v,u);
    }
  }
}

int main(){

  cin >> n;

  for(int i=0;i<n-1;i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  } 

  solve(1);

  memset(visitado,false, sizeof visitado);

  solve2(1,-1);

  for(int i=1;i<=n;i++)
    cout << ans[i] << " ";

  cout << endl;

  return 0;
}