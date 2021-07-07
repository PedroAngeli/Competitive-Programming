#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
   int t;
   cin >> t;
   while(t--){
     int n,m,x,y;
     cin >> n  >> m >> x >> y;
     vector <string> grid(n);
     for(int i=0;i<n;i++)
      cin >> grid[i];

    int ans = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m-1;j++){
        if(grid[i][j] == '.'){
          if(grid[i][j+1] == '.'){
            ans += min(y,2*x);
            grid[i][j] = grid[i][j+1] = '*';
          }else{
            ans += x;
            grid[i][j] = '*';
          }
        }
      }
      if(grid[i][m-1] == '.')
        ans += x, grid[i][m-1] = '*';
    }

    cout << ans << endl;
   } 

  return 0;
}