#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 100;
long long comb[nax][nax];

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int vet[n+1];

    for(int i=1;i<=n;i++)
      cin >> vet[i];

    int ans[n+1] = {0};
    ans[1] = 1;

    for(int i=2;i<=n;i++){
      set <int> div;

      for(int j=1;j*j<=i;j++){
        if(i%j ==0){
          div.insert(j);
          div.insert(i/j);
        }
      }
      int mx = 0;
      for(auto it=div.begin();it!=div.end();it++){
        int cur = *it;
        if(cur != i){
          if(vet[i] > vet[cur])
            mx = max(mx,ans[cur]);  
        }
      }
      
      ans[i] = 1 + mx;
    }
    int resp = 0;
    for(int i=1;i<=n;i++){
      //cout << ans[i] << " ";
      resp = max(resp,ans[i]);
    }

    cout << resp << endl;
  }

  return 0;
}