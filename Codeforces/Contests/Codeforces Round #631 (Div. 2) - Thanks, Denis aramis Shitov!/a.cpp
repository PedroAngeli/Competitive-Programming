#include <bits/stdc++.h>

using namespace std;

int main(){


  int t;
  cin >> t;

  while(t--){
    int n,x;

    cin >> n >> x;
   set <int> conj;

    for(int i=0;i<n;i++){
      int a;
      cin >> a;
      conj.insert(a);
    } 
    
    int k = 1;
    while(x){
      if(!conj.count(k)){
        conj.insert(k);
        x--;
      }
      k++;
    }
    int anterior = 0;
    int atual = 0;
    bool ans = false;


    for(auto it = conj.begin();it!=conj.end();it++){
      int atual = *it;
      
      if(atual - anterior > 1){
        cout << anterior << endl;
        ans = true;
        break;
      }else{
        anterior = atual;
      }  
    }

    if(!ans){
      cout << anterior << endl;
    }
  }
  return 0;
}