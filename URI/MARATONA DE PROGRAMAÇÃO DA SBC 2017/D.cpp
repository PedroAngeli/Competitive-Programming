#include <bits/stdc++.h>

using namespace std;

const long long maxprime = 1e7 + 5;
bitset <maxprime> is_prime;
vector <long long> primes;

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

bool despojado(long long N){
  int idx = 0;
  long long pf = primes[idx];
  int factors = 0;

  while(pf*pf <= N){
    int qtd = 0;
    while(N%pf == 0){
      N /= pf;
      qtd++;
      if(qtd == 2)
        return false;
    }
    if(qtd){
      factors++;
    }
    pf = primes[++idx];
  }

  if(N != 1){
    factors++;
  }

  return factors >= 2;
}


int main(){

  long long N;
  cin >> N;

  SieveOfEratosthenes();
  int resp = 0;

  for(long long i=1;i*i<=N;i++){
    if(N % i == 0){
      if(despojado(i))
        resp++;

      if(N/i != i){
        if(despojado(N/i))
          resp++;
      }
    }
  }

  cout << resp << endl;

  return 0;
}