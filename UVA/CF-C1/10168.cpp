#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long nax = 1e7 + 5;
vector <int> primes;
bitset <nax> is_prime;

void sieve(){
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;

  for(long long i = 2;i<=nax;i++){
    if(is_prime[i]){
      primes.push_back(i);
      for(long long j = i*i;j<=nax;j+=i)
        is_prime[j] = 0;
    }
  }
}

int main(){
  
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  sieve();

  int n;
  int tam = primes.size();

  while(cin >> n){
    if(n < 8){
      cout << "Impossible." << endl;
      continue;
    }

    if(n % 2 == 0)
      cout << "2 2 ", n-=4;
    else
      cout << "2 3 ", n-=5;

    for(int i=0;i<tam;i++){
      int x1 = primes[i];
      int x2 = n - x1;

      if(is_prime[x2]){
        cout << x1 << " " << x2 << endl;
        break;
      }
    }

  }
  
  
  return 0;
}