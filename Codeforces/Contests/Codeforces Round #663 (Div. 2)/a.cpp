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
  
  int t = 1;
  cin >> t;

  while(t--){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}