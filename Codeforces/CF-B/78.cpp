#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  string ans = "";
  string s1 = "ROYG";
  string s2 = "BIVG";

  bool flag = true;

  while(ans.size() < n){
    int tam = min(n-(int)ans.size(),4);

    if(tam < 4 && flag){
      string temp(s2.begin(),s2.begin() + tam);
      ans += temp;
      break;
    }

    if(flag){
      string temp(s1.begin(),s1.begin() + tam);
      ans += temp;
    }else{
      string temp(s2.begin(),s2.begin() + tam);
      ans += temp;
    }

    flag = !flag;
  }

  cout << ans << endl;

  return 0;
}