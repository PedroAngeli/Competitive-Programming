#include <bits/stdc++.h>

using namespace std;

const long long maxprime = 1e3;
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

int main(){

  int t;
  cin >> t;
  SieveOfEratosthenes();

  while(t--){
    int n;
    cin >> n;
    vector <int> vet(n);
    bool check[n];
    int color[n];

    memset(check,false,sizeof check);

    for(int i=0;i<n;i++)
      cin >> vet[i];

    int c = 1;

    for(int k=0;k<primes.size();k++){
      int num = primes[k];
      int temp = 0;
      
      for(int i=0;i<n;i++){
        if(!check[i]){
          if(vet[i] % num == 0){
            check[i] = true;
            color[i] = c;
            temp++;
          }
        }
      }
      if(temp)
        c++;
    }

    int colors = 0;

    for(int i=0;i<n;i++)
      colors = max(colors,color[i]);

    cout << colors << endl;

    for(int i=0;i<n;i++)
      cout << color[i] << " ";

    cout << endl;
  }
  
  return 0;
}