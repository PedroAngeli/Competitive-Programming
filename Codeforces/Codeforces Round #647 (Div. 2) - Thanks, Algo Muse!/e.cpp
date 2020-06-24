#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 1e6 + 5;
const int mod = 1e9 + 7;
long long vet[nax];
long long n;
long long sum;
map < pair<int,int>,int > dp;

long long solve(int i,long long cur,int a){
  if(i == n){
    if(a == n)
      return mod+3;
    long long sumb = sum-cur;
    return abs(sumb-cur);
  }

  if(dp.count({i,cur}))
    return dp[{i,cur}];

  return dp[{i,cur}] = min(solve(i+1,cur,a), solve(i+1,(cur+vet[i])%mod,a+1));
}

long long binpow(long long a, long long b){
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  
  while(t--){
    long long p;
    cin >> n >> p;
    sum = 0;
    dp.clear();
    for(int i=0;i<n;i++){
      cin >> vet[i];
      vet[i] = binpow(p,vet[i]);
      sum += vet[i];
      sum %= mod;
    }
    cout << solve(0,0,0)%mod << endl;

  }

  return 0;
}