#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <string> grid(n);
    for(int i=0;i<n;i++)
      cin >> grid[i];
    int ones = 0;
    int cnt = 0;

    for(int i=0;i<n-1;i++){
      for(int j=0;j<n-1;j++){
        if(grid[i][j] == '1'){
          ones++;
          if(grid[i+1][j] == '1' || grid[i][j+1] == '1')
            cnt++;
        }
      }
    }


    if(cnt == ones)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}