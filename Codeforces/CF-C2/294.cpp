#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
using ld = long double;
using ll = long long;
using ii = pair <int,int>;
using pll = pair <ll,ll>;
using vi = vector <int>;
using vll = vector <ll>;
using vii = vector <ii>;
using vpll = vector<pll>;

const int mod = 1e9 + 7;
int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int n,m;
  cin >> n >> m;

  int comb[1001][1001];
  for(int i=0;i<=1000;i++){
    for(int j=0;j<=i;j++){
      if(j == 0 || j == i)
        comb[i][j] = 1;
      else{
        comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        comb[i][j] %= mod;
      }
    }
  }

  ll pot[1001];
  pot[0] = 1;

  for(int i=1;i<=n;i++){
    pot[i] = 2*pot[i-1];
    pot[i] %= mod;
  }

  vi vet(m);
  for(int i=0;i<m;i++)
    cin >> vet[i];
  
  sort(vet.begin(),vet.end());

  ll ans = 1;
  ll off = 0;
  ll sum = 0;

  for(int i=0;i<m;i++){
    if(i == 0)
      off = vet[i]-1;
    else{
      off = vet[i]-vet[i-1]-1;
      ans *= pot[max(off-1,0LL)];
      ans %= mod;
    }
    sum += off;
    ans *= comb[sum][off];
    ans %= mod;
  }

  off = n-vet[m-1];
  sum += off;
  ans *= comb[sum][off];
  ans %= mod;

  cout << ans <<endl;
  
  return 0;
}