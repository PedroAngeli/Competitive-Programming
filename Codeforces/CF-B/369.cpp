#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,l,r,sall,sk;

  cin >> n >> k >> l >> r >> sall >> sk;

  vector <int> ans(n);
  int mod = sk%k;

  for(int i=0;i<k;i++){
    ans[i] = sk/k;

    if(mod)
      ans[i]++, mod--;
  }

  if(n!=k){
    int dif = sall-sk;
  mod = dif % (n-k);

  for(int i=k;i<n;i++){
    ans[i] = dif/(n-k);

    if(mod)
      ans[i]++,mod--;  
  }

  }
  
  for(int i=0;i<n;i++)
    cout << ans[i] << " ";

  cout << endl;


  return 0;
}