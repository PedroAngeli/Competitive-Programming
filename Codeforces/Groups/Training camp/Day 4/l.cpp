#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
 
  int n,k;
  cin >> n >> k;
  vector <int> primes;
  vector <bool> is_prime(n+1,true);

  for(int i=2;i<=n;i++){
    if(is_prime[i]){
      primes.push_back(i);
      for(int j=i*i;j<=n;j+=i){
        is_prime[j] = false;
      }
    }
  }

  int len = primes.size();
  int cnt = 0;

  for(int i=0;i<len;i++){
    int cur = primes[i];
    for(int j=0;j<i;j++){
      int sum = primes[j]+primes[j+1];
      sum++;
      if(sum == cur)
        cnt++;
    }
  }

  if(cnt >= k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}