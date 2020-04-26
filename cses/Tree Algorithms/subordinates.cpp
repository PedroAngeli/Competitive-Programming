#include <bits/stdc++.h>

using namespace std;


int n;
const int nax = 2*1e5 + 5;
vector <int> adj[nax];
int ans[nax];
bool visitado[nax];

int solve(int v){
  visitado[v] = true;

  int employee = 0;

  for(int i=0;i<adj[v].size();i++){
    int u = adj[v][i];

    if(!visitado[u]){
      employee += solve(u);
    }
  }

  ans[v] = employee;

  return ans[v] + 1 ;
}

int main(){

  cin >> n;

  for(int i=2;i<=n;i++){
    int a;
    cin >> a;
    adj[a].push_back(i);
  }
    

  solve(1);

 for(int i=1;i<=n;i++){
    cout << ans[i] << " ";
  }

  cout << endl;
    

  return 0;
}