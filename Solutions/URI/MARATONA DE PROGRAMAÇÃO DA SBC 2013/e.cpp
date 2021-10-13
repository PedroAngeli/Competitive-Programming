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
  
  int n,r;
  while(cin >> n >> r){
    vector <bool> check(n+1,false);
    for(int i=0;i<r;i++){
      int x;
      cin >> x;
      check[x] = true;
    }

    if(n == r)
      cout << "*" << endl;
    else{
      for(int i=1;i<=n;i++)
        if(!check[i])
          cout << i << " ";
      cout << endl;
    }

  }

  return 0;
}