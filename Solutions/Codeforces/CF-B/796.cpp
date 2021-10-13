#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,k;
  bool hole[n+1] = {false};
  int cup = 1;

  cin >> n >> m >> k;

  for(int i=0;i<m;i++){
    int h;
    cin >> h;
    hole[h] = true;
  }

  while(k--){
    int u,v;
    cin >> u >> v;

    if(cup == u){
      if(!hole[u])
        cup = v;
      else
        break;
    }
    else if(cup == v){
      if(!hole[v])
      cup = u;
      else
        break;
    }
      
  }

  cout << cup << endl;
  
  return 0;
}