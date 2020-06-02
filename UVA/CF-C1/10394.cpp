#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const long long nax = 2*1e7 + 5;
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

  int s;
  sieve();
  vector <pair <int,int> > twins;

  int n = primes.size();

  for(int i=0;i<n-1;i++){
    int cur = primes[i];
    int next = primes[i+1];

    if(cur + 2 == next)
      twins.push_back({cur,next});
  }

  while(cin >> s){
    s--;
    cout << "(" << twins[s].first << ", " << twins[s].second << ")" << endl;
  }
  
  return 0;
}