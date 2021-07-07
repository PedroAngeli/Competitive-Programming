#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m;
  cin >> n >> m;

  vector <vector <char> > grid(n,vector <char>(m));

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> grid[i][j];

  int ans = 0;

  for(int i=0;i<n;i++){
    bool canEat = true;
    for(int j=0;j<m;j++)
      if(grid[i][j] == 'S'){
        canEat = false;
        break;
      }
    if(canEat){
      for(int j=0;j<m;j++){
        ans += (grid[i][j] == '.');
        if(grid[i][j] == '.');
          grid[i][j] = 'x';
      }
    }
  }

  for(int j=0;j<m;j++){
    bool canEat = true;
    for(int i=0;i<n;i++)
      if(grid[i][j] == 'S'){
        canEat = false;
        break;
      }
    if(canEat){
      for(int i=0;i<n;i++){
        ans += (grid[i][j] == '.');
          if(grid[i][j] == '.')
            grid[i][j] = 'x';
      }
    }
  }
  

  cout << ans << endl;
  return 0;
}