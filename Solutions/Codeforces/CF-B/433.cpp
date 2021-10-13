#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

long long query(int l, int r, long long* vet){
  if(l == 0)
    return vet[r];

  return vet[r] - vet[l-1];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  long long prefOne[n];
  prefOne[0] = vet[0];

  for(int i=1;i<n;i++)
    prefOne[i] = prefOne[i-1] + vet[i];

  sort(vet,vet+n);

  long long prefTwo[n];
  prefTwo[0] = vet[0];

  for(int i=1;i<n;i++)
    prefTwo[i] = prefTwo[i-1] + vet[i];

  int m;

  cin >> m;

  while(m--){
    int t,l,r;
    cin >> t >> l >> r;
    l--;
    r--;
  
    if(t == 1)
      cout << query(l,r,prefOne) << endl;
    else
      cout << query(l,r,prefTwo) << endl;
  }



  

  return 0;
}