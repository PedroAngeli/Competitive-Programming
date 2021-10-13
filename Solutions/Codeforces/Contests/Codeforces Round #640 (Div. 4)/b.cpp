#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while(t--){
    int n,k;
    cin >> n >> k;

    int even = (k-1)*2;
    if((n-even) % 2 ==0 && n-even > 0){
      cout << "YES" << endl;
      for(int i=0;i<k-1;i++)
        cout << 2 << " ";
      cout << n-even << endl;;
      continue;
    }

    int odd = k-1;
    if((n-odd) % 2 == 1 && n-odd > 0){
      cout << "YES" << endl;
      
      for(int i=0;i<k-1;i++)
        cout << 1 << " ";
      cout << n-odd << endl;
      continue;
    }

    cout << "NO" << endl;
  }
    
  return 0;
}