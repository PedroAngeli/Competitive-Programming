#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

const int nax = 2e5 +5;
vector <pair <int,int> > factors[nax+5];
vector <int> expQtd[nax];
bitset <nax> is_prime;

void sieve(){
  is_prime.set();
  for(long long i=2;i<=nax;i++){
    if(is_prime[i]){
      for(long long j=i;j<=nax;j+=i){
        is_prime[j] = 0;
        pair <int,int> f = {i,0};
        long long temp = j;
        while(temp % i == 0)
          temp/=i,f.second++;
        factors[j].push_back(f);
      }
    }
  }
}

int main(){

  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
 
  sieve();
 
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    int len = factors[a].size();
    for(int j=0;j<len;j++){
      int factor = factors[a][j].first;
      int e = factors[a][j].second;
      expQtd[factor].push_back(e);
    }
  }

  long long ans = 1;

  for(int i=2;i<=nax;i++){
    int len = expQtd[i].size();
    if(len == 0)
      continue;
    sort(expQtd[i].begin(),expQtd[i].end());
    if(len == n-1)
      ans *= (long long)pow(i,expQtd[i][0]);
    else if(len == n)
      ans *= (long long)pow(i,expQtd[i][1]);
  }

  cout << ans << endl;

  

  return 0;
}