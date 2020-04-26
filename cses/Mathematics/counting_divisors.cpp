#include <bits/stdc++.h>

using namespace std;

const long long maxprime = 1e4;
bitset <maxprime> is_prime;
vector <long long> primes;
vector <long long>  factors;

void SieveOfEratosthenes(){
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;

  for(long long i = 2;i<=maxprime;i++){
    if(is_prime[i]){
      primes.push_back(i);
      for(long long j = i*i;j<=maxprime;j+=i){
        is_prime[j] = 0;
      }
    }
  }
}

int primeFactors(long long N){
  int idx = 0;
  int ans = 1;
  long long pf = primes[idx];

  while(pf*pf <= N){
    int qtd = 1;
    while(N%pf == 0){
      N /= pf;
      qtd++;
    }
    ans *= qtd;
    pf = primes[++idx];
  }

  if(N != 1){
   ans *= 2; 
  }

  return ans;
}

int main(){

  SieveOfEratosthenes();

  int n; 
  cin >> n;

  while(n--){
    int x;
    cin >> x;

    cout << primeFactors(x) << endl;

  }
  return 0;
}