#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;
const int nax = 1e6;
long long fatorial[nax+1];

//Calcula a^b % m
//Complexidade O(log b)
long long binary_pow(long long a, long long b){
  a = a%m;
  long long ans = 1;

  while(b>0){
    if(b & 1){
      ans = (ans * a) % m;
    }

    a = (a * a)%m;
    b = b >> 1;
  }

  return ans;
}

//Calcula o inverso modular de a (mod m) (a^m-2 ≡ a⁻1  (mod m)) -> Fermat's little Theorem
//Funciona quando m é um número primo
//Complexidade O(log m)
long long modular_inverse(long long a){
  return binary_pow(a,m-2);
}

//Calcula o fatorial (mod m) até o valor máximo de n
//Complexidade O(nax) 
void calcula_fatorial(){
  fatorial[0] = 1;

  for(int i=1;i<=nax;i++){
    fatorial[i] = (fatorial[i-1] * i) % m;
  }
}

long long binomial_coefficient(int n,int k){
  return fatorial[n] * modular_inverse(fatorial[k]) % m * modular_inverse(fatorial[n-k]) % m;
}

int main(){

  calcula_fatorial();

  int n;
  cin >> n;

  while(n--){
    int a,b;
    cin >> a >> b;
    cout << binomial_coefficient(a,b) << endl;
  }

  return 0;
}