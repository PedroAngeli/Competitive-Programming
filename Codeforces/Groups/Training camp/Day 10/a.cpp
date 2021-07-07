#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m;
  cin >> n >> m;
  vector <string> grid(n);

  for(int i=0;i<n;i++)
    cin >> grid[i];
  
  int ans = 0;
  vector <bool> removed(m,false);

  for(int j=0;j<m;j++){
    for(int i=0;i<n-1;i++){
      if(grid[i][j] > grid[i+1][j]){
        bool remove = true;
        for(int k=0;k<j;k++){
          if(removed[k])
            continue;
          if(grid[i+1][k] > grid[i][k])
            remove = false;
        }
        if(remove){
          removed[j] = true;
          ans++;
          break;
        }
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}