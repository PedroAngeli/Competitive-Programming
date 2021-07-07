#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  long long n,m,k;

  cin >> n >> m >> k;
  const int mod = 1e9 + 9;

  if(m <= (n+1)/2)
    cout << m << endl;
  else{
    long long times = max(0LL,n/k - n + m);
    long long rest = m-times*k;
    times++;

    long long ans = 1;
    long long base = 2;

    while(times){
      if(times & 1)
        ans = (ans*base)%mod;
      times /= 2;
      base = (base * base)%mod;
    }

    ans = (ans-2+mod)%mod;
    ans = (ans*k)%mod;

    cout << (ans + rest)%mod << endl;
  }
  return 0;
}