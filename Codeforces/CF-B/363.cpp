#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int query(int l,int r, int* pref){
  if(l == 0)
    return pref[r];

  return pref[r] - pref[l-1];
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k;

  cin >> n >> k;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int pref[n];
  pref[0] = vet[0];

  for(int i=1;i<n;i++)
    pref[i] = pref[i-1] + vet[i];

  int ans = 1e9 + 7;
  int idx = 0;

  for(int i=0;i+k-1<n;i++){
    int q = query(i,i+k-1,pref);
    if(ans > q){
      ans = q;
      idx = i;
    }
  }
  
  cout << idx+1 << endl;

  return 0;
}