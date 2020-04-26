#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector <string> grid(4);

  for(int i=0;i<4;i++)
    cin >> grid[i];

  bool ans = false;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      
      char c = grid[i][j];
      int count = 0;

      for(int k=i;k<2+i;k++){
        for(int l=j;l<2+j;l++){
         
          if(grid[k][l] == c)
            count++;
        }
      }


      if(count <= 1 || count >= 3)
        ans = true;
    }
  }

  if(ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}