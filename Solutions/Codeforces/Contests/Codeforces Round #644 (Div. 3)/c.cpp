#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int vet[n];
    int even = 0;
    int odd = 0;
    for(int i=0;i<n;i++){
      cin >> vet[i];
      if(vet[i] % 2 ==0)
        even++;
      else
        odd++;
    }

    if(even % 2 == 0 && odd % 2 == 0)
      cout << "YES" << endl;
    else{
      int cnt = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(i!=j && vet[i] == vet[j]+1){
            cnt++;
            break;
          }
        }

        if(cnt)
          break;
      }

      if(cnt)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    
  }

  return 0;
}