#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long double comb[101][101];

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  long long h,m,c;

  for(int i=0;i<=100;i++){
    for(int j=0;j<=i;j++){
      if(i == 0 || j == 0 || j == i)
        comb[i][j] = 1.0;
      else comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
    }
  }

  while(cin >> h >> m >> c && (h || m)){
    long double ans = 0;
    long double ph = (long double)h/(h+m);
    long double pm = (long double)m/(h+m);

    for(int i=0;i<=c;i+=2){
        ans += comb[c][i]*pow(ph,i)*pow(pm,c-i);
    }

    cout << fixed << setprecision(7) << ans << endl;
  }  
  return 0;
}