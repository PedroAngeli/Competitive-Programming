#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,x;
  
  cin >> n >> x;

  long long vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  sort(vet,vet+n);
  long long ans = 0;

  for(int i=0;i<n;i++){
    ans += vet[i]*x;
    if(x > 1)
      x--;
  }

  cout << ans << endl;
  
  return 0;
}