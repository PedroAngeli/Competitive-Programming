#include <bits/stdc++.h>

using namespace std;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  int vet[n];

  int total = 0;
  for(int i=0;i<n;i++){
    cin >> vet[i];
    total += vet[i];
  }
    

  sort(vet,vet+n);
  reverse(vet,vet+n);

  int sum = 0;
  int ans = 0;

  for(int i=0;i<n;i++){
    sum += vet[i];
    total -= vet[i];
    ans++;
    if(sum > total)
      break;
  }

  cout << ans << endl;
  
  return 0;
}