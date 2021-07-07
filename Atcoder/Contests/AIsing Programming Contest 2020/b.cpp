#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int ans = 0;
  
  for(int i=1;i<=n;i++){
    int x;
    cin >> x;
    if(x%2 == 1 && i%2 == 1)
      ans++;
  }

  cout << ans << endl;

  return 0;
}