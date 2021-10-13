#include <bits/stdc++.h>

using namespace std;

int n,m;
const int nax = 1e3 +5;
vector <string> mapa;
bool visitado[nax][nax];

bool valid(int i,int j){
  return i >= 0 && i < n && j>=0 && j < m && mapa[i][j] != '#' && !visitado[i][j];
}

int solve(int i,int j){
  int sum = 1;

  visitado[i][j] = true;

  if(valid(i,j+1)){
    sum += solve(i,j+1);  
  }

  if(valid(i,j-1)){
    sum += solve(i,j-1);
  }

  if(valid(i+1,j)){
    sum += solve(i+1,j);
  }

  if(valid(i-1,j)){
    sum += solve(i-1,j);
  }

  return sum;
}

int main(){

  cin >> n >> m;
  mapa.resize(n);
  
  for(int i=0;i<n;i++){
    cin >> mapa[i];
  }

  int ans = 0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!visitado[i][j] && mapa[i][j] != '#'){
          if(solve(i,j))
            ans += 1;
      }
    }
  }

  cout << ans << endl;

  return 0;
}