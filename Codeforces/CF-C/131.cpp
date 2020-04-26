#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 100;
long long comb[nax][nax];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n, m, t;

  cin >> n >> m >> t;

  comb[0][0] = 1;
  
  for(int i=1;i<=30;i++)
    for(int j=0;j<=i;j++)
      if(j == 0 || j== i)
        comb[i][j] = 1;
      else
        comb[i][j] = comb[i-1][j] + comb[i-1][j-1];

  long long ans = 0;

  for(int i=0;i<=t-5;i++){
    ans += comb[n][i+4]*comb[m][t-(i+4)];
  }

  cout << ans << endl;

  return 0;
}