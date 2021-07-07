#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

int main(){

 long long n,k;

 cin >> n >> k;

 vector <long long> vet(n);

 for(int i=0;i<n;i++)
  cin >> vet[i];

  long long a = ((2*n - k + 1)*k)/2;

  int intervalo = 0;
  long long resp = 1;
  int count = 0;

  for(int i = 0;i<n;i++){

    if(count && vet[i] >= (n-k+1)){
      intervalo = i - intervalo;
      resp = ((resp % mod)*(intervalo % mod))%mod;
      intervalo = i;
    }

    if(vet[i] >= (n-k+1)){
      count++;
      intervalo = i;
    }
      
  }  

  cout << a << " " << resp << endl;

  return 0;
}