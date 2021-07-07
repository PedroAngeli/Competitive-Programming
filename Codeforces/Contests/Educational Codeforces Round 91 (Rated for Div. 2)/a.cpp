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

    bool find = false;
    int I=-1,J=-1,K=-1;

    for(int j=1;j<n-1;j++){
      for(int i=j-1;i>=0;i--)
        if(vet[i] < vet[j]){
          I = i;
          break;
        }

      for(int k=j+1;k<n;k++)
        if(vet[k] < vet[j]){
          K = k;
          break;
        }

      if(I != -1 && K!=-1){
        cout << "YES" << endl;
        cout << I+1 << " " << j+1 << " " << K+1 << endl;
        find = true;
        break;
      } 

      I = -1;
      K = -1;
    }

    if(!find)
      cout << "NO" << endl;
  }
  
   
  return 0;
}