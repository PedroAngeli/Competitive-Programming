#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  int vet[n];


  for(int i=0;i<n;i++){
    cin >> vet[i];
  }

  int cnt = 0;

  for(int i=0;i<k;i++){
    if(i < n && vet[i] < 0){
      cnt++;
      vet[i] *= -1;
    }
  }

  int ans = 0;

  for(int i=0;i<n;i++)
    ans += vet[i];

  if(cnt < k){
    k = k - cnt;
    if(k % 2 == 1){
      if(cnt >= 1)
        ans += max(2*vet[cnt-1]*-1,2*vet[cnt]*-1);
      else
        ans += (2*vet[cnt]*-1);
    }
  }

  cout << ans << endl;

  return 0;
}