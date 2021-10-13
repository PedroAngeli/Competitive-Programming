#include <bits/stdc++.h>

using namespace std;

string msg, crib;

int main(){

  cin >> msg >> crib;

  int ans = 0;

  for(int k=0;k<=msg.size()-crib.size();k++){
    bool can = true;
    for(int i=k,j=0;j<crib.size();i++,j++){
      if(crib[j] == msg[i]){
        can = false;
        break;
      }
    }

    if(can)
      ans++;
  }

  cout << ans << endl;

  return 0;
}