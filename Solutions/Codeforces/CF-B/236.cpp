#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int mod = 1073741824;
const int nax = 1e6 + 5;

int div(int x){
  
  set <int> s;

  for(int i=1;i*i<=x;i++){
    if(x % i == 0){
      s.insert(i);
      s.insert(x/i);
    }
  }

  return s.size();
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a,b,c;
  
  cin >> a >> b >> c;

  int dp[nax];
  memset(dp,-1,sizeof dp);
  int ans = 0;

  for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++)
      for(int k=1;k<=c;k++){
        int x = i*j*k;
        if(dp[x] != -1)
          ans = (ans + dp[x]) % mod;
        else{
          dp[x] = div(x) % mod;
          ans = (ans + dp[x]) % mod;
        }
      }
    
    cout << ans << endl;

  return 0;
}