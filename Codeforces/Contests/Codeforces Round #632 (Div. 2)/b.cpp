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
    int a[n];
    int b[n];
    for(int i=0;i<n;i++)
      cin >> a[i];
    for(int i=0;i<n;i++)
      cin >> b[i];

    bool one = false;
    bool minusOne = false;
    bool can = true;
    
    for(int i=0;i<n;i++){
      if(i == 0 && a[i] != b[i]){
        can = false;
        break;
      }

      if((b[i] > a[i] && !one) || (b[i] < a[i] && !minusOne)){
        can = false;
        break;
      }
      
      if(a[i] == -1)
        minusOne = true;
      if(a[i] == 1)
        one = true;
    }

    if(can)
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
    
  }

  return 0;
}