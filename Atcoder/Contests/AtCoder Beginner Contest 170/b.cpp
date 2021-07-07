#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int x,y;
  cin >> x >> y;
 
  for(int i=0;i<=x;i++){
    for(int j=0;j<=x;j++){
      if(2*i + 4*j == y && i+j == x){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}