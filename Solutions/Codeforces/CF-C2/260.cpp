#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,x;
  cin >> n >> x;
  x--;
  long long vet[n];
  long long mn = LLONG_MAX;

  for(int i=0;i<n;i++){
    cin >> vet[i];
    mn = min(mn,vet[i]);
  }

  for(int i=0;i<n;i++)
    vet[i] -= mn;

  int i = x;
  long long sum = 0;

  while(true){
    if(vet[i] == 0){
      vet[i] = mn*n + sum;
      break;
    }
    vet[i]--;
    i--;
    sum++;
    if(i < 0) i = n-1;
  }

  for(int i=0;i<n;i++)
    cout << vet[i] << " ";
  cout << endl;

  return 0;
}