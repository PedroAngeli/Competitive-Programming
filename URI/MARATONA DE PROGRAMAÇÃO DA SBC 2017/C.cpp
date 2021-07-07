#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b){
  return b == 0 ? a : gcd(b,a%b);
}

long long lcm(long long a,long long b){
  return a * (b/gcd(a,b));
}

int main(){

  int n,l;
  cin >> n >> l;

  long long mmc = 1;

  for(int i=0;i<n;i++){
    long long c;
    cin >> c;
    mmc = lcm(mmc,c);
  }

  long long ans = 1e9 + 7;
  long long maior = 0;

  for(long long i=1;i<=l;i++){
    long long m = lcm(mmc,i); 
   
    if(m <= l && m > maior){
      maior = m;
      ans = i;
    }
  }

  cout << ans << endl;

  return 0;
}