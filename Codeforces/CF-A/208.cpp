#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;

  cin >> s;

  for(int i=0;i<s.size();i+=3){

    string temp = "";
    if(i < s.size() - 2)
      temp = string(s.begin()+i,s.begin()+i+3);
      
    if(temp != "WUB"){
      for(;i<s.size();i++){
        string temp2(s.begin()+i,s.begin()+i+3);
        if(i < s.size() -2 && temp2 == "WUB")
          break;
        cout << s[i];
      }
      cout << " ";
    }
  }

  cout << endl;
  

  return 0;
}