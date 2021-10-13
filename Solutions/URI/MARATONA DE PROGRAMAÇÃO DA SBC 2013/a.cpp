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
  
  int a,b,c;
  while(cin >> a >> b >> c){
    if(b == c && a != b)
      cout << "A" << endl;
    else if(a == b && c != a)
      cout << "C" << endl;
    else if(a == c && b != a)
      cout << "B" << endl;
    else
      cout << "*" << endl;
  }

  return 0;
}