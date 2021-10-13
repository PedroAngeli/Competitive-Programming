#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    vector <int> vet(n);
    for(int i=0;i<n;i++)
      cin >> vet[i];
    
    int i = 0;
    while(i < n && vet[i] == 1)
      i++;
    if(i == n){
      if(n % 2 == 1)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    }else{
      if(i%2 == 0)
        cout << "First" << endl;
      else
        cout << "Second" << endl;
    }
  }
    
  return 0;
}