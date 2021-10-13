#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 3e5 + 5;
int vet[nax];
int n;

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    cin >> n;
    for(int i=0;i<n;i++)
      cin >> vet[i];

    sort(vet,vet+n);

    int ans = 0;
    int minSize = 0;
    int curSize = 0;

    for(int i=0;i<n;i++){
      minSize = max(minSize,vet[i]);
      curSize++;
      if(curSize >= minSize){
        ans++;
        curSize = 0;
      }
    }

    cout << ans << endl;
  }

  return 0;
}