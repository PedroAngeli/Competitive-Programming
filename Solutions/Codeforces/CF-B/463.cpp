#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long n;

  cin >> n;

  long long h[n+1];
  h[0] = 0;

  for(int i=1;i<=n;i++)
    cin >> h[i];

  long long ans = 0;

  long long energy = 0;
  

  for(int i=0;i<n;i++){
    energy += h[i]-h[i+1];

    if(energy < 0)
      ans = max(abs(energy),ans);
  }

  cout << ans << endl;

  return 0;
}