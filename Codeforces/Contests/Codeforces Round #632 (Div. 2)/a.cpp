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
    vector <vector<char> > ans(n,vector<char>(m));

    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
        if(i%2 == 0){
          if(j%2 == 0)
            ans[i][j] = 'B';
          else
            ans[i][j] = 'W';
        }else{
          if(j%2 == 0)
            ans[i][j] = 'W';
          else
            ans[i][j] = 'B';
        }
       }
    }
     
    if((n*m)%2 == 0){
      if(n % 2 == 0)
        ans[n-1][0] = 'B';
      else
        ans[n-1][m-1] = 'B';
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++)
        cout << ans[i][j];
      cout << endl;
    }
      
      
  }

  return 0;
}