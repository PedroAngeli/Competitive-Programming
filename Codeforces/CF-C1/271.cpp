#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e7 + 5;
bitset <nax> is_prime;
vector <int> primes;

void sieve(){
  is_prime.set();
  is_prime[0] = is_prime[1] = 0;

  for(long long i=2;i<=nax;i++){
    if(is_prime[i]){
      primes.push_back(i);
      for(long long j=i*i;j<=nax;j+=i)
        is_prime[j] = 0;
    }
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  sieve();

  cin >> n >> m;
  int mat[n][m];

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin >> mat[i][j];

  long long ans = INT_MAX;

   for(int i=0;i<n;i++){
    long long cnt = 0;
    for(int j=0;j<m;j++){
      int cur = mat[i][j];
      if(!is_prime[cur]){
        auto it = lower_bound(primes.begin(),primes.end(),cur);
        cnt += *it-cur;
      }
    }
    ans = min(cnt,ans);
   }

   for(int i=0;i<m;i++){
    long long cnt = 0;
    for(int j=0;j<n;j++){
      int cur = mat[j][i];
      if(!is_prime[cur]){
        auto it = lower_bound(primes.begin(),primes.end(),cur);
        cnt += *it-cur;
      }
    }
    ans = min(cnt,ans);
   }

   cout << ans << endl;

   


  return 0;
}