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
  
  ll n,m;

  while(cin >> n >> m){
    if(n == 1 && m == 1)
      break;
    ll curNum = 1;
    ll curDen = 1;
    ll lastNumLeft = 0;
    ll lastDenLeft = 1;
    ll lastNumRight = 1;
    ll lastDenRight = 0;

    while(curNum != n || curDen != m){
      ll mmc = (m*curDen)/__gcd(m,curDen);
      if((mmc/m)*n < (mmc/curDen)*curNum){ 
        lastNumRight = curNum;
        lastDenRight = curDen;
        curNum = curNum + lastNumLeft;
        curDen = curDen + lastDenLeft;
        cout << "L";
      }else{
        lastNumLeft = curNum;
        lastDenLeft = curDen;
        curNum = curNum + lastNumRight;
        curDen = curDen + lastDenRight;
        cout << "R";
      }
    }
    cout << endl;
  }

  return 0;
}