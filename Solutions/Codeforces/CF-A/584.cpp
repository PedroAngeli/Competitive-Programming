#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,t;

  cin >> n >> t;
  string ans = "";
  if(t != 10)
    while(n--)
      ans += '0'+t;
  else{
    if(n == 1)
      ans = "-1";
    else{
      while(n--){
      if(n >= 1)
      ans += "1";
      else
        ans += "0";
    } 
    }
  }
   
    


  cout << ans << endl;
  

  return 0;
}