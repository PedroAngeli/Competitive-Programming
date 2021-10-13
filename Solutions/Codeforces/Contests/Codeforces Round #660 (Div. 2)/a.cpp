#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define f first
#define s second
 
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
    int sum = 6 + 10 + 14;
    if(n <= sum)
      cout << "NO" << endl;
    else{
      cout << "YES" << endl;
      if(n == 36)
        cout << "5 6 10 15" << endl;
      else if(n == 40)
        cout << "6 14 15 5" << endl;
      else if(n == 44)
        cout << "15 10 6 13" << endl;
      else 
        cout << "6 10 14 " << n-sum << endl; 
    }
  }
 
  return 0;
}