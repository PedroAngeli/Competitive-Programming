#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int ans = 1e9 + 7;

  for(int i=0;i<n-1;i++){
    if(s[i] == 'R' && s[i+1] == 'L')
      ans = min(ans,(vet[i+1]-vet[i])/2);
  }

  if(ans == 1e9 + 7)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}