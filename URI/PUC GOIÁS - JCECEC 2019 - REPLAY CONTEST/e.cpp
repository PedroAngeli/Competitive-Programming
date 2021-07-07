#include <bits/stdc++.h>

using namespace std;


int main(){

  string s;

  while(getline(cin,s)){
    int tam = s.size();

    for(int i=0;i<tam-1;i++)
      if(!(s[i] == ' ' && (s[i+1]=='.' || s[i+1]==',')))
        cout << s[i];
    cout << s[tam-1];
    cout << "\n";
  }

  return 0;
}