#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 8e3 + 1;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int vet[n];
    int cnt[nax] = {0};
    
  
    for(int i=0;i<n;i++)
      cin >> vet[i];

    for(int i=0;i<n;i++){
      int sum = vet[i];
      for(int j=i+1;j<n;j++){
        sum+=vet[j];
        if(sum > n)
          break;
        cnt[sum]++;
      }
    }

    int ans =0;
    for(int i=0;i<n;i++)
      if(cnt[vet[i]])
        ans++;
    
    cout << ans << endl;
  }
    
  return 0;
}