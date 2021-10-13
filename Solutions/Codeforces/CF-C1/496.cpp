#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector <string> grid;
int n,m;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  grid.resize(n);

  for(int i=0;i<n;i++)
    cin >> grid[i];

  int ans =0;
  bool removed[m]= {false};
  for(int i=0;i<m;i++){
    for(int j=0;j<n-1;j++){
      if(grid[j][i] > grid[j+1][i]){
        bool remove = true;
        for(int k=0;k<i;k++){
          if(removed[k])
            continue;
          if(grid[j+1][k] > grid[j][k]){
            remove = false;
            break;
          }else if(grid[j+1][k] < grid[j][k])
            break;
        }
          if(remove){
            removed[i] = true;
            ans++;
            j = n;
          }
      }
    }
  }
    

  cout << ans << endl;

  return 0;
}