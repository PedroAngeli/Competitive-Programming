#include <bits/stdc++.h>

using namespace std;


int main(){

  int n;
  cin >> n;
  int cont = 0;
  int crimes = 0;
  int ans = 0;
  for(int i=0;i<n;i++){
    int e;
    cin >> e;

    if(e == -1){
      crimes++;

      if(cont >= crimes){
        cont -= crimes;
        crimes--;
      }
    }
    else{
      cont += e;
      ans += crimes;
      crimes = 0;
    }
  }

  ans += crimes;

  cout << ans << endl;


  return 0;
}