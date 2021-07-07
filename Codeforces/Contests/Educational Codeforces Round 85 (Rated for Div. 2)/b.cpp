#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;

  cin >> t;

  while(t--){
    int n;
    long long k;
    cin >> n >> k;

    long long vet[n];

    for(int i=0;i<n;i++)  
      cin >> vet[i];

    sort(vet,vet+n);
    reverse(vet,vet+n);

    int ans = 0;
    long long sum = 0;

    for(long long i=0;i<n;i++){
      sum += vet[i];
      if(sum/(i+1) >= k)
        ans++;
    }

    cout << ans << endl;
  }
  return 0;
}