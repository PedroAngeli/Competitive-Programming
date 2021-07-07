#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m;
  cin >> n >> m;
  int grid[n][m];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> grid[i][j];

  int a,b;
  cin >> a >> b;
  int ans = INT_MAX;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
      if(i+a <= n && j+b <= m){
        int cnt = 0;
        for(int k=i;k<i+a;k++)
          for(int l=j;l<j+b;l++)
            cnt += (grid[k][l] == 1);
        ans = min(ans,cnt);
      }
      if(i+b <= n && j+a <= m){
        int cnt = 0;
        for(int k=i;k<i+b;k++)
          for(int l=j;l<j+a;l++)
            cnt += (grid[k][l] == 1);
          ans = min(ans,cnt);
      }
    }
  
  cout << ans << endl;
  return 0;
}