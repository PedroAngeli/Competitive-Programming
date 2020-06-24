#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;

  int vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  int ans = -1;

  int cnt = 1;

  for(int i=0;i<2*n-1;i++){
    int idx = i%n;

    if(cnt == n){
      ans = ((2*n-1)-i)%n;
      break;
    }

    if(vet[idx] <= vet[(idx+1)%n])
      cnt++;
    else
      cnt = 1;
  }

  cout << ans << endl;
  
   
  return 0;
}