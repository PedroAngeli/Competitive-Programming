#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  map <string,int> mapa;

  cin >> n;

  for(int i=0;i<n;i++){
    string s;
    cin >> s;

    if(!mapa.count(s)){
      mapa[s] = 1;
    }else{
      mapa[s]++;
    }
  }

  map <string,int> :: iterator it;
  int maior = 0;

  for(it = mapa.begin();it!=mapa.end();it++){
    int f = it->second;
    maior = max(maior, f);
  }

   for(it = mapa.begin();it!=mapa.end();it++){
    int f = it->second;
    string s = it->first;
    
    if(f == maior){
      cout << s << endl;
    }
    
  }
 

  return 0;
}