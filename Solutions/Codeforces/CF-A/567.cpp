#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int cnt[4];

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  long long vet[n];

  for(int i=0;i<n;i++)
    cin >> vet[i];

  for(int i=0;i<n;i++){
    if(i == 0){
      cout << vet[i+1]-vet[i] << " " << vet[n-1]-vet[i] << endl;
    }
    else if(i == n-1){
      cout << vet[i]-vet[i-1] << " " << vet[i]-vet[0] << endl;
    }
    else{
      cout << min(vet[i]-vet[i-1],vet[i+1]-vet[i]) << " " << max(vet[i]-vet[0],vet[n-1]-vet[i]) << endl;
    }
  }

  
  return 0;
}