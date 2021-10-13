#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  
  while(t--){
    int n;
    cin >> n;
    long long vet[n];
    for(int i=0;i<n;i++)
      cin >> vet[i];
    int ans = 0;

    for(int i=1;i<n;i++){
      if(vet[i] < vet[i-1]){
        long long dif = vet[i-1]-vet[i];
        int op = log2(dif) + 1;
        ans = max(ans,op);
        long long add = pow(2,op-1);
        if(vet[i] + add >= vet[i-1])
        vet[i] += add;
        else
        vet[i]+=dif;
      }
    }

    cout << ans << endl;
  }

  return 0;
}