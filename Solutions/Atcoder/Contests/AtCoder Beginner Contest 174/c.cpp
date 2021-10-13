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


int main(){
 
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  
  int k;
  cin >> k;
  int cur = 7;
  for(int i=1;i<=1e6;i++){
    if(cur%k == 0){
      cout << i << endl;
      return 0;
    }
    cur *= 10;
    cur += 7;
    cur %= k;
  }

  cout << -1 << endl;

  return 0;
}