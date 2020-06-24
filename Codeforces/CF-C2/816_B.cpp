#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2e5 + 5;
long long qtd[nax];
long long pref[nax]; 

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,k,q;
  cin >> n >> k >> q;
  
  for(int i=0;i<n;i++){
    int l,r;
    cin >> l >> r;
    qtd[l]++;
    qtd[r+1]--;
  }

  for(int i=1;i<nax;i++){
    qtd[i] += qtd[i-1];
  }

  pref[0] = qtd[0] >= k ? 0 : 1;

  for(int i=1;i<nax;i++){
    pref[i] = pref[i-1];
    if(qtd[i] >= k)
      pref[i]++;
  }

  while(q--){
    int a,b;
    cin >> a >> b;
    cout << pref[b] - pref[a-1] << endl;
  }


  return 0;
}