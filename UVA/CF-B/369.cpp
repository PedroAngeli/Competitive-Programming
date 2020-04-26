#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int comb[101][101];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  comb[0][0] = 1;
  comb[1][0] = 1;
  comb[1][1] = 1;

  for(int i=1;i<=100;i++)
    for(int j=0;j<=i;j++){
      if(j == 0 || j == i)
        comb[i][j] = 1;
      else
        comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
    }
      

  int n, m;

  while(cin >> n >> m && n && m)
    cout << n << " things taken " << m << " at a time is " << comb[n][m] << " exactly." << endl;
  
  return 0;
}