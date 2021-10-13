#include <bits/stdc++.h>


using namespace std;


int main(){

  string s;
  string ans = "";
  cin >> s;
  int i;
  map <char,char> mapa;
  mapa['R'] = 'S';
  mapa['B'] = 'K';
  mapa['L'] = 'H';

  for(i=0;i<(int)s.size()-2;){
    int r=0,b=0,l=0;
  
    string temp(s.begin()+i,s.begin()+i+3);

    if(temp == "RLB" || temp == "RBL" || temp == "LRB" || temp == "LBR" || temp == "BRL" || temp == "BLR"){
      ans+="C";
      i+=3;
    }else{
      ans+=mapa[s[i]];
      i++;
    }
  }

  for(;i<s.size();i++){
    ans+=mapa[s[i]];
  }


  cout << ans << endl;

  return 0;
}