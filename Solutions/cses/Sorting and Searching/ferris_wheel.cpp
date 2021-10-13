#include <bits/stdc++.h>

using namespace std;


int main(){

  long long n,x;

  cin >> n >> x;
  vector <long long> vet(n);

  for(int i=0;i<n;i++)  
    cin >> vet[i];

  sort(vet.begin(),vet.end());

  int resp = 0;

  for(int i=0,j=n-1;;){
    if(i > j){
      break;
    }
    if(i == j){
      resp++;
      break;
    }

    if(vet[i] + vet[j] <= x){
      resp++;
      i++;
      j--;
    }else{
      resp++;
      j--;
    }
  }

  cout << resp << endl;
  
  return 0;
}