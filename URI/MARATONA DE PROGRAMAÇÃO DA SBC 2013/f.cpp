#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  while(cin >> n){
    vi vet(n+1);
    vi pref(n+1,0);
    for(int i=1;i<=n;i++)
      cin >> vet[i],pref[i] = pref[i-1] + vet[i];
    
    if(pref[n] % 3 != 0){
      cout << 0 << endl;
      continue;
    }

    int ans = 0;
    int side_len = pref[n]/3;

    for(int i=1;i<=n;i++){
      int j = lower_bound(pref.begin(),pref.end(),pref[i] + side_len) - pref.begin();
      if(pref[j] - pref[i] != side_len || j >= n)
        continue;
      int k = lower_bound(pref.begin(),pref.end(),pref[j] + side_len) - pref.begin();
      if(pref[k] - pref[j] != side_len)
        continue;
      ans++;
    }

    cout << ans << endl;
  }

  return 0;
}