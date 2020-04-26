#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  long long n,m;

  cin >> n >> m;

  long long ans = 0;

  for(long long i=1;i<=n;i++){
    long long searchMod = 5-(i%5);
    ans += m/5;

    if(m % 5 != 0 && m % 5 >= searchMod)
      ans++;
  }

  cout << ans << endl;

  return 0;
}