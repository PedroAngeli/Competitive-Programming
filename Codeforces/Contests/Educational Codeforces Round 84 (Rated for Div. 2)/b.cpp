#include <bits/stdc++.h>
 
using namespace std;
 
 
int main(){
 
  int t;
  cin >> t;
 
  while(t--){
    int n;
    cin >> n;
    set <int> d;
    set <int> k;

    for(int i=1;i<=n;i++){
      d.insert(i);
      k.insert(i);
    }
    
    bool improve = false;
    int x,y;

    for(int i=0;i<n;i++){
      int temp;
      cin >> temp;
      vector <int> vet(temp);
      for(int j=0;j<temp;j++)
        cin >> vet[j];
      
      int j = 0;
      while(j < temp){
        if(k.count(vet[j])){
          k.erase(vet[j]);
          d.erase(i+1);
          break;
         }
        j++;
      }

      if(j == temp){
        improve = true;
      }
    }

    if(improve){
      x = *(d.begin());
      y = *(k.begin());
      cout << "IMPROVE\n" << x << " " << y << endl;
    }
    else{
      cout << "OPTIMAL\n";
    }
  }
  return 0;
}