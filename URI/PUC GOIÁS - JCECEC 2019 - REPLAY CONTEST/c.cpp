#include <bits/stdc++.h>

using namespace std;

int n,m;
vector <string> V;
string S;

bool palindromo(string s){
  int tam = s.size();

  for(int i=0;i<tam/2;i++){
    if(s[i] != s[tam-1-i]){
      return false;
    }
  }

  return true;
}

int main(){

  while(cin >> n >> m){
    cin >> S;
    int resp = 0;

    V.resize(m);

    for(int i=0;i<m;i++)
      cin >> V[i];


    for(int k=0;k<n;k++){
      for(int i=0;i+k<n;i++){
        string s(S.begin()+i,S.begin()+i+k+1);
        if(palindromo(s)){
          bool isSub = false;
          for(int j=0;j<m;j++){
            if(s.find(V[j]) != string::npos){
              isSub = true;
              break;
            }
          }
          if(!isSub)
            resp++;
        }
      }
    }    

    cout << resp << endl;

  }

  return 0;
}