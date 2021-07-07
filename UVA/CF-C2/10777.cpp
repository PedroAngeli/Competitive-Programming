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
  
  int t;
  cin >> t;
  int ncase = 1;

  while(t--){
    ld safe = 0;
    cout << "Case " << ncase++ << ": ";
    int n;
    cin >> n;

    ld e = 0;

    while(n--){
      ld t,p;
      cin >> t >> p;
      if(t > 0)
        safe += p;
      e += fabsl(t)*p;
    }

    if(safe == 0)
      cout << "God! Save me" << endl;
    else
      cout << fixed << setprecision(2) << e/safe << endl;
  }
  
 
  return 0;
}