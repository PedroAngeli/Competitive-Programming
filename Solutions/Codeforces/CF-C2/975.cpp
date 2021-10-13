#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int n,q;
  cin >> n >> q;

  long long vet[n];
  for(int i=0;i<n;i++)
    cin >> vet[i];
  
  vector <long long> pref(n+1);
  pref[0] = 0;
  for(int i=1;i<=n;i++)
    pref[i] = pref[i-1] + vet[i-1];

  long long dead = 0;

  while(q--){
    long long k;
    cin >> k;
    long long search = k + dead;
    auto it = lower_bound(pref.begin(),pref.end(),search);

    if(it == pref.end()){
      cout << n << endl;
      dead = 0;
    }else{
      long long cur = *it;
      if(cur == search){
        long long ans = pref.end() - it - 1;
        if(ans == 0)
          ans = n;
          cout << ans << endl;
          if(ans == n){
            dead = 0;
            continue;
          }
      }else{
        cout << pref.end() - it << endl;
      }
      dead = search;
    }
  }
  
  return 0;
}