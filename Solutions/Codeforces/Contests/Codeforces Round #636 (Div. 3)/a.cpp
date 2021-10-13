#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  
  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    int sum = 1;
    int i =1;
    while(true){
      i *= 2;
      sum += i;
      if(n % sum == 0){
        cout << n/sum << endl;
        break;
      }
    }
  }

  return 0;
}