#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while(t--){
    int n,m;
    cin >> n >> m;
    int grid[n][m];
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        cin >> grid[i][j];

    int row[n];
    for(int i=0;i<n;i++){
      int can = 1;
      for(int j=0;j<m;j++){
        if(grid[i][j]){
          can = 0;
          break;
        }
      }
      row[i] = can;
    }
    int col[m];
    for(int i=0;i<m;i++){
      int can = 1;
      for(int j=0;j<n;j++){
        if(grid[j][i]){
          can = 0;
          break;
        }
      }
      col[i] = can;
    }

    int cntR= 0;
    for(int i=0;i<n;i++)
      if(row[i])
        cntR++;

    int cntC = 0;
    for(int i=0;i<m;i++)
      if(col[i])
        cntC++;

    int plays = min(cntC,cntR);
    if(plays % 2 == 0)
      cout << "Vivek" << endl;
    else
      cout << "Ashish" << endl;


  }

  return 0;
}