#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const long long nax = 2e6;
vector <int> pal;
vector <int> primes;
long long p,q;

bool isPal(int n){
  string str;

  while(n){
    int dig = n%10;
    n/=10;
    str.push_back(dig);
  }

  int len = str.size();

  for(int i=0;i<len/2;i++)
    if(str[i] != str[len-i-1])
      return false;

  return true;  
}

bool can(int m){
  long long qtdPrimes = upper_bound(primes.begin(),primes.end(),m) - primes.begin();
  long long qtdPal = upper_bound(pal.begin(),pal.end(), m) - pal.begin();
  
  return p*qtdPal >= q*qtdPrimes;
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> p >> q;

  vector <bool> isPrime(nax+1,true);

  for(long long i=2;i<=nax;i++){
    if(isPrime[i]){
      primes.push_back(i);
      for(long long j=i*i;j<=nax;j+=i)
        isPrime[j] = false;
    }
  }

  for(int i=1;i<=nax;i++){
    if(isPal(i))
      pal.push_back(i);
  }

  int ans = 0;

  for(int i=1;i<=nax;i++){
    if(can(i))
      ans = i;
  }
  
  cout << ans << endl;
  
   
  return 0;
}