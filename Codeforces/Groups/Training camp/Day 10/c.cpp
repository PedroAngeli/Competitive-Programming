#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int mod = 1e9 + 7;

vector <long long> c;
long long comb[1005][1005];

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  long long k;
  cin >> k;

  c.resize(k);

  for(int i=0;i<k;i++)
    cin >> c[i];

  for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++)
      comb[i][j] = 1;

  for(int i=2;i<=1000;i++)
    for(int j=1;j<i;j++){
      comb[i][j] = comb[i-1][j] + comb[i-1][j-1];
      comb[i][j] %= mod;
    }

  long long ans = 1;
  long long pref = 0;

  for(int i=0;i<k;i++){
    ans *= (comb[c[i]+pref-1][c[i]-1]);
    pref += c[i];
    ans %= mod;
    if(ans < 0)
      ans+=mod;
  }

  cout << ans << endl;

  return 0;
}