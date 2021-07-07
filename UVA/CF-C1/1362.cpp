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

string a;
int n;
const int mod = 1e9;
vector <vi> dp;

int solve(int i,int j){
  if(i > j || i < 0 || i >= n || j < 0 || j >= n)
    return 0;
  if(i == j)
    return 1;
  
  int& state = dp[i][j];
  if(state != -1)
    return state;
  ll sum = 0;

  for(int k=i+2;k<=j;k++){
    if(a[i] == a[k] && a[i] == a[j]){
      sum += (1LL*solve(i+1,k-1)*solve(k,j));
      sum %= mod;
    }
  }
  
  return state = sum;
} 

int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  while(cin >> a){
    n = a.size();
    dp.assign(n,vi(n,-1));
    cout << solve(0,n-1) << endl;
  }  

  return 0;
}