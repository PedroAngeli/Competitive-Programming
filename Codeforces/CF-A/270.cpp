#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;

  while(t--){
    int a;
    cin >> a;
    
    if(360 % (180-a) == 0)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;  
  }

  return 0;
}