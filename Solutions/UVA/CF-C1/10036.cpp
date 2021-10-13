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

vi vet;
int n,k;
vector <vi> dp;

int mod(int x,int m){
  return ((x%m)+m)%m;
}

int solve(int i,int curMod){
  if(i == n){
    return mod(curMod+vet[0],k) == 0;
  }

  int& state = dp[i][curMod];

  if(state != -1)
    return state;
  
  return state = solve(i+1,mod(curMod+vet[i],k)) || solve(i+1,mod(curMod-vet[i],k));
}

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    cin >> n >> k;
    vet.resize(n);
    dp.assign(n+1,vi(k+1,-1));

    for(int i=0;i<n;i++)
      cin >> vet[i];

    if(solve(1,0))
      cout << "Divisible" << endl;
    else
      cout << "Not divisible" << endl;
  }

  return 0;
}