#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,m;
  cin >> n >> m;

  vector <long long> vet(n);
  
  for(int i=0;i<n;i++){
    long long c,t;
    cin >> c >> t;
    vet[i] = c*t;
  }

  vector <long long> pref(n);
  pref[0] = vet[0];

  for(int i=1;i<n;i++) 
    pref[i] = vet[i]+pref[i-1];

  while(m--){
    long long x;
    cin >> x;
    int ans = lower_bound(pref.begin(),pref.end(),x) - pref.begin();
    cout << ans + 1 << endl;
  }
  
  return 0;
}