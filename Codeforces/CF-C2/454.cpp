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
  
  ld n,m;
  cin >> m >> n;
  
  ld ans = 0;
  for(int i=1;i<=m;i++){
    ans += i*(pow(i/m,n)-pow((i-1)/m,n));
  } 

  cout << fixed << setprecision(9) << ans << endl;
 
  return 0;
}