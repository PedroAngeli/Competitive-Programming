#include <bits/stdc++.h>

using namespace std;

int maiorDigito(int n){
  int maior = 0;

  while(n > 0){
    maior = max(maior, n%10);
    n/=10;
  }

  return maior;
}

int main(){

 int n;

 cin >> n;
 int ans = 0;

 while(n > 0){
   int dig = maiorDigito(n);
   n -= dig;
   ans++;
 }

  cout << ans << endl;
  

  return 0;
}