#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;
  cin >> n >> k;
  int vet[n];
  for(int i=0;i<n;i++)
    cin >> vet[i];
  sort(vet,vet+n);

  int ans = 0;

  for(int i=0;i<k;i++)
    ans += vet[i];
  
  cout << ans << endl;
 
  return 0;
}