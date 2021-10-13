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
    int vet[n];
    for(int i=0;i<n;i++)
      cin >> vet[i];
    sort(vet,vet+n);
    int ans = 0;

    for(int i=0;i<n;i++){
      if(i+1 >= vet[i])
        ans = max(ans,i+1);
    }

    cout << ans + 1 << endl;
  }
  
  return 0;
}