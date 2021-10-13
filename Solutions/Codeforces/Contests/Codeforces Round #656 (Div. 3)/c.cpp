#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int n;
vector <int> vet;

bool can(int m){
  vector <int> aux;
  int l = m;
  int r = n-1;

  while(l <= r){
    if(vet[l] <= vet[r]){
      aux.push_back(vet[l]);
      l++;
    }else{
      aux.push_back(vet[r]);
      r--;
    }
  }

  for(int i=0;i<aux.size()-1;i++){
    if(aux[i]>aux[i+1])
      return false;
  }

  return true;
}
  
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int t = 1;
  cin >> t;
  while(t--){
    cin >> n;
    vet.resize(n);
    for(int i=0;i<n;i++)
      cin >> vet[i];
    
    int l = 0;
    int r = n-1;
    int ans = n;

    while(l <= r){
      int m = (l+r)/2;

      if(can(m)){
        ans = min(ans,m);
        r = m-1;
      }else{
        l = m+1;
      }
    }

    cout << ans << endl;
  }
    
  return 0;
}