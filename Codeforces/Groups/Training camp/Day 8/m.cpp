#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m,d;
  cin >> n >> m >> d;
  const int INF = 1e9 + 7;

    int mat[n][m];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin >> mat[i][j];

  int ans = INF;

  for(int k=1;k<=2e4;k++){
    int cnt = 0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        if(mat[i][j] == k)
          continue;
        
        if(k < mat[i][j] && ((mat[i][j]-k)%d) == 0){
            cnt+=((mat[i][j]-k)/d);
            continue;
        }else if(((k-mat[i][j])%d) == 0){
          cnt+=((k-mat[i][j])/d);
          continue;
        }

        cnt = INF;
        i = n;
        break;
      }
    }

    ans = min(cnt,ans);
  }

  if(ans == INF)
    ans = -1;

  cout << ans << endl;
  
  return 0;
}