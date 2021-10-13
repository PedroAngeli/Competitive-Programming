#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int ans[350][350];
int n,k;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin >> t;
  while(t--){
    memset(ans,0,sizeof(ans));
    memset(vis,false,sizeof(vis));
    cin >> n >> k;
    int i = 0;
    int j = 0;
    while(k){
      k--;
      ans[i][j] = 1;
      i++,j++;
      if(i==n)
        j++;
      i %= n;
      j %= n;
    }

   int mnRow = INT_MAX;
   int mxRow = 0;
   int mnCol = INT_MAX;
   int mxCol = 0;

    for(int i=0;i<n;i++){
      int sum = 0;
      for(int j=0;j<n;j++){
        sum += ans[i][j];
      }
      mnRow = min(mnRow,sum);
      mxRow = max(mxRow,sum);
    }

    for(int i=0;i<n;i++){
      int sum = 0;
      for(int j=0;j<n;j++){
        sum += ans[j][i];
      }

      mxCol = max(mxCol,sum);
      mnCol = min(mnCol,sum);

    }

    int val = pow((mxRow - mnRow),2) + pow((mxCol-mnCol),2);

    cout << val << endl;

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << ans[i][j];
      }
      cout << endl;
    }
      
  }

  return 0;
}