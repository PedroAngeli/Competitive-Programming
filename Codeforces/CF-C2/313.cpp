#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int n;
int mx;

long long solve(int cur, long long *pref){
  if(cur == mx)
    return 2*pref[cur];
  
  return pref[cur] + solve(cur*4,pref);
}
int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  long long vet[n];
  for(int i=0;i<n;i++)
    cin >> vet[i];
  if(n == 1){
    cout << vet[0] << endl;
    return 0;
  }
  sort(vet,vet+n);
  reverse(vet,vet+n);
  long long pref[n+1];
  pref[0] = 0;
  for(int i=1;i<=n;i++)
    pref[i] = vet[i-1] + pref[i-1];
  
  mx = n/4;
  cout << solve(1,pref) + pref[n]-pref[mx] << endl;

  return 0;
}