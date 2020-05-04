#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  int ans = 0;

  for(int i=0;i<n;i++){
    int p;
    cin >> p;
    ans = ans ^ p;
  }

  int vet[n+1];
  vet[0] = 0;

  for(int i=1;i<=n;i++)
    vet[i] = i ^ vet[i-1];

  for(int i=2;i<=n;i++){
    int t = n/i;
    int r = n%i;
    ans = ans ^ vet[r];
    if(t % 2 == 1)
      ans = ans ^ vet[i-1];
  }

  cout << ans << endl;

  return 0;
}