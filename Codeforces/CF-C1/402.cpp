#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t--){
    int n,p;
    cin >> n >> p;
    int e = 2*n + p;

    for(int i=1;i<=n && e;i++){
      int j = i+1;
      while(j <= n && e){
        cout << i << " " << j << endl;
        j++;
        e--;
      }
    }
  }  

  return 0;
}