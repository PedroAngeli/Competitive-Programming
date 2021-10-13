#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int h,w,k;
vector <string> grid;
bool check(int r,int c){
  int cnt = 0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(r & (1 << i) || c & (1 << j))
          continue;
        if(grid[i][j] == '#')
          cnt++;
      }
    }
    return cnt == k;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> k;

  grid.resize(h);

  for(int i=0;i<h;i++)
    cin >> grid[i];
 
  int ans  =0;
  for(int r=0;r<(1<<h);r++){
    for(int c=0;c<(1<<w);c++){
      if(check(r,c))
        ans++;
    }
  }

  cout << ans << endl;

  return 0;
}