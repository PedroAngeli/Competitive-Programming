#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 
 
  int t = 1;
  // cin >> t;
 
  while(t--){
    int n;
    cin >> n;
    int cnt[20] = {0};

    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      for(int j=0;j<20;j++)
        if(x & (1 << j))
          cnt[j]++;
    }

    long long vet[n] = {0};

    for(int i=0;i<20;i++){
      for(int j=0;j<cnt[i];j++)
        vet[j] += (1 << i);
    }

    long long ans = 0;
    for(int i=0;i<n;i++)
      ans += vet[i]*vet[i];

    cout << ans << endl;

  }
 
  
  return 0;
}