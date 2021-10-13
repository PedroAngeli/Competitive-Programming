#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

const int nax = 15000005;
int prime[nax];
int cntDiv[nax];

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL); 


  for(long long i=2;i<nax;i++){
    if(!prime[i]){
      for(long long j=i*i;j<nax;j+=i){
        prime[j] = i;
      }
    }
  }

  for(int i=1;i<nax;i++)
    if(!prime[i])
      prime[i] = i;
 
  int n;
  cin >> n;
  vector <int> vet(n);
  int gcd = 0;
  
  for(int i=0;i<n;i++)
    cin >> vet[i],gcd = __gcd(gcd,vet[i]);

  for(int i=0;i<n;i++)
    vet[i] /= gcd;

  int left = 0;

  for(int i=0;i<n;i++){
    int cur = vet[i];
    while(cur > 1){
      int div = prime[cur];
      cntDiv[div]++;

      left = max(left,cntDiv[div]);

      while(cur % div == 0)
        cur/=div;
    }
  }

  int ans = n-left;

  if(ans == n)
    ans = -1;

  cout << ans << endl;

  return 0;
}