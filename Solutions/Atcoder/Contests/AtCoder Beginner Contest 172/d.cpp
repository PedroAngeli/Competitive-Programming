#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e7;
long long divs[nax+5];
bitset <nax> is_prime;

void sieve(){
  is_prime.set();
  for(int i=1;i<=nax;i++)
      divs[i] = 1;
  for(long long i=2;i<=nax;i++){
    if(is_prime[i]){
      for(long long j=i;j<=nax;j+=i){
        is_prime[j] = 0;
        int qtd = 0;
        long long temp = j;
        while(temp % i == 0)
          temp/=i,qtd++;
        divs[j] *= (qtd+1);
      }
    }
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  long long ans = 0;
  sieve();
  for(int i=1;i<=n;i++){
    ans += i*divs[i];
  }

  cout << ans << endl;
 
  return 0;
}